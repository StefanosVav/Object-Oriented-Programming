#include "Player.h"
#include "DeckBuilder.h"

Player::Player() {

    dynasty = d.createDynastyDeck();    //create the dynasty deck
    fate = d.createFateDeck();          //create the fate deck
    d.deckShuffler(dynasty);
    d.deckShuffler(fate);               //shuffle them
    Provinces = new BlackCard*[4];      //initialize provinces
    for(int i = 0; i<4; i++){
        Provinces[i] = dynasty->front();//get the top card from the dynasty deck and make it a province
        dynasty->pop_front();           //the card is drawn from the dynasty deck so we remove it
    }
    holdings = new Holding*[10];        //initialize the holdings area
    for(int i = 0; i<10; i++){
        holdings[i] = NULL;
    }
    army = new Personality*[10];        //initialize the army(personalities) area
    for(int i = 0; i<10; i++){
        army[i] = NULL;
    }
    Hand = new GreenCard*[7];           //initialize the player's hand
    for(int i = 0; i<4; i++){
        Hand[i] = fate->front();        //draw 4 cards from the fate deck for the starting hand
        fate->pop_front();
    }
    for(int i = 4; i<7; i++){
        Hand[i] = NULL;
    }
    HonorPoints = SH.getHonor();
}

Player::~Player() {
    for(int i = 0; i<4; i++){
        delete Provinces[i];
    }
    delete[] Provinces;

    for(int i = 0; i<10; i++){
        delete holdings[i];
    }
    delete[] holdings;

    for(int i = 0; i<10; i++){
        delete army[i];
    }
    delete[] army;

    for(int i = 0; i<7; i++){
        delete Hand[i];
    }
    delete[] Hand;
}

int Player::getFatePoints() {
    return FatePoints;
}

void Player::SetFatePoints() {
    FatePoints = SH.getHarvestValue();
    for(int i = 0; i<10; i++){
        if(holdings[i]==NULL)
            break;
        FatePoints += holdings[i]->getHarvestValue();
    }
}

int Player::getHonor() {return HonorPoints;}

void Player::untapEverything() {
    for(int i = 0; i<10; i++){
        if(holdings[i]==NULL)
            break;
        holdings[i]->unTap();           //untap the holdings
    }
    for(int i = 0; i<10; i++){
        if(army[i]==NULL)
            break;
        army[i]->unTap();               //untap the personalities
    }
}

void Player::drawFateCard() {
    int i = 0;
    while(Hand[i]!=NULL){
        if(i == 6){
            cout << "Can't have more than 7 cards in your hand!" << endl;
            return;
        }
        i++;
    }
    Hand[i] = fate->front();        //draw the top card from the fate deck
    fate->pop_front();              //the card is drawn from the fate deck so we remove it
}

void Player::revealProvinces() {
    for(int i = 0; i<4; i++){
        if(Provinces[i]==NULL)
            break;
        Provinces[i]->Reveal();     //set is revealed to true
    }
}

void Player::printHand() {
    cout << "Player Hand: " << endl;
    for(int i = 0; i<6; i++){
        if(Hand[i] == NULL) {
            if(i==0)
                cout << "Empty Hand!" << endl;
            break;
        }
        cout << i << ": ";
        Hand[i]->print();
    }
}

void Player::printProvinces() {
    cout << "Player Provinces: " << endl;
    for(int i = 0; i<4; i++){

        if(Provinces[i] == NULL) {
            if(i==0)
                cout << "No provinces left!" << endl;
            break;
        }else {
            if (Provinces[i]->Revealed()) {
                cout << i << ": ";
                Provinces[i]->print();
            } else {
                cout << "Province no." << i << " not Revealed" << endl;
            }
        }
    }
}

void Player::printArmy() {
    cout << "Player Army: " << endl;
    for(int i = 0; i<10; i++){
        if(army[i] == NULL) {
            if(i==0)
                cout << "Player has no army!" << endl;
            break;
        }
        cout << i << ": ";
        army[i]->print();
    }
}

void Player::printHoldings() {
    cout << "Player Holdings: " << endl;
    for(int i = 0; i<10; i++){
        if(holdings[i] == NULL) {
            if(i==0)
                cout << "Player has no holdings!" << endl;
            break;
        }
        cout << i << ": ";
        holdings[i]->print();
    }
}

