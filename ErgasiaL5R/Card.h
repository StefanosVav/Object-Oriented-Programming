#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>
using namespace std;

enum Type{PERSONALITY = 1, HOLDING, FOLLOWER, ITEM};

class Card {
protected:
    string Name;
    int Cost;
    bool isTapped;
public:
    int getCost();
    string getName();
    bool Tapped();
    void Tap();
    void unTap();
    virtual void print() = 0;
};

class GreenCard : public Card {
protected:
    int AttackBonus;
    int DefenseBonus;
    int MinimumHonor;
    string CardText;
    int EffectBonus;
    int EffectCost;
public:
    virtual Type getType() = 0;
    int getAttackBonus();
    int getDefenseBonus();
    int getMinimumHonor();
    int getEffectBonus();
    int getEffectCost();
    string getCardText();

};

class BlackCard : public Card {
protected:
    bool isRevealed;
public:
    virtual Type getType() = 0;
    bool Revealed();
    void Reveal();
};


#endif
