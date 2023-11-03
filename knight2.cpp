#include "knight2.h"

/* * * BEGIN Function * * */
bool prime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

bool checkDragon(int hp) {
    int check = hp / 100;
    if ((check >= 10) || (check < 1)) {
        return 0;
    }
    int a = hp / 100;
    int b = (hp - a * 100) / 10;
    int c = (hp - a * 100 - b * 10);
    if(a != 0 && b != 0 && c !=0){
        if (a * a + b * b == c * c || a * a + c * c == b * b || c * c + b * b == a * a) return 1;
    }
    return 0;
}
/* * * END Function * * */

/* * * BEGIN implementation of class BaseBag * * */
BaseItem* addNode(ItemType x) {
    BaseItem *p;
    switch (x){
        case ANTIDOTE:{
            p = new Antidote;
            break;
        }
        case PHOENIXDOWNI :{
            p = new PhoenixDownI;
            break;
        }
        case PHOENIXDOWNII :{
            p = new PhoenixDownII;
            break;
        }
        case PHOENIXDOWNIII :{
            p = new PhoenixDownIII;
            break;
        }
        case PHOENIXDOWNIV :{
            p = new PhoenixDownII;
            break;
        }
        default:
            break;
    }
    p = new PhoenixDownI;
    if (p == NULL) {
        return NULL;
    }
    p->data = x;
    p->next = NULL;
    return p;
}
void addBag(BaseItem *&Head, BaseItem *temp){
    if(Head == NULL){
        Head = temp;
    } else {
        temp->next = Head;
        Head = temp;
    }
}
void swapItem(BaseItem* Head, ItemType item) {
    if (Head == NULL || Head->next == NULL) {
        return ;
    }
    ItemType a = Head->data;
    Head->data = item;
    Head = Head->next;
    while (Head != NULL)
    {
        if(Head->data == item){
            Head->data = a;
            break;
        } 
        Head = Head->next;
    }
}
BaseItem * deleteItemBag(BaseItem *Head){
    if (Head != NULL) {
        Head = Head->next;
        return Head;
    }
    return NULL;
} 

bool BaseBag::insertFirst(BaseItem* item){
    return 1;
}

BaseItem *BaseBag::get(ItemType itemType){
    return NULL;
}

string BaseBag::toString() const{
    string s("");
     s += "Bag[count=" + to_string(this->count)
      + ";" ;
    BaseItem *current = Head;
    while (current != NULL) {
        ItemType type = current->data;
        switch (type){
            case ANTIDOTE:{
                s+= "Antidote";
                break;
            }
            case PHOENIXDOWNI:{
                s+= "PhoenixI";
                break;
            }
            case PHOENIXDOWNII:{
                s+= "PhoenixII";
                break;
            }
            case PHOENIXDOWNIII:{
                s+= "PhoenixIII";
                break;
            }
            case PHOENIXDOWNIV:{
                s+= "PhoenixIV";
                break;
            }
        }
        current = current->next;
        if (current != NULL) {
            s += ",";
        }
    }
    s += "]";
    return s;
}

void PaladinBag::create(){
    if(this->a > 0){
        for(int i=0;i<this->a;i++){
            BaseItem *temp = addNode(PHOENIXDOWNI);
            if(this->insertFirst(temp)){
                addBag(Head,temp);
            } else break;
        }
    }
    if(this->b > 0){
        for (int i=0;i<this->b;i++){
            BaseItem *temp = addNode(ANTIDOTE);
            if(this->insertFirst(temp)){

                addBag(Head,temp);
            } else break;
        }
    }   
}

bool PaladinBag::insertFirst(BaseItem* item){
    // cout<<endl;
    this->count += 1;
    return 1;
}

BaseItem* PaladinBag::get(ItemType itemType){
    BaseItem *p = k->getBag()->getHead();
    while(p==NULL){
        if(p->data == itemType) return p;
        p=p->next;
    }
    return NULL;
}

string PaladinBag::toString() const{
    string s("");
    return s;
}

void DaragonBag::create(){
    if(this->a > 0){
        for(int i=0;i<this->a;i++){
            BaseItem *temp = addNode(PHOENIXDOWNI);
            if(this->insertFirst(temp)){
                addBag(Head,temp);
            } else break;
        }
    }
    if(this->b > 0){
        for (int i=0;i<this->b;i++){
            BaseItem *temp = addNode(ANTIDOTE);
            if(this->insertFirst(temp)){
                addBag(Head,temp);
            } else break;
        }
    }   
}

