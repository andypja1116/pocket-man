#ifndef PLAYER_H
#define PLAYER_H

#include "pet.h"
#include <QDebug>

class player{
private:
    QString name;//玩家用户名
    QString password;//玩家密码
    int winNum;//玩家获胜的次数
    int failNum;//玩家失败的次数
    int petNum;//玩家拥有的宠物的数量
    int highPetNum;//玩家拥有的高级宠物的数量
    vector<pet *> petOfPlayer;//玩家拥有的宠物的向量集合

public:
    player(QByteArray &b);
    ~player();

    void addPet(pet *);//玩家获胜时为玩家添加宠物
    void getPlayerInfo(QByteArray &b , int &pos);//获取玩家信息
    void getOtherPlayer(QByteArray &b , int &pos);
    QString toQString();//将其他类型的数据转换成Qstring类型的数据

    void win() { winNum++; } ;
    void fail() { failNum++; } ;
    void changePetNum(int num) { petNum = num; } ;//修改玩家拥有的宠物的数量
    QString getName() const { return name; } ;//获取玩家的用户名
    QString getPassword() const { return password; } ;//获取玩家的密码
    int getWinNum() const { return winNum; } ;//获取玩家的获胜次数
    int getFailNum() const { return failNum; } ;//获取玩家的失败次数
    int getPetNum() const { return petNum; } ;//获取玩家的宠物数目
    int getHighPetNUm() const { return highPetNum; } ;//获取玩家的高端宠物数目


};

#endif // PLAYER_H
