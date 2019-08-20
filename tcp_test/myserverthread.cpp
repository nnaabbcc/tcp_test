#include "myserverthread.h"
#include <QTcpSocket>
#include <QDebug>

MyServerThread::MyServerThread(qintptr socketDescriptor, QObject *parent)
    : QThread (parent)
    , m_socketDescriptor(socketDescriptor)
{
}

void MyServerThread::run()
{
    QTcpSocket tcpSocket;

    if (!tcpSocket.setSocketDescriptor(m_socketDescriptor))
    {
        return;
    }

    char c = 0x00;
    while (true)
    {
        const int size = 400000;
        static QByteArray block(size, c);
        c++;
        c = c % 0x7F;
        tcpSocket.write(block);
        if (!tcpSocket.waitForBytesWritten(300))
        {
            if (tcpSocket.state() == QAbstractSocket::UnconnectedState)
            {
                break;
            }
        }
    }

    tcpSocket.disconnectFromHost();
    tcpSocket.waitForDisconnected();
}
