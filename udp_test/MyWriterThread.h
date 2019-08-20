#ifndef MYWRITERTHREAD_H
#define MYWRITERTHREAD_H

#include <QThread>

class MyWriterThread : public QThread
{
    Q_OBJECT

    bool m_quit = false;

    QString m_ip;
    quint16 m_port;

public:
    MyWriterThread(QObject* parent = nullptr);

    void start(const QString& ip, quint16 port);

    void quit();

protected:
    void run() override;

};

#endif // MYWRITERTHREAD_H