void Player::PrintStatistics() {
    printHand();
    printProvinces();
    printArmy();
    cout << "Player has " << FatePoints << " Fate points" << endl;
    cout << "Player has " << HonorPoints << " Honor" << endl;
}

bool Player::HasProvinces() {
    return Provinces[0] != NULL;
}

bool Player::HasArmy() {
    return army[0] != NULL;
}

void Player::Attack(Player &player) {
    int a = 0, b = 0, p = 0, s, TAP = 0, TDP = 0;
    //a=population of attacking army, b=population of defending army
    //p=population of defender's provinces, s=no. of province getting attacked
    //TAP=total attack points, TDP=total defense points
    int attackers[10];      //holding selected attackers
    for (int i = 0; i < 10; i++) {
        attackers[i] = -1;
    }
    int defenders[10];      //holding selected defenders
    for (int i = 0; i < 10; i++) {
        defenders[i] = -1;
    }

    while (player.Provinces[p] != NULL) {
        p++;
    }
    p--;
    cout << "Playing as the attacker, pick an enemy province to attack: 0-" << p << endl;
    cin >> s;
    while (s < 0 || s > p) {
        cout << "The number you picked is not valid, try again: " << endl;
        cin >> s;
    }
    cout << "You picked province no." << s << ":" << player.Provinces[s]->getName() << endl;

    while (army[a] != NULL) {
        a++;
    }
    a--;

    for (int i = 0; i < 10; i++) {                      //loop to set attackers
        cout << "Pick an attacker from your army: 0-" << a << ". If you're done input -1" << endl;
        cin >> attackers[i];
        if (attackers[0] == -1) {                       //no attackers were selected
            cout << "Attack canceled" << endl;
            return;
        } else if (attackers[i] == -1) {                //done selecting attackers
            break;
        }
        while (attackers[i] < 0 || attackers[i] > a) {
            cout << "The number you picked is not valid, try again: " << endl;
            cin >> attackers[i];
        }
        for (int j = 0; j < i; j++) {
            if (attackers[j] == attackers[i]) {     //if an attacker is picked again
                cout << "This attacker is already picked, try again" << endl;
                attackers[i] = -1;
                i--;                            //run the loop to set attackers with 'i' being the same as before
                break;
            }
        }
        cout << "You have picked Attacker no." << attackers[i] << ": " << army[attackers[i]]->getName() << endl;
    }

    for (int i = 0; i < 10; i++) {
        if (attackers[i] != -1) {
            TAP += army[attackers[i]]->getTotalAttack();
        } else
            break;
    }

    cout << "Attackers set -> Total Attack Points: " << TAP << endl;
    cout << "(These points include the follower-item bonuses)" << endl;
    cout << endl;

    //for the defender
    if (player.HasArmy()) {
        while (player.army[a] != NULL) {
            a++;
        }
        a--;

        cout << "Playing as the Defender" << endl;
        for (int i = 0; i < 10; i++) {                      //loop to set defenders
            cout << "Pick a defender from your army: 0-" << a << ". If you're done input -1" << endl;
            cin >> defenders[i];
            if (defenders[0] == -1) {                       //no defenders were selected
                cout << "Selected not to defend" << endl;
                break;
            } else if (defenders[i] == -1) {                 //done selecting defenders
                break;
            }
            while (defenders[i] < 0 || defenders[i] > a) {
                cout << "The number you picked is not valid, try again: " << endl;
                cin >> defenders[i];
            }
            for (int j = 0; j < i; j++) {
                if (defenders[j] == defenders[i]) {     //if a defender is picked again
                    cout << "This defender is already picked, try again" << endl;
                    defenders[i] = -1;
                    i--;                                //run the loop to set defenders with 'i' being the same as before
                    break;
                }
            }
            cout << "You have picked Attacker no." << defenders[i] << ": " << player.army[defenders[i]]->getName()
                 << endl;
        }

        for (int i = 0; i < 10; i++) {
            if (defenders[i] != -1) {
                TDP += player.army[defenders[i]]->getTotalDefense();
            } else
                break;
        }

        cout << "Defenders set -> Total Defense Points: " << TDP << endl;
        cout << "(These points include the follower-item bonuses)" << endl;
    } else {
        cout << "Defender has no army and thus can't Defend the Attack!" << endl;
    }

    cout << "---------------------------------------------------------------" << endl << "BATTLE STARTS!" << endl;
    cout << "Total Attack Points = " << TAP << endl;
    cout << "Total Defense Points = " << TDP << endl;

    if ((TAP - TDP) > player.SH.getInitialDefense()) {
        cout << "The attack is succesful!" << endl;
        cout << "Province " << player.Provinces[s]->getName() << " destroyed!" << endl;
        delete player.Provinces[s];
        for (int j = s; j < 3; j++) {
            player.Provinces[j] = player.Provinces[j + 1];
        }
        player.Provinces[3] = NULL;

        cout << "Participating Defenders killed!" << endl;
        for (int i = 0; i < 10; i++) {
            if (defenders[i] != -1) {
                delete player.army[defenders[i]];
                for (int j = defenders[i]; j < 9; j++) {
                    player.army[j] = player.army[j + 1];
                }
                player.army[9] = NULL;
            } else
                break;
        }
    } else if (TAP > TDP) {
        cout << "Attack won, but the Province was not destroyed" << endl;
        cout << "Participating Defenders killed!" << endl;
        for (int i = 0; i < 10; i++) {
            if (defenders[i] != -1) {
                delete player.army[defenders[i]];
                for (int j = defenders[i]; j < 9; j++) {
                    player.army[j] = player.army[j + 1];
                }
                player.army[9] = NULL;
            } else
                break;
        }
        cout << "Participating Attackers or Attacking Followers with ATK >=" << TAP - TDP << " also killed!" << endl;
        for (int i = 0; i < 10; i++) {
            if (attackers[i] != -1) {
                army[attackers[i]]->KillFollowers(TAP - TDP);
                if (army[attackers[i]]->getAttack() >= TAP - TDP) {
                    delete army[attackers[i]];
                    for (int j = attackers[i]; j < 9; j++) {
                        army[j] = army[j + 1];
                    }
                    army[9] = NULL;
                } else
                    army[attackers[i]]->Tap();                  //The attackers that survived the attack are tapped
            } else
                break;
        }

    } else if (TAP == TDP) {
        cout << "It's a tie. Every participating Personality is killed!" << endl;
        for (int i = 0; i < 10; i++) {
            if (defenders[i] != -1) {
                delete player.army[defenders[i]];
                for (int j = defenders[i]; j < 9; j++) {
                    player.army[j] = player.army[j + 1];
                }
                player.army[9] = NULL;
            } else
                break;
        }
        for (int i = 0; i < 10; i++) {
            if (attackers[i] != -1) {
                delete army[attackers[i]];
                for (int j = attackers[i]; j < 9; j++) {
                    army[j] = army[j + 1];
                }
                army[9] = NULL;
            } else
                break;
        }
    } else {
        cout << "Attack unsuccesful. Participating Attackers killed!" << endl;
        for (int i = 0; i < 10; i++) {
            if (attackers[i] != -1) {
                delete army[attackers[i]];
                for (int j = attackers[i]; j < 9; j++) {
                    army[j] = army[j + 1];
                }
                army[9] = NULL;
            } else
                break;
        }
        cout << "Participating Defenders or Defending Followers with ATK >=" << TDP - TAP << " also killed!"
             << endl;
        for (int i = 0; i < 10; i++) {
            if (attackers[i] != -1) {
                player.army[defenders[i]]->KillFollowers(TDP - TAP);
                if (player.army[defenders[i]]->getAttack() >= TDP - TAP) {
                    delete player.army[defenders[i]];
                    for (int j = defenders[i]; j < 9; j++) {
                        player.army[j] = player.army[j + 1];
                    }
                    player.army[9] = NULL;
                }
                else{
                    player.army[defenders[i]]->Tap();           //The defenders that survived the attack are tapped
                }
            } else
                break;
        }
    }
}


