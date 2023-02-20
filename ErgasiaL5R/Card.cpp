#include "Card.h"

int Card::getCost() {return Cost;}
string Card::getName() {return Name;}
bool Card::Tapped() {return isTapped;}
void Card::Tap() {isTapped = true;}
void Card::unTap() {isTapped = false;}

int GreenCard::getMinimumHonor() {return MinimumHonor;}
int GreenCard::getEffectCost() {return EffectCost;}
int GreenCard::getEffectBonus() {return EffectBonus;}
int GreenCard::getDefenseBonus() {return DefenseBonus;}
string GreenCard::getCardText() {return CardText;}
int GreenCard::getAttackBonus() {return AttackBonus;}

bool BlackCard::Revealed() {return isRevealed;}
void BlackCard::Reveal() {
    isRevealed = true;
}
