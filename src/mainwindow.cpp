#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_server = new MyServer(this);
    m_client = new MyClient(this);
}

MainWindow::~MainWindow()
{
    delete m_client;
    delete m_server;
    delete ui;
}

void MainWindow::on_btnStartServer_clicked()
{
    bool ok = false;
    auto port = ui->serverPort->text().toUShort(&ok);
    startServer(port);
}

void MainWindow::on_btnConnectToServer_clicked()
{
    bool ok = false;
    auto ip = ui->serverIP->text();
    auto port = ui->serverPort->text().toUShort(&ok);
    connectToServer(ip, port);
}

void MainWindow::on_btnStopServer_clicked()
{
    if (m_server->isListening())
    {
        m_server->close();
        ui->btnStartServer->setEnabled(true);
    }
}

void MainWindow::on_btnDisconnect_clicked()
{
    m_client->disconnect();
}

void MainWindow::startServer(quint16 port)
{
    if (m_server->listen(QHostAddress::AnyIPv4, port))
    {
        ui->btnStartServer->setEnabled(false);
    }
}

void MainWindow::connectToServer(const QString &ip, quint16 port)
{
    m_client->connectToHost(ip, port);
}
