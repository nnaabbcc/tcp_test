#include "MyUdpClient.h"

MyUdpClient::MyUdpClient(QObject *parent) : QObject(parent)
{
    m_thread = new MyWriterThread(this);
}

void MyUdpClient::connectToHost(const QString &ip, quint16 port)
{
    m_thread->start(ip, port);
}

void MyUdpClient::disconnectFromHost()
{
    m_thread->quit();
}
