#include "myserver.h"
#include "myserverthread.h"

MyServer::MyServer(QObject* parent)
    : QTcpServer (parent)
{}


void MyServer::incomingConnection(qintptr socketDescripter)
{
    auto thread = new MyServerThread(socketDescripter, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}
