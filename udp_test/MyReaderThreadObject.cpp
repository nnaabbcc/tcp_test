#include "MyReaderThreadObject.h"
#include <QNetworkDatagram>

MyReaderThreadObject::MyReaderThreadObject(QObject *parent) : QObject(parent)
{
}

void MyReaderThreadObject::slotStartServer(quint16 port)
{
    slotStopServer();

    m_socket = new QUdpSocket(this);
    m_socket->bind(QHostAddress::AnyIPv4, port);

    connect(m_socket, SIGNAL(readyRead()),
            this, SLOT(slotReadPendingDatagrams()));
}

void MyReaderThreadObject::slotStopServer()
{
    if (m_socket != nullptr)
    {
        m_socket->close();
        m_socket->deleteLater();
        m_socket = nullptr;
    }
}

void MyReaderThreadObject::slotReadPendingDatagrams()
{
    while (m_socket->hasPendingDatagrams())
    {
        m_socket->receiveDatagram();
    }
}
