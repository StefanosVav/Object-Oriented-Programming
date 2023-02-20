#include "Item.h"

Type Item::getType() {return ITEM;}
int Item::getDurability() {return Durability;}

Katana::Katana(string a){
    Cost         = 0;
    AttackBonus  = 2;
    DefenseBonus = 0;
    MinimumHonor = 1;
    EffectBonus  = 1;
    EffectCost   = 2;
    Durability   = 3;
    Name         = a;
    CardText     = "Ability";
    isTapped     = false;
}
void Katana::print() {
    cout << "Item->Katana: " << Name << ", Cost = " << Cost << ", ATK+: " << AttackBonus << ", DEF+: " << DefenseBonus << ", MinHonor: " << MinimumHonor <<
    endl << "              EffectB: " << EffectBonus << ", EffectCost: " << EffectCost << ", Durability: " << Durability << ", Text: " << CardText << endl;
}

Spear::Spear(string a){
    Cost         = 0;
    AttackBonus  = 0;
    DefenseBonus = 2;
    MinimumHonor = 1;
    EffectBonus  = 1;
    EffectCost   = 2;
    Durability   = 3;
    Name         = a;
    CardText     = "Ability";
    isTapped     = false;
}
void Spear::print() {
    cout << "Item->Spear: " << Name << ", Cost = " << Cost << ", ATK+: " << AttackBonus << ", DEF+: " << DefenseBonus << ", MinHonor: " << MinimumHonor <<
    endl << "              EffectB: " << EffectBonus << ", EffectCost: " << EffectCost << ", Durability: " << Durability << ", Text: " << CardText << endl;
}

Bow::Bow(string a) {
    Cost         = 2;
    AttackBonus  = 2;
    DefenseBonus = 2;
    MinimumHonor = 2;
    EffectBonus  = 3;
    EffectCost   = 4;
    Durability   = 5;
    Name         = a;
    CardText     = "Ability";
    isTapped     = false;
}
void Bow::print() {
    cout << "Item->Bow: " << Name << ", Cost = " << Cost << ", ATK+: " << AttackBonus << ", DEF+: " << DefenseBonus << ", MinHonor: " << MinimumHonor <<
    endl << "              EffectB: " << EffectBonus << ", EffectCost: " << EffectCost << ", Durability: " << Durability << ", Text: " << CardText << endl;
}

Ninjato::Ninjato(string a) {
    Cost         = 4;
    AttackBonus  = 3;
    DefenseBonus = 3;
    MinimumHonor = 3;
    EffectBonus  = 2;
    EffectCost   = 2;
    Durability   = 4;
    Name         = a;
    CardText     = "Ability";
    isTapped     = false;
}
void Ninjato::print() {
    cout << "Item->Ninjato: " << Name << ", Cost = " << Cost << ", ATK+: " << AttackBonus << ", DEF+: " << DefenseBonus << ", MinHonor: " << MinimumHonor <<
    endl << "              EffectB: " << EffectBonus << ", EffectCost: " << EffectCost << ", Durability: " << Durability << ", Text: " << CardText << endl;
}

Wakizashi::Wakizashi(string a) {
    Cost         = 8;
    AttackBonus  = 5;
    DefenseBonus = 5;
    MinimumHonor = 3;
    EffectBonus  = 3;
    EffectCost   = 3;
    Durability   = 8;
    Name         = a;
    CardText     = "Ability";
    isTapped     = false;
}
void Wakizashi::print() {
    cout << "Item->Wakizashi: " << Name << ", Cost = " << Cost << ", ATK+: " << AttackBonus << ", DEF+: " << DefenseBonus << ", MinHonor: " << MinimumHonor <<
    endl << "              EffectB: " << EffectBonus << ", EffectCost: " << EffectCost << ", Durability: " << Durability << ", Text: " << CardText << endl;
}