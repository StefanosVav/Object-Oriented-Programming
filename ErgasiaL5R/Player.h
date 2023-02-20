#ifndef PLAYER_H
#define PLAYER_H

#include <list>
#include "Holding.h"
#include "Personality.h"
#include "DeckBuilder.h"

class Player {
    DeckBuilder d;
    list<GreenCard*>* fate;
    list<BlackCard*>* dynasty;

    GreenCard **Hand;
    StrongHold SH;
    BlackCard **Provinces;
    Holding **holdings;
    Personality **army;

    int FatePoints;
    int HonorPoints;

public:
    Player();
    ~Player();
    void untapEverything();
    void drawFateCard();
    void revealProvinces();

    void printHand();
    void printProvinces();
    void printArmy();
    void printHoldings();
    void PrintStatistics();
    void SetFatePoints();
    int getFatePoints();
    int getHonor();

    bool HasProvinces();
    bool HasArmy();
    void Attack(Player &);
    void EquipArmy();
    void BuyProvinces();
    void DiscardSurplusCards();

    //void printfatedeck();
    //void printdynastydeck();
};


#endif
