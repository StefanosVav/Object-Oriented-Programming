#ifndef HOLDING_H
#define HOLDING_H

#include "Card.h"

class Holding : public BlackCard {
protected:
    int harvestValue;
public:
    Type getType();
    int getHarvestValue();
};

class Plain : public Holding {
public:
    Plain(string);
    void print();
};

class Mine : public Holding {
    Holding *UpperHolding;
public:
    Mine(string);
    void print();
};

class GoldMine : public Holding {
    Holding *UpperHolding;
    Holding *SubHolding;
public:
    GoldMine(string);
    void print();
};

class CrystalMine : public Holding {
    Holding *SubHolding;
public:
    CrystalMine(string);
    void print();
};

class Farmland : public Holding {
public:
    Farmland(string);
    void print();
};

class GiftsandFavour : public Holding {
public:
    GiftsandFavour(string);
    void print();
};

class StrongHold : public Holding {
    int Honor;
    int initialDefense;
public:
    StrongHold();
    Type getType();
    void print();
    int getInitialDefense();
    int getHonor();
};



#endif
