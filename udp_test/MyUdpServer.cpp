#include "MyUdpServer.h"

MyUdpServer::MyUdpServer(QObject *parent) : QObject(parent)
{
    m_thread = new MyReaderThread(this);
}

void MyUdpServer::startServer(quint16 port)
{
    m_thread->startServer(port);
}

void MyUdpServer::stopServer()
{
    m_thread->stopServer();
}
