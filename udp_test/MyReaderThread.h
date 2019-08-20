#ifndef MYREADERTHREAD_H
#define MYREADERTHREAD_H

#include <QThread>

class MyReaderThread : public QThread
{
    Q_OBJECT

public:
    MyReaderThread(QObject* parent = nullptr);

    void startServer(quint16 port);
    void stopServer();

signals:
    void sigStartServer(quint16 port);
    void sigStopServer();

protected:
    void run() override;
};

#endif // MYREADERTHREAD_H