bool DaragonBag::insertFirst(BaseItem* item){
    if(item->data != ANTIDOTE && this->count < Maxitem ){
        this->count += 1;
        return 1;
    }
    return 0;
}

BaseItem* DaragonBag::get(ItemType itemType){
    BaseItem *p = k->getBag()->getHead();
    while(p==NULL){
        if(p->data == itemType) return p;
        p=p->next;
    }
    return NULL;
}

string DaragonBag::toString() const{
    string s("");
    return s;
}
void LancelotBag::create(){
    if(this->a > 0){
        for(int i=0;i<this->a;i++){
            BaseItem *temp = addNode(PHOENIXDOWNI);
            if(this->insertFirst(temp)){
                addBag(Head,temp);
            } else break;
        }
    }
    if(this->b > 0){
        for (int i=0;i<this->b;i++){
            BaseItem *temp = addNode(ANTIDOTE);
            if(this->insertFirst(temp)){

                addBag(Head,temp);
            } else break;
        }
    }   
}

bool LancelotBag::insertFirst(BaseItem* item){
    if(this->count < Maxitem ){
        this->count += 1;
        return 1;
    }
    return 0;
}

BaseItem* LancelotBag::get(ItemType itemType){
    BaseItem *p = k->getBag()->getHead();
    while(p==NULL){
        if(p->data == itemType) return p;
        p=p->next;
    }
    return NULL;
}

string LancelotBag::toString() const{
    string s("");
    return s;
}
void NormalBag::create(){
    if(this->a > 0){
        for(int i=0;i<this->a;i++){
            BaseItem *temp = addNode(PHOENIXDOWNI);
            if(this->insertFirst(temp)){
                addBag(Head,temp);
            } else break;
        }
    }
    if(this->b > 0){
        for (int i=0;i<this->b;i++){
            BaseItem *temp = addNode(ANTIDOTE);
            if(this->insertFirst(temp)){

                addBag(Head,temp);
            } else break;
        }
    }   
}

bool NormalBag::insertFirst(BaseItem* item){
    if(this->count <= Maxitem ){
        this->count += 1;
        return 1;
    }
    return 0;
}

BaseItem* NormalBag::get(ItemType itemType){
    BaseItem *p = k->getBag()->getHead();
    while(p==NULL){
        if(p->data == itemType) return p;
        p=p->next;
    }
    return NULL;
}

string NormalBag::toString() const{
    string s("");
    return s;
}
/* * * END implementation of class BaseBag * * */

/* * * BEGIN implementation of class BaseOpponent * * */
bool MadBear::fight(int level,int level0){
    if(level >= level0) return 1 ; else return 0; 
}

BaseKnight *MadBear::updateKnight(BaseKnight *k){
    if(fight(this->level,this->level0())){
        k->setgil(k->getgil() + 100);
    } else {
        k->setHp(k->getHp() - this->baseDamge * (level0()-level));
    }
    return this->k;
}

bool Bandit::fight(int level,int level0){
    if(level >= level0) return 1 ; else return 0; 
}

BaseKnight *Bandit::updateKnight(BaseKnight *k){
    if(fight(this->level,this->level0())){
        k->setgil(k->getgil()+ 150);
    } else {
        k->setHp(k->getHp() - this->baseDamge * (level0() - level));
    }
    return this->k;
}

bool LordLupin::fight(int level,int level0){
    if(level >= level0) return 1 ; else return 0; 
}

BaseKnight *LordLupin::updateKnight(BaseKnight *k){
    if(fight(this->level,this->level0())){
        k->setgil(k->getgil()+ 450);
    } else {
        k->setHp(k->getHp() - this->baseDamge * (level0() - level));
    }
    return this->k;
}

bool Elf::fight(int level,int level0){
    if(level >= level0) return 1 ; else return 0; 
}

BaseKnight *Elf::updateKnight(BaseKnight *k){
    if(fight(this->level,this->level0())){
        k->setgil(k->getgil()+ this->gil);
    } else {
        k->setHp(k->getHp() - this->baseDamge * (level0() - level));
    }
    return this->k;
}

bool Troll::fight(int level,int level0){
    if(level >= level0) return 1 ; else return 0; 
}

