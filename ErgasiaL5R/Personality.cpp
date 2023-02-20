#include "Personality.h"

Personality::Personality()
{
    f = new Follower*[2];       //max Followers on a Personality = 2
    for(int i = 0; i<2; i++){
        f[i] = NULL;             //no followers yet
    }
    it = new Item*[2];       //max Items on a Personality = 2
    for(int i = 0; i<2; i++){
        it[i] = NULL;             //no items yet
    }
}

Personality::~Personality() {
    for(int i = 0; i<2; i++){
        delete f[i];
    }
    delete[] f;

    for(int i = 0; i<2; i++){
        delete it[i];
    }
    delete[] it;
}

Type Personality::getType() {return PERSONALITY;}

int Personality::getTotalAttack() {
    int AttackTotal=Attack, i=0;
    while(f[i]!=NULL) {
        AttackTotal += f[0]->getAttackBonus();
        i++;
    }
    i=0;
    while(it[i]!=NULL) {
        AttackTotal += it[i]->getAttackBonus();
        i++;
    }
    return AttackTotal;
}

int Personality::getTotalDefense() {
    int DefenseTotal=Defense, i=0;
    while(f[i]!=NULL) {
        DefenseTotal += f[0]->getDefenseBonus();
        i++;
    }
    i=0;
    while(it[i]!=NULL) {
        DefenseTotal += it[i]->getDefenseBonus();
        i++;
    }
    return DefenseTotal;
}

int Personality::getAttack() {return Attack;}
int Personality::getDefense() {return Defense;}

bool Personality::Dead() {return isDead;}
void Personality::Kill() {isDead = true;}
int Personality::getHonor() {return Honor;}

bool Personality::Equip(Follower *fo) {
    for(int i = 0; i<2; i++){
        if(f[i]==NULL){
            Follower *temp;
            temp = fo;
            f[i] = temp;
            return true;
        }else if(i==1){
            cout << "Can't assign this Follower to this Personality because it already has 2 Followers" << endl;
            return false;
        }
    }
}

bool Personality::Equip(Item *item) {
    for(int i = 0; i<2; i++){
        if(it[i]==NULL){
            Item *temp;
            temp = item;
            it[i] = temp;
            return true;
        }else if(i==1){
            cout << "Can't assign this Item to this Personality because it already has 2 Items" << endl;
            return false;
        }
    }
}

void Personality::KillFollowers(int d) {        //d stands for difference between attacking-defending points
    for(int i = 1; i>=0; i--){
        if(f[i]!=NULL) {
            if(f[i]->getAttackBonus()>=d){
                delete f[i];
                f[i] = NULL;
            }
        }
    }
}

Attacker::Attacker(string a) {
    Cost         = 0;
    Attack       = 3;
    Defense      = 2;
    Honor        = 2;
    Name         = a;
    isRevealed   = false;
    isTapped     = false;
    isDead       = false;
}
void Attacker::print() {
    cout << "Personality->Attacker: " << Name << ", Cost = " << Cost << ", ATK: " << Attack << ", DEF: " << Defense << ", HNR: " << Honor << endl;
    for(int i = 0; i<2; i++){
        if(f[i] != NULL)  {
            cout << "Attached Follower: ";
            f[i]->print();
        }
    }
    for(int i = 0; i<2; i++){
        if(it[i] != NULL)  {
            cout << "Attached Item: ";
            it[i]->print();
        }
    }
}

Defender::Defender(string a) {
    Cost         = 5;
    Attack       = 2;
    Defense      = 3;
    Honor        = 2;
    Name         = a;
    isRevealed   = false;
    isTapped     = false;
    isDead       = false;
}

void Defender::print() {
    cout << "Personality->Defender: " << Name << ", Cost = " << Cost << ", ATK: " << Attack << ", DEF: " << Defense << ", HNR: " << Honor << endl;
    for(int i = 0; i<2; i++){
        if(f[i] != NULL)  {
            cout << "Attached Follower: ";
            f[i]->print();
        }
    }
    for(int i = 0; i<2; i++){
        if(it[i] != NULL)  {
            cout << "Attached Item: ";
            it[i]->print();
        }
    }
}

Champion::Champion(string a) {
    Cost         = 30;
    Attack       = 20;
    Defense      = 20;
    Honor        = 12;
    Name         = a;
    isRevealed   = false;
    isTapped     = false;
    isDead       = false;
}
void Champion::print() {
    cout << "Personality->Champion: " << Name << ", Cost = " << Cost << ", ATK: " << Attack << ", DEF: " << Defense << ", HNR: " << Honor << endl;
    for(int i = 0; i<2; i++){
        if(f[i] != NULL)  {
            cout << "Attached Follower: ";
            f[i]->print();
        }
    }
    for(int i = 0; i<2; i++){
        if(it[i] != NULL)  {
            cout << "Attached Item: ";
            it[i]->print();
        }
    }
}

Chancellor::Chancellor(string a) {
    Cost         = 15;
    Attack       = 5;
    Defense      = 10;
    Honor        = 8;
    Name         = a;
    isRevealed   = false;
    isTapped     = false;
    isDead       = false;
}
void Chancellor::print() {
    cout << "Personality->Chancellor: " << Name << ", Cost = " << Cost << ", ATK: " << Attack << ", DEF: " << Defense << ", HNR: " << Honor << endl;
    for(int i = 0; i<2; i++){
        if(f[i] != NULL)  {
            cout << "Attached Follower: ";
            f[i]->print();
        }
    }
    for(int i = 0; i<2; i++){
        if(it[i] != NULL)  {
            cout << "Attached Item: ";
            it[i]->print();
        }
    }
}

Shogun::Shogun(string a) {
    Cost         = 15;
    Attack       = 10;
    Defense      = 5;
    Honor        = 8;
    Name         = a;
    isRevealed   = false;
    isTapped     = false;
    isDead       = false;
}
void Shogun::print() {
    cout << "Personality->Shogun: " << Name << ", Cost = " << Cost << ", ATK: " << Attack << ", DEF: " << Defense << ", HNR: " << Honor << endl;
    for(int i = 0; i<2; i++){
        if(f[i] != NULL)  {
            cout << "Attached Follower: ";
            f[i]->print();
        }
    }
    for(int i = 0; i<2; i++){
        if(it[i] != NULL)  {
            cout << "Attached Item: ";
            it[i]->print();
        }
    }
}