#include "Holding.h"

Type Holding::getType() {return HOLDING;}
int Holding::getHarvestValue() {return harvestValue;}

Plain::Plain(string a) {
    Cost         = 2;
    harvestValue = 2;
    Name         = a;
    isTapped     = false;
    isRevealed   = false;
}
void Plain::print() {
    cout << "Holding->Plain: " << Name << ", Cost = " << Cost << ", Harvest: " << harvestValue << endl;
}

Mine::Mine(string a) {
    UpperHolding = NULL;
    Cost         = 5;
    harvestValue = 3;
    Name         = a;
    isTapped     = false;
    isRevealed   = false;
}
void Mine::print() {
    cout << "Holding->Mine: " << Name << ", Cost = " << Cost << ", Harvest: " << harvestValue << endl;
}


GoldMine::GoldMine(string a) {
    UpperHolding = NULL;
    SubHolding = NULL;
    Cost         = 7;
    harvestValue = 5;
    Name         = a;
    isTapped     = false;
    isRevealed   = false;
}
void GoldMine::print() {
    cout << "Holding->GoldMine: " << Name << ", Cost = " << Cost << ", Harvest: " << harvestValue << endl;
}

CrystalMine::CrystalMine(string a) {
    SubHolding = NULL;
    Cost         = 12;
    harvestValue = 6;
    Name         = a;
    isTapped     = false;
    isRevealed   = false;
}
void CrystalMine::print() {
    cout << "Holding->CrystalMine: " << Name << ", Cost = " << Cost << ", Harvest: " << harvestValue << endl;
}

Farmland::Farmland(string a) {
    Cost         = 3;
    harvestValue = 4;
    Name         = a;
    isTapped     = false;
    isRevealed   = false;
}
void Farmland::print() {
    cout << "Holding->Farmland: " << Name << ", Cost = " << Cost << ", Harvest: " << harvestValue << endl;
}

GiftsandFavour::GiftsandFavour(string a)  {
    Cost         = 2;
    harvestValue = 2;
    Name         = a;
    isTapped     = false;
    isRevealed   = false;
}
void GiftsandFavour::print() {
    cout << "Holding->GiftsandFavour: " << Name << ", Cost = " << Cost << ", Harvest: " << harvestValue << endl;
}

StrongHold::StrongHold() {
    Honor          = 5;
    initialDefense = 5;
    harvestValue   = 5;
    isRevealed     = false;
    isTapped       = false;
}
void StrongHold::print() {
    cout << "StrongHold: " << Name << ", Cost = " << Cost << ", Money: " << harvestValue << ", In. Defense: " << initialDefense << endl;
}
Type StrongHold::getType() {return HOLDING;}
int StrongHold::getHonor() {return Honor;}
int StrongHold::getInitialDefense() {return initialDefense;}
