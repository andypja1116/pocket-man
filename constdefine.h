#ifndef CONSTDEFINE_H
#define CONSTDEFINE_H

#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<QString>
#include<QPainter>

using namespace std;

enum petKind//不同宠物的属性:高攻击，高防御，高生命值，低攻击间隔
{
    ATTACK, DEFINE, HP, LOW_INTERVAL
};

/*enum petGrade
{
    GRAY, GREEN, BLUE, MAGENTA, GOLDEN
};*/

const int levelInitial = 1;//初始等级
const int xpMaxInitial = 100;//经验值升级上限
const int levelUpperBound = 15;//最高级别

const int attackRate_level = 25;//每一级别的攻击力
const int defineRate_level = 22;//每一级别的防御力
const int hpRate_level = 100;//每一级别的生命值
const int intervalRate_level = 4;//每一级别的攻击间隔
const int performRate = 15;

const int petSumNumber = 4;
const int petOfEveryKind = 1;
const QString petName[petSumNumber] =
{
    "smallFireDragon", "squirtle", "bulbasaur", "pikachu"
};//小火龙，杰尼龟，妙蛙种子，皮卡丘

const QString userNameIsIn = "UserNameIsAlreadyIn";
const QString registeSuccessful = "RegisteSuccessful";
const QString loginFailed = "LoginInFailed";
const QString loginSuccessful = "LoginInSuccessful";

#endif // CONSTDEFINE_H
