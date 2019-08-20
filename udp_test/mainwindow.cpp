#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_server = new MyUdpServer(this);
    m_client = new MyUdpClient(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startServer_clicked()
{
    bool ok = false;
    auto port = ui->port->text().toUShort(&ok);
    if (ok)
    {
        m_server->startServer(port);
    }
}

void MainWindow::on_stopServer_clicked()
{
    m_server->stopServer();
}

void MainWindow::on_connectToServer_clicked()
{
    auto ip = ui->ip->text();
    bool ok = false;
    auto port = ui->port->text().toUShort(&ok);
    if (ok && !ip.isEmpty())
    {
        m_client->connectToHost(ip, port);
    }
}

void MainWindow::on_disconnectFromServer_clicked()
{
    m_client->disconnectFromHost();
}
