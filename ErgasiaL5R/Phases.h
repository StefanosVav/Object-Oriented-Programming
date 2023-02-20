#ifndef PHASES_H
#define PHASES_H
#include "Player.h"
extern int N;

void Gameplay(Player*);

void startingPhase(Player*);
void equipPhase(Player*);
bool battlePhase(Player*);
void economyPhase(Player*);
void endingPhase(Player*);

bool CheckWinningCondition(Player*);  //returns the number of the winning player

#endif