BaseKnight *Troll::updateKnight(BaseKnight *k){
    if(fight(this->level,this->level0())){
        k->setgil(k->getgil()+ this->gil);
    } else {
        k->setHp(k->getHp() - this->baseDamge * (level0() - level));
    }
    return this->k;
}

bool Tornbery::fight(int level,int level0){
    if(level >= level0) return 1 ; else return 0; 
}

BaseKnight *Tornbery::updateKnight(BaseKnight *k){
    if(fight(this->level,this->level0())){
        k->setlev(k->getlev() + 1);
    } else {
        if(k->gettype() == DRAGON) k->setpoisoning(0); else
        k->setpoisoning(1);
    }
    return this->k;
}

bool QueenOfCards::fight(int level,int level0){
    if(level >= level0) return 1 ; else return 0; 
}

BaseKnight *QueenOfCards::updateKnight(BaseKnight *k){
    if(fight(this->level,this->level0())){
        k->setgil(k->getgil()*2);
    } else {
        if(k->gettype()!= PALADIN) k->setgil(k->getgil()/2);
    }
    return this->k;
}
/* * * END implementation of class BaseOpponent * * */

/* * * BEGIN implementation of class BaseKnight * * */
string BaseKnight::toString() const {
    string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    // inefficient version, students can change these code
    //      but the format output must be the same
    string s("");
    s += "[Knight:id:" + to_string(id) 
        + ",hp:" + to_string(hp) 
        + ",maxhp:" + to_string(maxhp)
        + ",level:" + to_string(level)
        + ",gil:" + to_string(gil)
        + "," + bag->toString()
        + ",knight_type:" + typeString[knightType]
        + "]";
    return s;
}
BaseKnight::BaseKnight(){
    bag = new BaseBag();
}
BaseKnight* BaseKnight::create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI) {
    BaseKnight* Knight = new BaseKnight();
    Knight->id = id;
    Knight->maxhp = maxhp;
    Knight->hp = maxhp;
    Knight->level = level;
    Knight->gil = gil;
    if(antidote > 5) Knight->antidote = 5; else Knight->antidote = antidote;
    if(phoenixdownI > 5) Knight->phoenixdownI = 5; else Knight->phoenixdownI = phoenixdownI;
    if (prime(maxhp)) {
        Knight->knightType = PALADIN;
    }
    else if (maxhp == 888) {
        Knight->knightType = LANCELOT;
    }
    else if (checkDragon(maxhp)) {
        Knight->knightType = DRAGON;
    }
    else {
        Knight->knightType = NORMAL;
    }
    return Knight;
}
/* * * END implementation of class BaseKnight * * */

/* * * BEGIN implementation of class ArmyKnights * * */
ArmyKnights::ArmyKnights(const string& file_armyknights) {
    ifstream armyKnights(file_armyknights);
    armyKnights >> numberKnight;
    arrKnigths = new BaseKnight * [numberKnight + 1];
    for (int i = 1; i <= numberKnight; i++) {
        *(arrKnigths + i) = new BaseKnight();
        int maxhp;
        int level;
        int gil;
        int antidote;
        int phoenixdownI;
        armyKnights >> maxhp >> level >>phoenixdownI>> gil >> antidote;
        arrKnigths[i] = BaseKnight::create(i, maxhp, level, gil, antidote, phoenixdownI);
        switch(arrKnigths[i]->gettype()){
            case PALADIN:{
                PaladinBag *p = new PaladinBag(arrKnigths[i],arrKnigths[i]->getphoenixdownI(),arrKnigths[i]->getantidote());
                p->create();
                arrKnigths[i]->getBag()->setHead(p->getHead());
                arrKnigths[i]->getBag()->setCount(p->count);
                break;
            }
            case LANCELOT:{
                LancelotBag *p = new LancelotBag(arrKnigths[i],arrKnigths[i]->getphoenixdownI(),arrKnigths[i]->getantidote());
                p->create();
                arrKnigths[i]->getBag()->setHead(p->getHead());
                arrKnigths[i]->getBag()->setCount(p->count);
                break;
            }
            case DRAGON:{
                DaragonBag *p = new DaragonBag(arrKnigths[i],arrKnigths[i]->getphoenixdownI(),arrKnigths[i]->getantidote());
                p->create();
                arrKnigths[i]->getBag()->setHead(p->getHead());
                arrKnigths[i]->getBag()->setCount(p->count);
                break;
            }
            case NORMAL:{
                NormalBag *p = new NormalBag(arrKnigths[i],arrKnigths[i]->getphoenixdownI(),arrKnigths[i]->getantidote());
                p->create();
                arrKnigths[i]->getBag()->setHead(p->getHead());
                arrKnigths[i]->getBag()->setCount(p->count);
                break;
            }
            default:{
                break;
            }            
        }
    }
    armyKnights.close();
}

