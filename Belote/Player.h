#pragma once

#include "Card.h"
#include "Game.h"

class Game;

class Player
{
friend std::ostream& operator<<(std::ostream& out, const Player& c)
{
    for(int i=0;i<c.getCount();++i)
        out<<c.playerDeck[i];
    return out;
}
public:
    Player();
    ~Player();

    const char* getType() const {return type;}
    int getCount() const {return count;}
    int getPoints() const {return points;}

    void setType(const char* tp = nullptr);
    void setPoints(int);

    void firstDeal(int**);
    void secondDeal(int**);
    void thirdDeal(int**);

    bool isCardInDeck(const Card&);
    bool doYouHaveThatSuit(const char*);

    void remove(const Card&);

private:
    Card* playerDeck;
    char* type;
    int count;
    int points;

    void Deal(int n, int beg, int** cards);
};
