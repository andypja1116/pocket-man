#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <windows.h>
#include "database.h"
#include "player.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void newConnect();//与客户端程序建立连接
    void receive_data();//读取从客户端发来的程序信息
    void socketDisconnected();//与客户端程序断开连接

    Database playerDatabase;
    vector<player*> inLinePlayer;//所有玩家的队列

private:
    Ui::MainWindow *ui;

    QTcpServer *server;
    QTcpSocket *socket;

    int port;
};

QString get(const QByteArray &b , int &pos);
bool nameIsInDatabase(QByteArray &b , Database &playerDatabase);
bool infoIsInDatabase(QByteArray &b , Database &playerDatabase);

#endif // MAINWINDOW_H
