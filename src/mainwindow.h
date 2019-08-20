#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myserver.h"
#include "myclient.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    MyServer* m_server = nullptr;
    MyClient* m_client = nullptr;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_btnStartServer_clicked();

    void on_btnConnectToServer_clicked();

    void on_btnStopServer_clicked();

    void on_btnDisconnect_clicked();

private:
    void startServer(quint16 port);
    void connectToServer(const QString& ip, quint16 port);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
