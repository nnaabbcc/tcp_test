#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyServerThread : public QThread
{
    Q_OBJECT

    qintptr m_socketDescriptor;

public:
    MyServerThread(qintptr socketDescriptor, QObject *parent = nullptr);

protected:
    void run() override;

};

#endif // MYTHREAD_H
