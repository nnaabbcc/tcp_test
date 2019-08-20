#ifndef MYUDPSERVER_H
#define MYUDPSERVER_H

#include "MyReaderThread.h"

class MyUdpServer : public QObject
{
    Q_OBJECT

    MyReaderThread* m_thread;

public:
    explicit MyUdpServer(QObject *parent = nullptr);

    void startServer(quint16 port);
    void stopServer();

};

#endif // MYUDPSERVER_H
