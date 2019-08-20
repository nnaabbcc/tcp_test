#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MyUdpServer.h"
#include "MyUdpClient.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    MyUdpServer* m_server = nullptr;
    MyUdpClient* m_client = nullptr;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startServer_clicked();

    void on_stopServer_clicked();

    void on_connectToServer_clicked();

    void on_disconnectFromServer_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
