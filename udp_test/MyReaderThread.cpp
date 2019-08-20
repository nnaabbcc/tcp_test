#include "MyReaderThread.h"
#include "MyReaderThreadObject.h"

MyReaderThread::MyReaderThread(QObject* parent)
    : QThread (parent)
{
}

void MyReaderThread::startServer(quint16 port)
{
    emit sigStartServer(port);
}

void MyReaderThread::stopServer()
{
    emit sigStopServer();

}

void MyReaderThread::run()
{
    auto object = new MyReaderThreadObject;
    connect(this, SIGNAL(sigStartServer(quint16)),
            object, SLOT(slotStartServer(quint16)));
    connect(this, SIGNAL(sigStopServer()),
            object, SLOT(slotStopServer()));

    exec();

    object->deleteLater();
}
