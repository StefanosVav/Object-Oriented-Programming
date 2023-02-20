#ifndef FOLLOWER_H
#define FOLLOWER_H

#include "Card.h"

class Follower : public GreenCard {
public:
    Type getType();
};

class Footsoldier : public Follower{
public:
    Footsoldier(string);
    void print();
};

class Archer : public Follower{
public:
    Archer(string);
    void print();
};

class Cavalry : public Follower{
public:
    Cavalry(string);
    void print();
};

class Bushido : public Follower{
public:
    Bushido(string);
    void print();
};

class Sieger : public Follower{
public:
    Sieger(string);
    void print();
};

class Atakebune : public Follower{
public:
    Atakebune(string);
    void print();
};


#endif
