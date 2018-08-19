#include "g9_control.h"
#include <QApplication>
#include "client.h"
#include <thread>

void start_client(g9_control* g9)
{
    client* c = new client();
    c->Connect(g9);
    delete c;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    g9_control w;
    w.show();

    std::thread client_thread(&client::Connect, new client(), &w);

    return a.exec();
}

