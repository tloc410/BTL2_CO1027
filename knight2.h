#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

// #define DEBUG
enum ItemType { ANTIDOTE = 0, PHOENIXDOWNI, PHOENIXDOWNII, PHOENIXDOWNIII, PHOENIXDOWNIV };
class BaseKnight;
class BaseItem {
public:
    // BaseItem() {}// chưa thêm
    ItemType data;
    BaseItem *next;
    virtual bool canUse(BaseKnight* knight) = 0;
    virtual void use(BaseKnight* knight) = 0;
};
class BaseBag {
protected:
    BaseItem *Head = NULL;
    int count = 0;
    int maxitem;
public:
    BaseBag(){};
    BaseItem *getHead(){
        return this->Head;
    }
    int getCount(){
        return this->count;
    }
    void setHead(BaseItem *head){
        this->Head = head;
    }
    void setCount(int n){
        this->count = n;
    }
    virtual bool insertFirst(BaseItem* item);
    virtual BaseItem* get(ItemType itemType);
    virtual string toString() const;
};

class BaseOpponent{
public:
    int gil;
    int baseDamge;
    int level0;
};

enum KnightType { PALADIN = 0, LANCELOT, DRAGON, NORMAL };

static int maplength = 0;

class Events {
private:
    int *map;
public:
    Events(const string& file_events);
    int count() const;
    int get(int i) const;
};
static bool omega = 0;
static bool hades = 0;
class BaseKnight {
protected:
    int id;
    int maxhp;
    int hp;
    int level;
    int gil;
    int antidote = 0;
    int phoenixdownI = 0;
    int phoenixdownII = 0;
    int phoenixdownIII = 0;
    int phoenixdownIV = 0;
    bool poisoning = 0;
    BaseBag* bag;
    KnightType knightType;
public:
    BaseKnight();
    static BaseKnight * create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    string toString() const;
    KnightType gettype(){
        return this->knightType;
    }
    BaseBag* getBag() {
        return bag;
    }
    bool getpoisoning(){
        return poisoning;
    }
    void setpoisoning(int n){
        this->poisoning = n;
    }
    int getlv(){
        return this->level;
    }
    void setgil(int n){
        this->gil = n;
    }
    int getHp(){
        return this->hp;
    }
    void setHp(int n){
        this->hp = n;
    }
    int getHpmax(){
        return this->maxhp;
    }
    int getphoenixdownI(){
        return this->phoenixdownI;
    }
    int getphoenixdownII(){
        return this->phoenixdownII;
    }
    int getphoenixdownIII(){
        return this->phoenixdownIII;
    }
    int getphoenixdownIV(){
        return this->phoenixdownIV;
    }
    int getantidote(){
        return this->antidote;
    }
    void setphoenixdownI(int n){
        this->phoenixdownI = n;
    }
    void setphoenixdownII(int n){
        this->phoenixdownII = n;
    }
    void setphoenixdownIII(int n){
        this->phoenixdownIII = n;
    }
    void setphoenixdownIV(int n){
        this->phoenixdownIV = n;
    }
    void setantidote(int n){
        this->antidote = n;
    }
    int getgil(){
        return this->gil;
    }
    void setPoisoning(int n) {
        this->poisoning = n;
    }
    void setBag(BaseBag *item){
        this->bag = item;
    }
    int getlev(){
        return this->level;
    }
    void setlev(int n){
        this->level = n;
    }
};

static int numberKnight = 0;

class ArmyKnights {
private:
    bool PaladinShield = 0;
    bool LancelotSpear = 0;
    bool GuinevereHair = 0;
    bool ExcaliburSword = 0;
    BaseKnight** arrKnigths;
public:
    void setPaladinShield(int i) {
        this->PaladinShield = i;
    }
    void setLancelotSpear(int i) {
        this->LancelotSpear = i;
    }
    void setGuinevereHair(int i) {
        this->GuinevereHair = i;
    }
    void setExcaliburSword(int i) {
        this->ExcaliburSword = i;
    }

