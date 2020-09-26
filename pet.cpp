#include "mainwindow.h"

//produce a wild pet randomly
pet::pet(petKind _kind, QString , int _lv)
{
    kind = _kind;

    level = _lv;
    xp = 0;
    xpMax = xpMaxInitial;
    for(int i=1;i<_lv;i++)
    {
        xpMax+=100;
    }
    int r=random(1,10);
    rand=r;
    attack = level * attackRate_level+rand ;
    define = level * defineRate_level+rand ;
    hp = level * hpRate_level+rand ;
    attackInterval = 100 - level * intervalRate_level-rand;
    missRate = 10 + int(level/5)+1;

    //strengthen it's advantage according to kind
    switch(kind)
    {
    case ATTACK:
        attack =attack*2;
        break;
    case DEFINE:
        define =define*2;
        break;
    case HP:
        hp =hp*2;
        break;
    default:
        attackInterval = attackInterval - level * intervalRate_level;
        break;
    }  //end of switch(kind)
}

pet::pet(QByteArray &b, int &pos)
{
    get(b,pos);
    kind = petKind(get(b,pos).toInt());
    level = get(b,pos).toInt();
    rand =get(b,pos).toInt();
    xp = get(b,pos).toInt();


    xpMax = xpMaxInitial;
    for(int i=1;i<level;i++)
    {
        xpMax+=100;
    }
    attack = level * attackRate_level+rand ;
    define = level * defineRate_level+rand ;
    hp = level * hpRate_level +rand;
    attackInterval = 100 - level * intervalRate_level-rand;
    missRate = 10 + int(level/5)+1;

    //strengthen it's advantage according to kind
    switch(kind)
    {
    case ATTACK:
        attack =attack*2;
        break;
    case DEFINE:
        define =define*2;
        break;
    case HP:
        hp =hp*2;
        break;
    default:
        attackInterval = attackInterval - level * intervalRate_level;
        break;
    }  //end of switch(kind)
}

pet::~pet()
{

}




void pet::levelUp()
{
    if(xp >= xpMax)
    {
        if(level < levelUpperBound)
        {
            level++;
            xp = xp - xpMax;
            xpMax += 100;
            attack = level * attackRate_level+rand ;
            define = level * defineRate_level+rand ;
            hp = level * hpRate_level+rand ;
            attackInterval = 100 - level * intervalRate_level-rand;
            missRate = 10 + int(level/5)+1;

            //strengthen it's advantage according to kind
            switch(kind)
            {
            case ATTACK:
                attack =attack*2;
                break;
            case DEFINE:
                define =define*2;
                break;
            case HP:
                hp =hp*2;
                break;
            default:
                attackInterval = attackInterval - level * intervalRate_level;
                break;
            }  //end of switch(kind)

        }
    }
}

//when a wild pet is caught, use this to make it's lv = 1
void pet::levelInitialize()
{
    level = levelInitial;
    xp = 0;
    xpMax = xpMaxInitial;

    creat_rand();
    attack = level * attackRate_level+rand ;
    define = level * defineRate_level+rand ;
    hp = level * hpRate_level+rand ;
    attackInterval = 100 - level * intervalRate_level-rand;
    missRate = 10 + int(level/5)+1;

    //strengthen it's advantage according to kind
    switch(kind)
    {
    case ATTACK:
        attack =attack*2;
        break;
    case DEFINE:
        define =define*2;
        break;
    case HP:
        hp =hp*2;
        break;
    default:
        attackInterval = attackInterval - level * intervalRate_level;
        break;
    }  //end of switch(kind)

}



void pet::fightStart()
{
    attackIntervalNow = attackInterval;
    attackNow = attack;
    missRateNow = missRate;
    defineNow = define;
    hpNow = hp;
    attackTime = 0;
}

void pet::fightEnd(int experience)
{
    xp += experience;
}


