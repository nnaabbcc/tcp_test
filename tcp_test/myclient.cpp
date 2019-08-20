#include "myclient.h"
#include <QDebug>

MyClient::MyClient(QObject *parent) : QObject(parent)
{
    m_tcpSocket = new QTcpSocket(this);

    connect(m_tcpSocket, &QIODevice::readyRead,
            this, &MyClient::slotReadyRead);
    connect(m_tcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
            this, &MyClient::slotError);
}

void MyClient::connectToHost(const QString &hostName, quint16 port)
{
    m_tcpSocket->abort();
    m_tcpSocket->connectToHost(hostName, port);
}

void MyClient::disconnect()
{
    m_tcpSocket->disconnectFromHost();
}

void MyClient::slotReadyRead()
{
    auto bytes = m_tcpSocket->bytesAvailable();
    m_tcpSocket->read(bytes);
}

void MyClient::slotError(QAbstractSocket::SocketError socketError)
{
    qDebug() << socketError;
}
