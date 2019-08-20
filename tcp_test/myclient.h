#ifndef MYCLIENT_H
#define MYCLIENT_H


#include <QTcpSocket>

class MyClient : public QObject
{
    Q_OBJECT

    QTcpSocket *m_tcpSocket = nullptr;

public:
    explicit MyClient(QObject *parent = nullptr);

    void connectToHost(const QString &hostName, quint16 port);
    void disconnect();

signals:

public slots:
    void slotReadyRead();
    void slotError(QAbstractSocket::SocketError socketError);
};

#endif // MYCLIENT_H