void pet::beAttacked(QTextBrowser *p , const pet &attacker)
{
    int miss = random(1, 80);
    if(miss > missRateNow)
    {
        int damage = attacker.attackNow - defineNow;
        if(damage>0)
        {

        }
        else
            damage=0;
        if(hpNow > damage)
        {
            hpNow = hpNow - damage;
            p->append(name + " is attacked by " + attacker.name + " , hp - " + QString::number(damage,10));

        }
        else
        {
            hpNow = 0;
            p->append(name + " is attacked by " + attacker.name + " , hp - " + QString::number(damage,10));
            p->append(name + " is dead !");

        }
    }
    else
    {
        p->append(name + "is attacked by " + attacker.name + " , Miss !");
    }
}

QString pet::toQString()
{
    QString temp;
    temp += name;
    temp += ' ';
    temp += QString::number(kind,10);
    temp += ' ';
    temp += QString::number(level,10);
    temp += ' ';
    temp += QString::number(rand,10);
    temp += ' ';
    temp += QString::number(xp,10);
    return temp;
}



void pet::getPetInfo(QByteArray &b, int &pos)
{
    name = get(b,pos);
    kind = petKind(get(b,pos).toInt());
    level = get(b,pos).toInt();
    rand =get(b,pos).toInt();
    xp = get(b,pos).toInt();

    xpMax = xpMaxInitial;
    for(int i=1;i<level;i++)
    {
        xpMax+=100;
    }

    attack = level * attackRate_level+rand ;
    define = level * defineRate_level+rand ;
    hp = level * hpRate_level +rand;
    attackInterval = 100 - level * intervalRate_level-rand;
    missRate = 10 + int(level/5)+1;

    //strengthen it's advantage according to kind
    switch(kind)
    {
    case ATTACK:
        attack =attack*2;
        break;
    case DEFINE:
        define =define*2;
        break;
    case HP:
        hp =hp*2;
        break;
    default:
        attackInterval = attackInterval - level * intervalRate_level;
        break;
    }  //end of switch(kind)

}



smallFireDragon::smallFireDragon(petKind _kind, QString _name, int _lv):pet(_kind, _name, _lv) {
    name = petName[0];
}
smallFireDragon::smallFireDragon(QByteArray &b , int &pos):pet(b,pos) {
    name = petName[0];
}
void smallFireDragon::performAbilities(QTextBrowser *p, pet &attacked)
{
    changeAttackNow(getAttackNow() + attackRate_level);
    p->append("smallFireDragon uses [attack improve] , attack + " + QString::number(attackRate_level,10));
}

squirtle::squirtle(petKind _kind , QString _name , int _lv):pet(_kind , _name , _lv) {
    name = petName[1];
}
squirtle::squirtle(QByteArray &b , int &pos):pet(b,pos) {
    name = petName[1];
}
void squirtle::performAbilities(QTextBrowser *p, pet &attacked)
{
    changeDefineNow(getDefineNow() + defineRate_level);
    p->append("squirtle uses define improve , define + " + QString::number(defineRate_level,10));
}

bulbasaur::bulbasaur(petKind _kind , QString _name , int _lv):pet(_kind , _name , _lv) {
    name = petName[2];
}
bulbasaur::bulbasaur(QByteArray &b , int &pos):pet(b,pos) {
    name = petName[2];
}
void bulbasaur::performAbilities(QTextBrowser *p, pet &attacked)
{
    if(getHp()-getHpNow()>=20)
    {
        changeHpNow(getHpNow()+20);
        p->append("bulbasaur uses hp recover , hp + 20 !");
    }
    else
    {
        changeHpNow(getHp());
        p->append("bulbasaur uses hp recover , hp is fulled!");
    }
}

pikachu::pikachu(petKind _kind , QString _name , int _lv):pet(_kind , _name , _lv) {
    name = petName[3];
}
pikachu::pikachu(QByteArray &b , int &pos):pet(b,pos) {
    name = petName[3];
}
void pikachu::performAbilities(QTextBrowser *p , pet &attacked)
{
    p->append("pikachu uses [lighten] , causes " + QString::number(getAttack() * 2,10) + " damage");
    if(attacked.getHpNow() > getAttack() * 2)
    {
        attacked.changeHpNow(attacked.getHpNow() - getAttack() * 2);
    }
    else
    {
        attacked.changeHpNow(0);
        p->append(attacked.getName() + " is dead !");
    }

}
