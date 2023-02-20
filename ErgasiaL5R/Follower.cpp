#include "Follower.h"

Type Follower::getType() {return FOLLOWER;}

Footsoldier::Footsoldier(string a)
{
    Cost         = 0;
    AttackBonus  = 2;
    DefenseBonus = 0;
    MinimumHonor = 1;
    EffectBonus  = 1;
    EffectCost   = 2;
    Name         = a;
    CardText     = "Ability";
    isTapped     = false;
}
void Footsoldier::print() {
    cout << "Follower->Footsoldier: " << Name << ", Cost = " << Cost << ", ATK+: " << AttackBonus << ", DEF+: " << DefenseBonus << ", MinHonor: " <<
    MinimumHonor << "," << endl << "                        EffectB: " << EffectBonus << ", EffectCost: " << EffectCost << ", Text: " << CardText << endl;
}

Archer::Archer(string a) {
    Cost         = 0;
    AttackBonus  = 0;
    DefenseBonus = 2;
    MinimumHonor = 1;
    EffectBonus  = 1;
    EffectCost   = 2;
    Name         = a;
    CardText     = "Ability";
    isTapped     = false;
}
void Archer::print() {
    cout << "Follower->Archer: " << Name << ", Cost = " << Cost << ", ATK+: " << AttackBonus << ", DEF+: " << DefenseBonus << ", MinHonor: " <<
    MinimumHonor << "," << endl << "                   EffectB: " << EffectBonus << ", EffectCost: " << EffectCost << ", Text: " << CardText << endl;
}

Cavalry::Cavalry(string a) {
    Cost         = 3;
    AttackBonus  = 4;
    DefenseBonus = 2;
    MinimumHonor = 3;
    EffectBonus  = 3;
    EffectCost   = 4;
    Name         = a;
    CardText     = "Ability";
    isTapped     = false;
}
void Cavalry::print() {
    cout << "Follower->Cavalry: " << Name << ", Cost = " << Cost << ", ATK+: " << AttackBonus << ", DEF+: " << DefenseBonus << ", MinHonor: " <<
    MinimumHonor << "," << endl << "                    EffectB: " << EffectBonus << ", EffectCost: " << EffectCost << ", Text: " << CardText << endl;
}

Bushido::Bushido(string a){
    Cost         = 8;
    AttackBonus  = 8;
    DefenseBonus = 8;
    MinimumHonor = 6;
    EffectBonus  = 3;
    EffectCost   = 8;
    Name         = a;
    CardText     = "Ability";
    isTapped     = false;
}
void Bushido::print() {
    cout << "Follower->Bushido: " << Name << ", Cost = " << Cost << ", ATK+: " << AttackBonus << ", DEF+: " << DefenseBonus << ", MinHonor: " <<
    MinimumHonor << "," << endl << "                    EffectB: " << EffectBonus << ", EffectCost: " << EffectCost << ", Text: " << CardText << endl;
}

Sieger::Sieger(string a) {
    Cost         = 5;
    AttackBonus  = 3;
    DefenseBonus = 3;
    MinimumHonor = 2;
    EffectBonus  = 2;
    EffectCost   = 3;
    Name         = a;
    CardText     = "Ability";
    isTapped     = false;
}
void Sieger::print() {
    cout << "Follower->Sieger: " << Name << ", Cost = " << Cost << ", ATK+: " << AttackBonus << ", DEF+: " << DefenseBonus << ", MinHonor: " <<
    MinimumHonor << "," << endl << "                   EffectB: " << EffectBonus << ", EffectCost: " << EffectCost << ", Text: " << CardText << endl;
}

Atakebune::Atakebune(string a) {
    Cost         = 3;
    AttackBonus  = 2;
    DefenseBonus = 4;
    MinimumHonor = 3;
    EffectBonus  = 3;
    EffectCost   = 4;
    Name         = a;
    CardText     = "Ability";
    isTapped     = false;
}
void Atakebune::print() {
    cout << "Follower->Atakebune: " << Name << ", Cost = " << Cost << ", ATK+: " << AttackBonus << ", DEF+: " << DefenseBonus << ", MinHonor: " <<
    MinimumHonor << "," << endl << "                    EffectB: " << EffectBonus << ", EffectCost: " << EffectCost << ", Text: " << CardText << endl;
}