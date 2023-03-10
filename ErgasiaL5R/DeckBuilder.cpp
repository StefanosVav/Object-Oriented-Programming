#include "DeckBuilder.h"
#include "Card.h"

using namespace std;

DeckBuilder::DeckBuilder()
{
    black = new list<BlackCard *>();
    green = new list<GreenCard *>();
}

DeckBuilder::~DeckBuilder()
{
    list<BlackCard *>::iterator it;
    list<GreenCard *>::iterator it2;
    for (it = black->begin(); it != black->end(); it++)
    {
        black->remove((*it));
        delete *it;
        it = black->begin();
    }
    for (it2 = green->begin(); it2 != green->end(); it++)
    {
        green->remove((*it2));
        delete *it2;
        it2 = green->begin();
    }
    delete black;
    delete green;
}

list<GreenCard *> *DeckBuilder::createFateDeck()
{
    int i;
    for (i = 0; i < NO_FOOTSOLDIER; i++)
        green->push_back(new Footsoldier("Peasants"));
    for (i = 0; i < NO_ARCHER; i++)
        green->push_back(new Archer("Elite Troops"));
    for (i = 0; i < NO_SIEGER; i++)
        green->push_back(new Sieger("Immortal Bushi"));
    for (i = 0; i < NO_CAVALRY; i++)
        green->push_back(new Cavalry("Unicorn Horses"));
    for (i = 0; i < NO_NAVAL; i++)
        green->push_back(new Atakebune("Yomi Ships"));
    for (i = 0; i < NO_BUSHIDO; i++)
        green->push_back(new Bushido("7 Samurai"));

    for (i = 0; i < NO_KATANA; i++)
        green->push_back(new Katana("Daijtso"));
    for (i = 0; i < NO_BOW; i++)
        green->push_back(new Bow("Yumi"));
    for (i = 0; i < NO_SPEAR; i++)
        green->push_back(new Spear("Kama"));
    for (i = 0; i < NO_NINJATO; i++)
        green->push_back(new Ninjato("Butterfly Dagger"));
    for (i = 0; i < NO_WAKIZASHI; i++)
        green->push_back(new Wakizashi("Kusanagi"));

    return green;
}

list<BlackCard *> *DeckBuilder::createDynastyDeck()
{
    int i;
    //Create Personalities
    //NO_DEFENSIVE 10
    for (i = 0; i < NO_DEFENSIVE; i++)
        black->push_back(new Defender("Footsoldiers"));
    //NO_ATTACKING 10
    for (i = 0; i < NO_ATTACKING; i++)
        black->push_back(new Attacker("Steadfast bushi"));
    //NO_SHOGUN	2
    black->push_back(new Shogun("Akodo Kaneka"));
    black->push_back(new Shogun("Isawa Shi en"));
    //NO_CHANCELLOR 2
    black->push_back(new Chancellor("Hida Shozen"));
    black->push_back(new Chancellor("Mirimuto Enishi"));
    //NO_CHAMPION 1
    black->push_back(new Champion("Hida Kisada"));
    //Create holdings
    for (i = 0; i < NO_PLAIN; i++)
        black->push_back(new Plain("Rice Fields"));
    for (i = 0; i < NO_FARMS; i++)
        black->push_back(new Farmland("Fish Farms"));
    for (i = 0; i < NO_MINE; i++)
        black->push_back(new Mine("Ashio Copper Mine"));
    for (i = 0; i < NO_GOLD_MINE; i++)
        black->push_back(new GoldMine("Konomai Gold Mine"));
    for (i = 0; i < NO_CRYSTAL_MINE; i++)
        black->push_back(new CrystalMine("Ichinokawa Crystal Mine"));
    for (i = 0; i < NO_SOLO; i++)
        black->push_back(new GiftsandFavour("Gifts and Favors"));

    return black;
}

void DeckBuilder::deckShuffler(list<BlackCard *> *b)
{
    vector<BlackCard *> vect;
    list<BlackCard *>::iterator it;
    for (it = b->begin(); it != b->end(); it++)
        vect.push_back((*it));

    random_shuffle(vect.begin(), vect.end());

    b->clear();

    vector<BlackCard *>::iterator it2;
    for (it2 = vect.begin(); it2 != vect.end(); it2++)
        b->push_back((*it2));
}

void DeckBuilder::deckShuffler(list<GreenCard *> *g)
{
    vector<GreenCard *> vect;
    list<GreenCard *>::iterator it;
    for (it = g->begin(); it != g->end(); it++)
        vect.push_back((*it));

    random_shuffle(vect.begin(), vect.end());

    g->clear();

    vector<GreenCard *>::iterator it2;
    for (it2 = vect.begin(); it2 != vect.end(); it2++)
        g->push_back((*it2));
}
