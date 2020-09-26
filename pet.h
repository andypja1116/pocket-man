#ifndef PET_H
#define PET_H

#include"basepet.h"

class smallFireDragon: public pet
{
    public:
        smallFireDragon(petKind , QString , int);
        smallFireDragon(QByteArray &b , int &pos);
        virtual void performAbilities(QTextBrowser *p , pet &attacked);//特殊攻击，使用虚方法，对父类进行重载
};


class pikachu: public pet
{
    public:
        pikachu(petKind , QString , int);
        pikachu(QByteArray &b , int &pos);
        virtual void performAbilities(QTextBrowser *p, pet &attacked);
};

class squirtle: public pet
{
    public:
        squirtle(petKind , QString , int);
        squirtle(QByteArray &b , int &pos);
        virtual void performAbilities(QTextBrowser *p , pet &attacked);
};

class bulbasaur: public pet
{
    public:
        bulbasaur(petKind , QString , int);
        bulbasaur(QByteArray &b , int &pos);
        virtual void performAbilities(QTextBrowser *p , pet &attacked);
};

#endif // PET_H







