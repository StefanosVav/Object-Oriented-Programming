#ifndef ITEM_H
#define ITEM_H

#include "Card.h"

class Item : public GreenCard{
protected:
    int Durability;
    Type getType();
public:
    int getDurability();
};

class Katana : public Item{
public:
    Katana(string);
    void print();
};

class  Spear : public Item{
public:
    Spear(string);
    void print();
};

class Bow : public Item{
public:
    Bow(string);
    void print();
};

class Ninjato : public Item{
public:
    Ninjato(string);
    void print();
};

class Wakizashi : public Item{
public:
    Wakizashi(string);
    void print();
};


#endif