ArmyKnights::~ArmyKnights() {
    
}

BaseKnight* ArmyKnights::lastKnight() const {
    if (numberKnight == 0) return NULL;
    return arrKnigths[numberKnight];
}

int ArmyKnights::count() const {
    return numberKnight;
}

bool ArmyKnights::hasPaladinShield() const {
    return PaladinShield;
}

bool ArmyKnights::hasLancelotSpear() const {
    return LancelotSpear;
}

bool ArmyKnights::hasGuinevereHair() const {
    return GuinevereHair;
}

bool ArmyKnights::hasExcaliburSword() const {
    return ExcaliburSword;
}

bool ArmyKnights::fight(BaseOpponent * opponent){
    return 1;
}


void ArmyKnights::printInfo() const {
    cout << "No. knights: " << this->count();
    if (this->count() > 0) {
        BaseKnight * lknight = lastKnight();
        cout << ";" << lknight->toString();
    }
    cout << ";PaladinShield:" << this->hasPaladinShield()
        << ";LancelotSpear:" << this->hasLancelotSpear()
        << ";GuinevereHair:" << this->hasGuinevereHair()
        << ";ExcaliburSword:" << this->hasExcaliburSword()
        << endl
        << string(50, '-') << endl;
}

void ArmyKnights::printResult(bool win) const {
    cout << (win ? "WIN" : "LOSE") << endl;
}

/* * * END implementation of class ArmyKnights * * */

/* * * BEGIN implementation of class Events * * */
Events::Events(const string& file_events) {
    ifstream events(file_events);
    events >> maplength;
    map = new int[maplength];
    for (int i = 0; i < maplength; i++) {
        events >> map[i];
    }
    events.close();
}

int Events::count() const{
    return maplength;
}

int Events::get(int i) const {
    return map[i];
}


/* * * END implementation of class Events * * */

/* * * BEGIN implementation of class KnightAdventure * * */
KnightAdventure::KnightAdventure() {
    armyKnights = nullptr;
    events = nullptr;
}

KnightAdventure::~KnightAdventure() {
    delete armyKnights;
    delete events;
}

void KnightAdventure::loadArmyKnights(const string& file_armyknights) {
    armyKnights = new ArmyKnights(file_armyknights);
}

void KnightAdventure::loadEvents(const string& file_events) {
    events = new Events(file_events);
}
void events112to114(BaseItem *temp,int number,BaseKnight** arrKnigths){
    if(number < 1) return;
    int maxitem;
    BaseKnight *hiepsi = arrKnigths[number];
        switch(hiepsi->gettype()){
        case DRAGON:{
            maxitem = 14;
            break;
        }
        case LANCELOT:{
            maxitem = 16;
            break;
        }
        case PALADIN:{
            maxitem = -1;
            break;
        }
        case NORMAL:{
            maxitem = 19;
            break;
        }
        default:
            break;
        }
        BaseItem *Head1 = hiepsi->getBag()->getHead();
        if((hiepsi->getBag()->getCount() < maxitem) || (maxitem == -1) ){
            hiepsi->getBag()->setCount(hiepsi->getBag()->getCount()+1);
            addBag(Head1,temp);
        } else {
            events112to114(temp,number-1,arrKnigths);
        }
        hiepsi->getBag()->setHead(Head1);
        return;
}

