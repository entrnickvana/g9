#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include "g9_control.h"

class client : public QObject
{
    Q_OBJECT
public:
    explicit client(QObject *parent = nullptr);
    void Connect(g9_control* g9);
signals:

public slots:

private:
    QTcpSocket* socket;

};

#endif // CLIENT_H
