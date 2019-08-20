#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>

class MyServer : public QTcpServer
{
    Q_OBJECT

public:
    MyServer(QObject *parent = nullptr);

protected:
    void incomingConnection(qintptr socketDescripter) override;
};

#endif // MYSERVER_H
