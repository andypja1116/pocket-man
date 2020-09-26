#include "player.h"

//构造函数
player::player(QByteArray &b)
{
    int pos = 0;
    get(b,pos);
    name = get(b,pos);
    password = get(b,pos);
    winNum = get(b,pos).toInt();
    failNum = get(b,pos).toInt();
    petNum = get(b,pos).toInt();
    highPetNum = get(b,pos).toInt();
    qDebug()<<"OK";
    while(pos < b.size()){
        int n = pos;
        QString temp;
        temp.clear();
        temp += get(b,n);
        pet *p;
        if(temp == petName[0]){
            p = new smallFireDragon(b,pos);
        }
        else if(temp == petName[1]){
            p = new squirtle(b,pos);
        }
        else if(temp == petName[2]){
            p = new bulbasaur(b,pos);
        }
        else if(temp == petName[3]){
            p = new pikachu(b,pos);
        }
        qDebug()<<"fine";
        petOfPlayer.push_back(p);
    }

}


player::~player()
{
    for(unsigned int i = 0 ; i < petOfPlayer.size() ; i++){
        delete petOfPlayer[i];
    }
}


//用户获得新的小精灵的方法
void player::addPet(pet *p)
{
    petOfPlayer.push_back(p);
}


//从字符串中提取出用户信息的方法
void player::getPlayerInfo(QByteArray &b, int &pos)
{
    name = get(b,pos);
    password = get(b,pos);
    winNum = get(b,pos).toInt();
    failNum = get(b,pos).toInt();
    petNum = get(b,pos).toInt();
    highPetNum = get(b,pos).toInt();

    QString temp;
    pet *p;
    while(temp != "#"){
        temp.clear();
        temp += get(b,pos);
        int n = pos;
        get(b,n);    //get name
        //kind
        switch(get(b,n).toInt()){
        case 0:
            p = new smallFireDragon(ATTACK,"smallFireDragon",levelInitial);
            break;
        case 1:
            p = new squirtle(DEFINE,"bigStone",levelInitial);
            break;
        case 2:
            p = new bulbasaur(HP,"oldTree",levelInitial);
            break;
        case 3:
            p = new pikachu(LOW_INTERVAL,"pikachu",levelInitial);
            break;
        default:
            break;
        }
        p->getPetInfo(b,pos);
        petOfPlayer.push_back(p);
    }
}


//从字符串中提取其他在线用户信息方法
void player::getOtherPlayer(QByteArray &b , int &pos)
{
    name = get(b,pos);

    winNum = get(b,pos).toInt();
    failNum = get(b,pos).toInt();
    petNum = get(b,pos).toInt();
    highPetNum = get(b,pos).toInt();

    QString temp;
    pet *p;
    while(temp != "#"){
        temp.clear();
        temp += get(b,pos);
        int n = pos;
        get(b,n);    //get name
        //kind
        switch(get(b,n).toInt()){
        case 0:
            p = new smallFireDragon(ATTACK,"smallFireDragon",levelInitial);
            break;
        case 1:
            p = new squirtle(DEFINE,"squirtle",levelInitial);
            break;
        case 2:
            p = new bulbasaur(HP,"bulbasaur",levelInitial);
            break;
        case 3:
            p = new pikachu(LOW_INTERVAL,"pikachu",levelInitial);
            break;
        default:
            break;
        }
        p->getPetInfo(b,pos);
        petOfPlayer.push_back(p);
    }
}


//将用户信息变成字符串传送的方法
QString player::toQString()
{
    QString temp;
    temp.clear();
    temp += ' ';
    temp += name;
    temp += ' ';
    temp += QString::number(winNum,10);
    temp += ' ';
    temp += QString::number(failNum,10);
    temp += ' ';
    temp += QString::number(petNum,10);
    temp += ' ';
    temp += QString::number(highPetNum,10);
    temp += ' ';
    for(unsigned int i = 0 ; i < petOfPlayer.size() ; ++i){
        temp += petOfPlayer[i]->toQString();
        //qDebug() << temp;
        temp += ' ';
    }
    temp += "#";
    return temp;
}
