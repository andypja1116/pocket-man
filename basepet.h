#ifndef BASEPET_H
#define BASEPET_H

#include <QTextBrowser>
#include"functiondefine.h"

class pet
{
    private:
        petKind kind;//宠物的属性
        //petGrade grade;
        int level;//宠物的等级
        int xp;//宠物的经验值
        int xpMax;//当前级别下宠物的经验值上限
        int hp;//宠物的生命值
        int attack;//宠物的攻击力
        int define;//宠物的防御力
        int attackInterval;//宠物的攻击间隔
        int missRate;//宠物攻击的失误率
        int rand;

        int hpNow;//在战斗过程中宠物的生命值
        int attackNow;//在战斗过程中宠物的攻击力
        int defineNow;//在战斗过程中宠物的防御力
        int attackIntervalNow;//在战斗过程中宠物的攻击间隔
        int missRateNow;//当前战斗中宠物的失误率
        int attackTime;


    public:
        pet(petKind _kind, QString _name, int _lv);
        pet(QByteArray &b , int &pos);
        virtual ~pet();


        //petGrade getGrade() const { return grade; };
        petKind getKind() const { return kind; };//获得宠物的属性
        void creat_rand()
        {
            rand=random(1,10);
        }
        int getLevel() const { return level; };//获得宠物的等级
        QString getName() const { return name; };//获得宠物的名称
        int getHp() const { return hp; };//获得宠物的生命值
        int getXp() const { return xp; };//获得宠物的经验值
        int getXpMax() const { return xpMax; };//获得宠物当前等级下经验值的上限
        int getDefine() const { return define; };//获得宠物的防御力
        int getAttack() const { return attack; };//获得宠物的攻击力
        int getAttackInterval() const { return attackInterval; };//获得宠物的攻击间隔

        int getHpNow() const { return hpNow; };//获得宠物当前生命值
        int getAttackNow() const { return attackNow; };//获得宠物当前攻击力
        int getDefineNow() const { return defineNow; };//获得宠物当前防御力
        int getAttackIntervalNow() const { return attackIntervalNow; };//获得宠物当前攻击间隔
        int getMissRateNow() const { return missRateNow; };//获得宠物在战斗中的失误率
        int getAttackTime() const { return attackTime; };

        void changeDefineNow(int _def) { defineNow = _def; };//更改宠物当前的防御力
        void changeAttackNow(int _atk) { attackNow = _atk; };//更改宠物当前的攻击力
        void changeAttackIntervalNow(int _atkInterval) { attackIntervalNow = _atkInterval; };
        //更改宠物当前的攻击间隔
        void changeHpNow(int _hp) { hpNow = _hp; };//更改宠物当前的生命值

        void levelUp();//宠物升级
        void levelInitialize();//宠物级别初始化
        void beAttacked(QTextBrowser *p , const pet &attacker);
        void fightStart();
        void fightEnd(int experience);
        QString toQString();
        void getPetInfo(QByteArray &b , int &pos);
        virtual void performAbilities(QTextBrowser *p, pet &attacked) = 0;

    protected:
        QString name;
};

#endif // BASEPET_H
