#include "client.h"
#include <iostream>
#include <QString>
#include <string>

client::client(QObject *parent) : QObject(parent)
{

}

void client::Connect(g9_control* g9)
{
    this->socket = new QTcpSocket();

    std::cout << "ATTEMPTING TO CONNECT!!!!" << std::endl;

    socket->connectToHost("127.0.0.1", 1111);

    if(socket->waitForConnected(3000))
    {
        //qDebug() << "Connected\n";
        std::cout << "Connected" << std::endl;

        socket->waitForBytesWritten(1000);
        std::cout << "WAITING FOR BYTES WRITTEN" << std::endl;

        socket->waitForReadyRead(3000);
        std::cout << "WAITING FOR BYTES TO READ" << std::endl;

        //qDebug() << "Reading: \n" << socket->bytesAvailable();
        std::cout << "Reading: \n" << socket->bytesAvailable() << std::endl;

        //qDebug() << socket->readAll();
        std::cout << socket->readAll().toStdString() << std::endl;

        char char_arr[6];
        char_arr[4] = '\0';
        char_arr[3] = '\r';
        char_arr[0] = 'a';
        char_arr[1] = (char)g9->lo_level;
        char_arr[2] = (char)g9->mid_level;
        char_arr[3] = (char)g9->hi_level;

        do{

            char_arr[0] = (char)g9->lo_level;
            char_arr[1] = (char)g9->mid_level;
            char_arr[2] = (char)g9->hi_level;

            /*
            std::getline(std::cin, user_name);
            qDebug() << "YOUR INPUT IS: ";
            std::cout << user_name << "\n\n";
            */

            /*
            char usr_arr[1024];
            strncpy(usr_arr, user_name.c_str(), sizeof(usr_arr));
            usr_arr[sizeof(usr_arr) - 1] = 0;
            */

            socket->write(char_arr);
            socket->waitForBytesWritten(2000);
            socket->flush();

        }while(char_arr[0] != 'z');

        socket->close();

    }
    else
    {qDebug() << "Not Connected\n";}
}

