#include <cstring>
#include <cstdlib>

#include "Player.h"
#include "Game.h"

void Player::setType(const char* tp)
{
    if(!strcmp(tp, "No") || !strcmp(tp, "All") || !strcmp(tp, "Diamonds") || !strcmp(tp,"Clubs") || !strcmp(tp, "Spades") || !strcmp(tp, "Hearts") || !strcmp(tp, "Pass") || !strcmp(tp, "Double") || !strcmp(tp, "Redouble"))
    {
        int sz = strlen(tp) + 1;
        delete[] type;
        type = new char[sz];
        strcpy(type,tp);
    }
}

void Player::setPoints(int p)
{
    points = p;
}

Player::Player()
{
    playerDeck = new Card[8];
    count = 0;
    points = 0;
}

Player::~Player()
{
    if(count>0) delete[] playerDeck;
}

void Player::Deal(int n, int beg,int** cards)
{
    int f=0;
    for(int i=0; i<n;++i)
    {
        f=0;
        while(!f)
        {
            int fst = 0;
            int snd = 0;

            fst = rand() % 4;
            snd = rand() % 8;

            if(cards[fst][snd])
            {
                if(fst == 0) playerDeck[i+beg].setSuit("Diamonds");
                else if(fst == 1) playerDeck[i+beg].setSuit("Clubs");
                else if(fst == 2) playerDeck[i+beg].setSuit("Spades");
                else playerDeck[i+beg].setSuit("Hearts");

                if(snd == 0) playerDeck[i+beg].setRank("7");
                else if(snd == 1) playerDeck[i+beg].setRank("8");
                else if(snd == 2) playerDeck[i+beg].setRank("9");
                else if(snd == 3) playerDeck[i+beg].setRank("10");
                else if(snd == 4) playerDeck[i+beg].setRank("J");
                else if(snd == 5) playerDeck[i+beg].setRank("Q");
                else if(snd == 6) playerDeck[i+beg].setRank("K");
                else playerDeck[i+beg].setRank("A");

                cards[fst][snd] = 0;
                f=1;
            }
        }
    }
}

void Player::firstDeal(int** cards)
{
    Deal(3,0,cards);
    count = 3;
}

void Player::secondDeal(int** cards)
{
    Deal(2,3,cards);
    count = 5;
}

void Player::thirdDeal(int** cards)
{
    Deal(3,5,cards);
    count = 8;
}

void Player::remove(const Card& c)
{
    for(int i=0;i<getCount();++i)
    {
        if(c.areTheSame(playerDeck[i]))
        {
            playerDeck[i] = Card();
        }
    }
    count--;
}

bool Player::isCardInDeck(const Card& c)
{
    for(int i=0;i<8;++i)
    {
        if(c.areTheSame(this->playerDeck[i])) return true;
    }
    return false;
}

bool Player::doYouHaveThatSuit(const char* s)
{
    for(int i=0;i<getCount();++i)
    {
        if (!strcmp(this->playerDeck[i].getSuit(),s)) return true;
    }
    return false;
}
