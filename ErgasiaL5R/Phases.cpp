#include "Phases.h"
int N=2;

void Gameplay(Player *player){
    cout << "THE GAME HAS STARTED!!" << endl;

    while(true){
        cout << "---------------------------------------------------------------" << endl;
        startingPhase(player);
        cout << "---------------------------------------------------------------" << endl;
        equipPhase(player);
        cout << "---------------------------------------------------------------" << endl;
        if(battlePhase(player))               //function returns true if the game is over
            break;                            //and so the loop breaks
        cout << "---------------------------------------------------------------" << endl;
        economyPhase(player);
        cout << "---------------------------------------------------------------" << endl;
        endingPhase(player);
    }
}


void startingPhase(Player *player) {
    for(int i=0; i<N; i++) {
        cout << "---------------------------------------------------------------" << endl;
        cout << "---Player" << i+1 << " Starting Phase! " << endl;
        player[i].untapEverything();
        player[i].drawFateCard();
        player[i].revealProvinces();
        player[i].printHand();
        player[i].printProvinces();
        cout << "Press Enter to Continue";
        cin.ignore();
    }
}

void equipPhase(Player *player){
    for(int i=0; i<N; i++) {
        cout << "---------------------------------------------------------------" << endl;
        cout << "---Player " << i+1 << " Equip Phase! " << endl;
        player[i].SetFatePoints();
        //At the start of Each Equip Phase: Player Fate Points = sum of all Holdings' Harvest + the StrongHold's Harvest
        cout << "Player has " << player[i].getFatePoints() << " available fate points" << endl;
        player[i].printArmy();
        cout << endl;
        player[i].printHand();
        cout << endl;
        if (player[i].HasArmy()) {
            while (true) {
                cout << "Playing as Player " << i+1 << ":" << endl;
                cout << "Would you like to equip a Personality with a card from your hand?(input 1 for yes, 0 for no)"
                     << endl;
                int a;
                cin >> a;
                while (a!=0 && a!=1){
                    cout << "Invalid input: Input 1 or 0" << endl;
                    cin >> a;
                }
                if (!a)
                    break;
                player[i].EquipArmy();
                cout << "Player has " << player[i].getFatePoints() << " available Fate Points" << endl;
                player[i].printArmy();
                cout << endl;
                player[i].printHand();
                cout << endl;
            }
        } else {
            cout << "Player " << i+1 << " has no Army and thus his Equip Phase is skipped!" << endl;
        }
        cout << "Press Enter to Continue";
        cin.ignore();
    }
}

bool battlePhase(Player *player) {
    for (int i = 0; i < N; i++) {
        cout << "---------------------------------------------------------------" << endl;

        cout << "---Battle Phase! " << endl;
        for (int j = 0; j < N; j++) {           //Printing all players' armies and provinces
            cout << "--Player " << j + 1 << ": " << endl;
            player[j].printArmy();
            cout << endl;
            player[j].printProvinces();
            cout << endl;
        }

        if (player[i].HasArmy()) {
            cout << "Playing as Player " << i + 1 << ", would you like to initiate an Attack?(input 1 for yes, 0 for no)" << endl;
            int a;
            cin >> a;
            while (a!=0 && a!=1){
                cout << "Invalid input: Input 1 or 0" << endl;
                cin >> a;
            }

            if(!a)
                continue;
            else{
                cout << "Which player would you like to initiate an Attack against?" << endl;
                cout << "Input number from available Player(s): ";
                int j;
                for(j = 0; j < N; j++){
                    if(j!=i)
                        cout << j+1 << " ";
                }
                cout << endl;
                cin >> a;
                while (a<1 && a>j+1){
                    cout << "Invalid input, try again:" << endl;
                    cin >> a;
                }
                player[i].Attack(player[a-1]);
            }

            if(CheckWinningCondition(player)){
                cout << "GAME OVER!" << endl;
                return true;
            }
        } else {
            cout << "Player " << i+1 << " has no Army and thus his Battle Phase is skipped!" << endl;
        }
        cout << "Press Enter to Continue";
        cin.ignore();
    }
    return false;
}

void economyPhase(Player *player){
    cout << "---------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++) {
        cout << "---Player" << i+1 << " Economy Phase! " << endl;
        cout << "Player has " << player[i].getFatePoints() << " available fate points" << endl;
        player[i].printArmy();
        cout << endl;
        player[i].printHoldings();
        cout << endl;
        player[i].printProvinces();
        cout << endl;

        while (true) {
            cout << "Playing as Player " << i+1 << ":" << endl;
            cout << "Would you like to buy from your Provinces?(input 1 for yes, 0 for no)"
                 << endl;
            int a;
            cin >> a;
            while (a!=0 && a!=1){
                cout << "Invalid input: Input 1 or 0" << endl;
                cin >> a;
            }
            if (!a)
                break;
            player[i].BuyProvinces();
            cout << "Player has " << player[i].getFatePoints() << " available fate points" << endl;
            player[i].printArmy();
            cout << endl;
            player[i].printHoldings();
            cout << endl;
            player[i].printProvinces();
            cout << endl;
        }

        cout << "Press Enter to Continue";
        cin.ignore();
    }
}

void endingPhase(Player *player){
    cout << "---------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++) {
        cout << "---Player " << i + 1 << " Ending Phase! " << endl;
        player[i].DiscardSurplusCards();
        cout << "Player has " << player[i].getFatePoints() << " available fate points" << endl;
        cout << "Player has " << player[i].getHonor() << " Honor" << endl;
        player[i].printHand();
        cout << endl;
        player[i].printArmy();
        cout << endl;
        player[i].printProvinces();
        cout << endl;
        player[i].printHoldings();
        cout << endl;

        cout << "Press Enter to Continue";
        cin.ignore();
    }
}

bool CheckWinningCondition(Player* player){
    int a=0;                //counter for players who still have Provinces
    int Winner;
    for(int i = 0; i<N; i++){
        if(player[i].HasProvinces()){
            a++;
            Winner = i+1;
        }
    }
    if(a==1) {
        cout << "Player " << Winner << " is the Winner!" << endl;
        return true;
    }else if(a==0){
        cout  << "It's a tie. No one has any Provinces left" << endl;
        return true;
    }
    else
        return false;
}