void Player::EquipArmy() {
    int i = 0, n, m;

    while (Hand[i] != NULL) {
        i++;
    }
    i--;
    cout << "Pick a number that represents the card in your hand you want to equip: (0-" << i << ")" << endl;
    cin >> n;
    while (n < 0 || n > i) {
        cout << "The number you picked is not valid, try again: " << endl;
        cin >> n;
    }
    cout << "You picked number " << n << ": " << Hand[n]->getName() << endl;

    i = 0;
    while (army[i] != NULL) {
        i++;
    }
    i--;
    cout << "Pick a number that represents the card in your army you want equipped: (0-" << i << ")" << endl;
    cin >> m;
    while (m < 0 || m > i) {
        cout << "The number you picked is not valid, try again: " << endl;
        cin >> m;
    }
    cout << "You picked number " << m << ": " << army[m]->getName() << endl;

    if (Hand[n]->getCost() <= FatePoints && Hand[n]->getMinimumHonor() <= army[m]->getHonor()) {

        if (Hand[n]->getType() == FOLLOWER) {
            if (army[m]->Equip(dynamic_cast<Follower *>(Hand[n]))) {
                cout << "Equipping " << Hand[n]->getName() << " to " << army[m]->getName() << endl;
                FatePoints = FatePoints - Hand[n]->getCost();
                for (int j = n; j < 6; j++) {
                    Hand[j] = Hand[j + 1];
                }
                Hand[6] = NULL;
            }
        } else if (Hand[n]->getType() == ITEM) {
            if (army[m]->Equip(dynamic_cast<Item *>(Hand[n]))) {
                cout << "Equipping " << Hand[n]->getName() << " to " << army[m]->getName() << endl;
                FatePoints = FatePoints - Hand[n]->getCost();
                for (int j = n; j < 6; j++) {
                    Hand[j] = Hand[j + 1];
                }
                Hand[6] = NULL;
            }
        }
    }else if(Hand[n]->getCost() <= FatePoints)
        cout << "The personality you picked does not have enough Honor!" << endl;
    else if(Hand[n]->getMinimumHonor() <= army[m]->getHonor())
        cout << "You don't have enough Fate Points for this purchase!" << endl;
    else
        cout << "You don't have enough Fate Points and the personality you picked does not have enough Honor!";
}

