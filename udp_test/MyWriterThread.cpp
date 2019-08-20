#include "MyWriterThread.h"
#include <QUdpSocket>

MyWriterThread::MyWriterThread(QObject* parent)
    : QThread (parent)
{
}

void MyWriterThread::start(const QString& ip, quint16 port)
{
    m_ip = ip;
    m_port = port;
    m_quit = false;

    QThread::start();
}

void MyWriterThread::quit()
{
    m_quit = true;
    wait();
}

void MyWriterThread::run()
{
    auto socket = new QUdpSocket();
    socket->connectToHost(m_ip, m_port);

    int size = 40000;
    QByteArray buffer(size, char(0xCC));
    while (!m_quit)
    {
        socket->write(buffer);
        socket->flush();
    }

    socket->deleteLater();
}

