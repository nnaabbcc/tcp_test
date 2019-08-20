#ifndef MYREADERTHREADOBJECT_H
#define MYREADERTHREADOBJECT_H

#include <QUdpSocket>

class MyReaderThreadObject : public QObject
{
    Q_OBJECT

    QUdpSocket* m_socket = nullptr;

public:
    explicit MyReaderThreadObject(QObject *parent = nullptr);

private slots:
    void slotStartServer(quint16 port);
    void slotStopServer();
    void slotReadPendingDatagrams();
};

#endif // MYREADERTHREADOBJECT_H