void Player::BuyProvinces() {
    int i = 0, n, m=0;

    while (Provinces[i] != NULL) {
        i++;
    }
    i--;
    while(true) {
        cout << "Pick a number that represents the Province you want to buy: (0-" << i << ")" << endl;
        cin >> n;
        while (n < 0 || n > i) {
            cout << "The number you picked is not valid, try again: " << endl;
            cin >> n;
        }
        if(Provinces[n]->Revealed()) {
            cout << "You picked number " << n << ": " << Provinces[n]->getName() << endl;
            break;
        }else {
            cout << "This Province is not Revealed. You can't pick it" << endl;
            cout << "If all your Provinces are not Revealed and you want to skip this Phase, input 0, else input anything:" << endl;
            int a;
            cin >> a;
            if (a == 0)
                return;
        }
    }

    if (Provinces[n]->getCost() <= FatePoints) {

        if (Provinces[n]->getType() == PERSONALITY) {
            while (army[m] != NULL) {
                m++;
            }
            cout << "Buying " << Provinces[n]->getName() << endl;
            FatePoints = FatePoints - Provinces[n]->getCost();
            army[m] = dynamic_cast<Personality *>(Provinces[n]);
            Provinces[n] = dynasty->front();
            dynasty->pop_front();

        }else if (Provinces[n]->getType() == HOLDING) {
            while (holdings[m] != NULL) {
                m++;
            }
            cout << "Buying " << Provinces[n]->getName() << endl;
            FatePoints = FatePoints - Provinces[n]->getCost();
            holdings[m] = dynamic_cast<Holding *>(Provinces[n]);
            Provinces[n] = dynasty->front();
            dynasty->pop_front();
        }
    }
    else
        cout << "You don't have enough Fate Points for this purchase!" << endl;
}

void Player::DiscardSurplusCards() {
    int i = 0;
    while(Hand[i]!=NULL){
        i++;
    }
    if(i>6){
        cout << "Deleting Surplus Card: " << Hand[i]->getName() << endl;
        for(i=6; i<7; i++){
            delete Hand[i];
            Hand[i] = NULL;
        }
    }
}


/*void Player::printdynastydeck() {
    vector<BlackCard *> vect;
    list<BlackCard *>::iterator it;
    for (it = dynasty->begin(); it != dynasty->end(); it++)
        vect.push_back(*it);

    int it2;
    for (it2 = 0; it2 != 10; it2++)
       vect[it2]->print();
}

void Player::printfatedeck() {
    vector<GreenCard *> vect;
    list<GreenCard *>::iterator it;
    for (it = fate->begin(); it != fate->end(); it++)
        vect.push_back(*it);

    int it2;
    for (it2 = 0; it2 != 10; it2++)
        vect[it2]->print();
}*/
