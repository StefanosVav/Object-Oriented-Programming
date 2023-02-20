#ifndef PERSONALITY_H
#define PERSONALITY_H

#include "Follower.h"
#include "Item.h"

class Personality : public BlackCard {
protected:
    int Attack;
    int Defense;
    int Honor;
    bool isDead;
    Follower ** f;
    Item ** it;
public:
    Personality();
    ~Personality();
    Type getType();
    int getAttack();
    int getDefense();
    int getTotalAttack();
    int getTotalDefense();
    void KillFollowers(int);
    int getHonor();
    bool Dead();
    void Kill();
    bool Equip(Follower *);
    bool Equip(Item *);
};

class Attacker: public Personality{
public:
    Attacker(string);
    void print();
};

class Defender : public Personality{
public:
    Defender(string);
    void print();
};

class Champion : public Personality{
public:
    Champion(string);
    void print();
};

class Chancellor : public Personality{
public:
    Chancellor(string);
    void print();
};

class Shogun : public Personality{
public:
    Shogun(string);
    void print();
};


#endif
