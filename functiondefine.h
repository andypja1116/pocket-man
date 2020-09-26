#ifndef FUNCTIONDEFINE_H
#define FUNCTIONDEFINE_H

#include"constdefine.h"

int random(int left, int right);//随机选择，用于决斗赛失败时随机挑选出要被丢弃的宠物
QString get(const QByteArray &b , int &pos);
bool hasIllegal(QString s);//判断用户名和密码中是否含有非法的字符
void countTime();

#endif // FUNCTIONDEFINE_H
