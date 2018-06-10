#pragma once

#include <iostream>

class Card
{
friend std::ostream& operator<<(std::ostream& out, const Card& c)
{
    out<<c.getRank()<<" "<<c.getSuit()<<"\n";
    return out;
}

friend std::istream& operator>>(std::istream& in, Card& c)
{
    char st[10];
    char rn[3];

    std::cout<<"Suit of card: "; in>>st;
    std::cout<<"Rank of card: "; in>>rn;

    c.setSuit(st);
    c.setRank(rn);
    return in;
}
public:
    Card(const char* suit = "Diamonds", const char* rrank = "7");
    Card& operator=(const Card&);
    ~Card();

    void setSuit(const char* st);
    void setRank(const char* rn);

    const char* getSuit() const {return suit;}
    const char* getRank() const {return rrank;}

    int getCardSuit();
    int getCardRank();

    bool areTheSame(const Card&) const;

private:
    char* suit; ///Diamonds, Clubs, Spades, Hearts
    char* rrank; ///7,8,9,10,J,Q,K,A
};