    ArmyKnights (const string & file_armyknights);
    ~ArmyKnights();
    bool fight(BaseOpponent * opponent);
    bool adventure (Events * events);
    int count() const;
    BaseKnight * lastKnight() const;

    bool hasPaladinShield() const ;
    bool hasLancelotSpear() const ;
    bool hasGuinevereHair() const ;
    bool hasExcaliburSword() const ;

    void printInfo() const;
    void printResult(bool win) const;

};

class PaladinBag : public BaseBag 
{
    public:
    BaseKnight* k;
    int a;
    int b;
    int count = 0;
    PaladinBag(BaseKnight* k, int a, int b) :BaseBag() {
        this->k = k;
        this->a = a;
        this->b = b;
    }
    bool insertFirst(BaseItem* item);
    void create();
    BaseItem* get(ItemType itemType);
    string toString() const;
};

class DaragonBag : public BaseBag {
public:
    int Maxitem = 14;
    BaseKnight* k;
    int a;
    int b;
    int count = 0;
    DaragonBag(BaseKnight* k, int a, int b) :BaseBag() {
        this->k = k;
        this->a = a;
        this->b = b;
    }
    bool insertFirst(BaseItem* item);
    void create();
    BaseItem* get(ItemType itemType);
    string toString() const;
};

class LancelotBag : public BaseBag {
public:
    int Maxitem = 16;
    BaseKnight* k;
    int a;
    int b;
    int count = 0;
    LancelotBag(BaseKnight* k, int a, int b) :BaseBag() {
        this->k = k;
        this->a = a;
        this->b = b;
    }
    bool insertFirst(BaseItem* item);
    void create();
    BaseItem* get(ItemType itemType);
    string toString() const;
};

class NormalBag : public BaseBag {
public:
    int Maxitem = 19;
    BaseKnight* k;
    int a;
    int b;
    int count = 0;
    NormalBag(BaseKnight* k, int a, int b) :BaseBag() {
        this->k = k;
        this->a = a;
        this->b = b;
    }
    bool insertFirst(BaseItem* item);
    void create();
    BaseItem* get(ItemType itemType);
    string toString() const;
};

class MadBear : public BaseOpponent{
    public:
    int gil = 100;
    int baseDamge = 10;
    int level =0;
    int numE = 0;
    BaseKnight *k;
    MadBear(int level,int numberEvents,BaseKnight *k){
        this->level = level;
        this->numE = numberEvents;
        this->k = k;
    };
    int level0(){
        return (numE+1)%10+1;
    }
    bool fight(int level,int level0);
    BaseKnight *updateKnight(BaseKnight *k);
};

class Bandit: public BaseOpponent{
    public:
    int gil = 150;
    int baseDamge = 15;
    int level;
    int numE =0;
    BaseKnight *k;
    Bandit(int level,int numberEvents,BaseKnight *k){
        this->level = level;
        this->numE = numberEvents;
        this->k = k;
    };
    int level0(){
        return (numE+2)%10+1;
    }
    bool fight(int level,int level0);
    BaseKnight *updateKnight(BaseKnight *k);
};

class LordLupin:public BaseOpponent{
    public:
    int gil = 450;
    int baseDamge = 45;
    int level;
    int numE =0;
    BaseKnight *k;
    LordLupin(int level,int numberEvents,BaseKnight *k){
        this->level = level;
        this->numE = numberEvents;
        this->k = k;
    };
    int level0(){
        return (numE+3)%10+1;
    }
    bool fight(int level,int level0);
    BaseKnight *updateKnight(BaseKnight *k);
};

class Elf : public BaseOpponent{
    public:
    int gil = 750;
    int baseDamge = 75;
    int level =0;
    int numE =0;
    BaseKnight *k;
    Elf(int level,int numberEvents,BaseKnight *k){
        this->level = level;
        this->numE = numberEvents;
        this->k = k;
    };
    int level0(){
        return (numE+4)%10+1;
    }
    bool fight(int level,int level0);
    BaseKnight *updateKnight(BaseKnight *k);
};