void collectgil(int numberKnight,BaseKnight** arrKnigths){
    int preKnight = numberKnight;
    int gildu = 0;
    while(preKnight !=0){
        arrKnigths[preKnight]->setgil(arrKnigths[preKnight]->getgil()+ gildu);
        int nextKnight = preKnight  - 1;
        if(arrKnigths[preKnight]->getgil() > 999){
            gildu = arrKnigths[preKnight]->getgil() - 999;
            arrKnigths[preKnight]->setgil(999);
        } else break;
        preKnight = nextKnight;
    }

}
void set(BaseKnight *hiepsi){
        BaseItem *current = hiepsi->getBag()->getHead();
        while(current != NULL){
            ItemType item = current->data;
                if(item == ANTIDOTE ){
                    BaseItem *Item = new Antidote;
                    if(Item->canUse(hiepsi)){
                        Item->use(hiepsi);
                        swapItem(hiepsi->getBag()->getHead(),ANTIDOTE);
                        hiepsi->getBag()->setHead(deleteItemBag(hiepsi->getBag()->getHead()));
                        hiepsi->getBag()->setCount(hiepsi->getBag()->getCount()-1);
                        break;
                    }
                    // delete Item;
                } else if(item == PHOENIXDOWNI ){
                    BaseItem *Item = new PhoenixDownI;
                    if(Item->canUse(hiepsi)){
                        Item->use(hiepsi);
                        swapItem(hiepsi->getBag()->getHead(),PHOENIXDOWNI);
                        hiepsi->getBag()->setHead(deleteItemBag(hiepsi->getBag()->getHead()));
                        hiepsi->getBag()->setCount(hiepsi->getBag()->getCount()-1);
                        break;
                    }
                    // delete Item;
                } else if(item == PHOENIXDOWNII ){
                    BaseItem *Item = new PhoenixDownII;
                    if(Item->canUse(hiepsi)){
                        Item->use(hiepsi);
                        swapItem(hiepsi->getBag()->getHead(),PHOENIXDOWNII);
                        hiepsi->getBag()->setHead(deleteItemBag(hiepsi->getBag()->getHead()));
                        hiepsi->getBag()->setCount(hiepsi->getBag()->getCount()-1);
                        break;
                    }
                    // delete Item;
                } else if(item == PHOENIXDOWNIII ){
                    BaseItem *Item = new PhoenixDownIII;
                    if(Item->canUse(hiepsi)){
                        Item->use(hiepsi);
                        swapItem(hiepsi->getBag()->getHead(),PHOENIXDOWNIII);
                        hiepsi->getBag()->setHead(deleteItemBag(hiepsi->getBag()->getHead()));
                        hiepsi->getBag()->setCount(hiepsi->getBag()->getCount()-1);
                        break;
                    }
                    // delete Item;
                } else if(item == PHOENIXDOWNIV ){
                    BaseItem *Item = new PhoenixDownIV;
                    if(Item->canUse(hiepsi)){
                        Item->use(hiepsi);
                        swapItem(hiepsi->getBag()->getHead(),PHOENIXDOWNIV);
                        hiepsi->getBag()->setHead(deleteItemBag(hiepsi->getBag()->getHead()));
                        hiepsi->getBag()->setCount(hiepsi->getBag()->getCount()-1);
                        break;
                    }
                    // delete Item;
                } 
            current = current->next;
        }
        // delete current;
}
bool ArmyKnights::adventure(Events *events){
    int numberE = 0;
    int recuse = 1;
    while(recuse){
        BaseKnight *hiepsi = this->lastKnight();
        switch (events->get(numberE))
        {
            case 1:{
                int hpao = hiepsi->getHp();
                if((hiepsi->gettype() == LANCELOT) || (hiepsi->gettype() == PALADIN)){
                    hiepsi->setgil(hiepsi->getgil()+ 100);
                    break;
                }
                MadBear *doithu = new MadBear(hiepsi->getlv(),numberE,hiepsi);
                hiepsi = doithu->updateKnight(hiepsi);
                if(hpao != hiepsi->getHp()){
                    set(hiepsi);
                }
                delete doithu;
                break;
            }
            case 2:{
                int hpao = hiepsi->getHp();
                if(hiepsi->gettype() == LANCELOT || hiepsi->gettype() == PALADIN) {
                    hiepsi->setgil(hiepsi->getgil()+ 150);
                    break;
                }
                Bandit *doithu = new Bandit(hiepsi->getlv(),numberE,hiepsi);
                hiepsi = doithu->updateKnight(hiepsi);
                if(hpao != hiepsi->getHp()){
                    set(hiepsi);
                }
                delete doithu;
                break;
            }
            case 3:{
                int hpao = hiepsi->getHp();
                if(hiepsi->gettype() == LANCELOT || hiepsi->gettype() == PALADIN) {
                    hiepsi->setgil(hiepsi->getgil()+ 450);
                    break;
                }
                LordLupin *doithu = new LordLupin(hiepsi->getlv(),numberE,hiepsi);
                hiepsi = doithu->updateKnight(hiepsi);
                if(hpao != hiepsi->getHp()){
                    set(hiepsi);
                }
                delete doithu;
                break;
            }
            case 4:{
                int hpao = hiepsi->getHp();
                if(hiepsi->gettype() == LANCELOT || hiepsi->gettype() == PALADIN) {
                    hiepsi->setgil(hiepsi->getgil()+ 750);
                    break;
                }
                Elf *doithu = new Elf(hiepsi->getlv(),numberE,hiepsi);
                hiepsi = doithu->updateKnight(hiepsi);
                if(hpao != hiepsi->getHp()){
                    set(hiepsi);
                }
                delete doithu;
                break;
            }
            case 5:{
                int hpao = hiepsi->getHp();
                if((hiepsi->gettype() == LANCELOT) || (hiepsi->gettype() == PALADIN)){
                    hiepsi->setgil(hiepsi->getgil()+ 800);
                    break;
                } 
                Troll *doithu = new Troll(hiepsi->getlv(),numberE,hiepsi);
                hiepsi = doithu->updateKnight(hiepsi);
                if(hpao != hiepsi->getHp()){
                    set(hiepsi);
                }
                delete doithu;
                break;
            }
            case 6:{
                Tornbery *doithu = new Tornbery(hiepsi->getlv(),numberE,hiepsi);
                hiepsi = doithu->updateKnight(hiepsi);
                delete doithu;
                BaseItem *current = hiepsi->getBag()->getHead();
                while(current != NULL){
                    ItemType item = current->data;
                    if(item == ANTIDOTE ){
                        BaseItem *Item = new Antidote;
                        if(Item->canUse(hiepsi)){
                            Item->use(hiepsi);
                            swapItem(hiepsi->getBag()->getHead(),ANTIDOTE);
                            hiepsi->getBag()->setHead(deleteItemBag(hiepsi->getBag()->getHead()));
                            hiepsi->getBag()->setCount(hiepsi->getBag()->getCount()-1);
                        }
                        // delete Item;
                    } 
                    current = current->next;
                }
                // delete current;
                break;
            }
            case 7:{
                QueenOfCards *doithu = new QueenOfCards(hiepsi->getlv(),numberE,hiepsi);
                hiepsi = doithu->updateKnight(hiepsi);
                delete doithu;
                break;
            }
            case 8:{
                if(hiepsi->gettype() == PALADIN){
                    int calc = hiepsi->getHpmax()/3;
                    if((hiepsi->getHp() < calc )){
                        hiepsi->setHp(hiepsi->getHp()+hiepsi->getHpmax()/5);
                    }
                    break;
                }
                int calc = hiepsi->getHpmax()/3;
                if((hiepsi->getHp() < calc )&& (hiepsi->getgil() >= 50)){
                    hiepsi->setHp(hiepsi->getHp()+hiepsi->getHpmax()/5);
                    hiepsi->setgil(hiepsi->getgil()-50);
                    break;
                }
                break;
            }
            case 9:{
                hiepsi->setHp(hiepsi->getHpmax());
                break;
            }
            case 10:{
                int hpao = hiepsi->getHp();
                if(omega == 1) break;
                if((hiepsi->getlev() == 10 && hiepsi->getHp() == hiepsi->getHpmax()) || (hiepsi->gettype() == DRAGON) ){
                    hiepsi->setlev(hiepsi->getlev() + 10);
                    hiepsi->setgil(999);
                    omega = 1;
                } else {
                    hiepsi->setHp(0);
                }
                if(hpao != hiepsi->getHp()){
                    set(hiepsi);
                }
                break;
            }
            case 11:{
                int hpao = hiepsi->getHp();
                if(hades == 1) break;
                if((hiepsi->getlev() == 10) || (hiepsi->gettype() == PALADIN && hiepsi->getlev() >= 8)){
                    if(this->hasPaladinShield() == 0){
                        this->setPaladinShield(1);
                        hades = 1;
                    }
                } else {
                    hiepsi->setHp(0);
                }
                if(hpao != hiepsi->getHp()){
                    set(hiepsi);
                }
                break;
            }
            case 99:{
                if (this->hasExcaliburSword()){
                    this->printInfo();
                    return 1;
                    break;
                }
                if((this->hasGuinevereHair() && this->hasLancelotSpear() && this->hasPaladinShield())){
                    int pre = numberKnight;
                    // int h = numberKnight;
                    int normal = -1;
                    // bool KO = 0;
                    int hpUltimecia = 5000;
                    int damage;
                    double knightBaseDamage[3] = {0.06,0.05,0.075};
                    while(pre != 0){
                        if(this->arrKnigths[pre]->gettype()== DRAGON || this->arrKnigths[pre]->gettype()== PALADIN || this->arrKnigths[pre]->gettype()== LANCELOT){
                            damage = this->arrKnigths[pre]->getHp() * this->arrKnigths[pre]->getlev()  * knightBaseDamage[this->arrKnigths[pre]->gettype()];
                            hpUltimecia -=damage;
                            if(hpUltimecia <= 0){
                                if(normal != -1){
                                    this->arrKnigths[numberKnight] = this->arrKnigths[normal];
                                    hiepsi= this->lastKnight();
                                    this->printInfo();
                                    return 1;
                                } else {
                                    hiepsi= this->lastKnight();
                                    this->printInfo();
                                    return 1;
                                }
                            }
                            numberKnight--;
                        } else if(normal == -1) {
                            normal = numberKnight;
                        } 
                        pre= pre - 1;
                    }
                
                } 
                numberKnight = 0;
                hiepsi= this->lastKnight();
                this->printInfo();
                return 0;
                
                break;
            }
            case 112:{
                BaseItem *temp = addNode(PHOENIXDOWNII);
                events112to114(temp,numberKnight,arrKnigths);
                break;
            }
            case 113:{
                BaseItem *temp = addNode(PHOENIXDOWNIII);
                events112to114(temp,numberKnight,arrKnigths);
                break;
            }
            case 114:{
                BaseItem *temp = addNode(PHOENIXDOWNIV);
                events112to114(temp,numberKnight,arrKnigths);
                break;
            }
            case 98:{
                if(this->hasPaladinShield() && this->hasGuinevereHair() && this->hasLancelotSpear()) this->setExcaliburSword(1);
                break;
            }
            case 95:{
                if(this->hasPaladinShield() == 0) this->setPaladinShield(1);
                break;
            }
            case 96:{
                if(this->hasLancelotSpear() == 0) this->setLancelotSpear(1);
                break;
            }
            case 97:{
                if(this->hasGuinevereHair() == 0) this->setGuinevereHair(1);
                break;
            }
            default:
                break;
        }
        
        collectgil(numberKnight,this->arrKnigths);
        if(hiepsi->getpoisoning()){
            if(hiepsi->getBag()->getCount() < 3){
                hiepsi->getBag()->setHead(NULL);
                hiepsi->getBag()->setCount(0);
            } else {
                int i=1;
                while(i < 4){
                    hiepsi->getBag()->setHead(deleteItemBag(hiepsi->getBag()->getHead()));
                    hiepsi->getBag()->setCount(hiepsi->getBag()->getCount()-1);
                    i++;
                }
            }
            hiepsi->setHp(hiepsi->getHp()-10);
            hiepsi->setpoisoning(0);
            set(hiepsi);
        }

        if(hiepsi->getHp() > hiepsi->getHpmax() ) {
            hiepsi->setHp(hiepsi->getHpmax());
        }
        if(hiepsi->getlev() > 10) hiepsi->setlev(10);
        if(hiepsi->getphoenixdownI() > 5) hiepsi->setphoenixdownI(5);
        if(hiepsi->getantidote() > 5) hiepsi->setantidote(5);
        if(hiepsi->getHp() <= 0){
            if(hiepsi->getgil() >= 100){
                hiepsi->setgil(hiepsi->getgil()-100);
                hiepsi->setHp(hiepsi->getHpmax()/2);
            }
        }
        if(hiepsi->getHp() <= 0) {
            numberKnight--;
        }
        this->printInfo();
        numberE++;
        if(numberKnight <= 0) {
            return 0;
        }
        if(numberE == events->count()) return 1;
    }
    return recuse;
}

void KnightAdventure::run() {
    armyKnights->printResult(armyKnights->adventure(events));
}
/* * * END implementation of class KnightAdventure * * */