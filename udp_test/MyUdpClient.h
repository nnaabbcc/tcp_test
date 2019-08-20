#ifndef MYUDPCLIENT_H
#define MYUDPCLIENT_H

#include "MyWriterThread.h"

class MyUdpClient : public QObject
{
    Q_OBJECT

    MyWriterThread* m_thread = nullptr;
public:
    explicit MyUdpClient(QObject *parent = nullptr);

    void connectToHost(const QString& ip, quint16 port);
    void disconnectFromHost();

};

#endif // MYUDPCLIENT_H