class Troll: public BaseOpponent{
public:
    int gil = 800;
    int baseDamge = 95;
    int level;
    int numE = 0;
    BaseKnight *k;
    Troll(int level,int numberEvents,BaseKnight *k){
        this->level = level;
        this->numE = numberEvents;
        this->k = k;
    };
    int level0(){
        return (numE+5)%10+1;
    }
    bool fight(int level,int level0);
    BaseKnight *updateKnight(BaseKnight *k);
};

class Tornbery:public BaseOpponent{
    public:
    int level;
    int numE =0;
    BaseKnight *k;
    Tornbery(int level,int numberEvents,BaseKnight *k){
        this->level = level;
        this->numE = numberEvents;
        this->k = k;
    };
    int level0(){
        return (numE+6)%10+1;
    }
    bool fight(int level,int level0);
    BaseKnight *updateKnight(BaseKnight *k);
};

class QueenOfCards: public BaseOpponent{
public:
    int gil = 800;
    int baseDamge = 95;
    int level;
    int numE =0;
    BaseKnight *k;
    QueenOfCards(int level,int numberEvents,BaseKnight *k){
        this->level = level;
        this->numE = numberEvents;
        this->k = k;
    };
    int level0(){
        return (numE+7)%10+1;
    }
    bool fight(int level,int level0);
    BaseKnight *updateKnight(BaseKnight *k);
};

class KnightAdventure {
private:
    ArmyKnights * armyKnights;
    Events * events;
public:
    KnightAdventure();
    ~KnightAdventure();

    void loadArmyKnights(const string &);
    void loadEvents(const string &);
    void run();
};

class Antidote: public BaseItem{
    bool canUse(BaseKnight* knight){
        if((knight->getpoisoning()) && (knight->getantidote() > 0)) return 1;
        return 0;
    } ;
    void use(BaseKnight* knight){
        knight->setpoisoning(0);
        knight->setantidote(knight->getantidote()-1);
    }; 
};

class PhoenixDownI: public BaseItem{
    bool canUse(BaseKnight* knight){
        if(knight->getHp() <= 0) return 1;
        return 0;
    } ;
    void use(BaseKnight* knight){
        knight->setphoenixdownI (knight->getphoenixdownI()-1);
        knight->setHp(knight->getHpmax());
    }; 
};

class PhoenixDownII: public BaseItem{
    bool canUse(BaseKnight* knight){
        int hpcalc = knight->getHpmax()/4;
        if(knight->getHp() < hpcalc ) return 1;
        return 0;
    };
    void use(BaseKnight* knight){
        knight->setphoenixdownI (knight->getphoenixdownII()-1);
        knight->setHp(knight->getHpmax());
    }; 
};

class PhoenixDownIII: public BaseItem{
    bool canUse(BaseKnight* knight){
        int hpcalc = knight->getHpmax()/3;
        if(knight->getHp()<hpcalc) return 1;
        return 0;
    };
    void use(BaseKnight* knight){
        if(knight->getHp() <= 0 ){
            knight->setHp(knight->getHpmax()/3);
        } else knight->setHp(knight->getHp()+knight->getHpmax()/4);
        knight->setphoenixdownIII(knight->getphoenixdownIII()-1);
    }; 
};

class PhoenixDownIV: public BaseItem{
    bool canUse(BaseKnight* knight){
        int hpcalc = knight->getHpmax()/2;
        if(knight->getHp()<hpcalc) return 1;
        return 0;
    };
    void use(BaseKnight* knight){
         if(knight->getHp() <= 0 ){
            knight->setHp(knight->getHpmax()/2);
        } else knight->setHp(knight->getHp()+knight->getHpmax()/5);
        knight->setphoenixdownIV(knight->getphoenixdownIV()-1);
    }; 
};
#endif // __KNIGHT2_H__