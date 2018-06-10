#include <cstring>

#include "Card.h"

void Card::setSuit(const char* st)
{
    if(!strcmp(st, "Diamonds") || !strcmp(st,"Clubs") || !strcmp(st, "Spades") || !strcmp(st, "Hearts"))
    {
        int sz = strlen(st) + 1;
        delete[] suit;
        suit = new char[sz];
        strcpy(suit, st);
    }
}

void Card::setRank(const char* rn)
{
    if(!strcmp(rn, "7") || !strcmp(rn, "8") || !strcmp(rn,"9") || !strcmp(rn, "10") || !strcmp(rn, "J") || !strcmp(rn,"Q") || !strcmp(rn, "K") || !strcmp(rn, "A"))
    {
        int sz = strlen(rn) + 1;
        delete[] rrank;
        rrank = new char[sz];
        strcpy(rrank, rn);
    }
}

Card::Card(const char* suit, const char* rrank): suit(nullptr), rrank(nullptr)
{
    setSuit(suit);
    setRank(rrank);
}

Card& Card::operator=(const Card& c)
{
    if(this!=&c)
    {
        setRank(c.getRank());
        setSuit(c.getSuit());
    }
    return *this;
}

Card::~Card()
{
    delete[] suit;
    delete[] rrank;
}

int Card::getCardSuit()
{
    if(!strcmp(this->getSuit(),"Diamonds")) return 0;
    if(!strcmp(this->getSuit(),"Clubs")) return 1;
    if(!strcmp(this->getSuit(),"Spades")) return 2;
    return 3;
}

int Card::getCardRank()
{
    if(!strcmp(this->getRank(),"7")) return 0;
    if(!strcmp(this->getRank(),"8")) return 1;
    if(!strcmp(this->getRank(),"9")) return 2;
    if(!strcmp(this->getRank(),"10")) return 3;
    if(!strcmp(this->getRank(),"J")) return 4;
    if(!strcmp(this->getRank(),"Q")) return 5;
    if(!strcmp(this->getRank(),"K")) return 6;
    return 7;
}

bool Card::areTheSame(const Card& c) const
{
    return (!strcmp(c.getRank(),this->getRank()) && !strcmp(c.getSuit(),this->getSuit()));
}
