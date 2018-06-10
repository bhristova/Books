#include <cstring>
#include "Game.h"

Game::Game(): type(nullptr)
{
    players = new Player*;
    for(int i=0;i<4;++i)
        players[i] = new Player;

    deckPoints = new int*[4];
    for(int i=0;i<4;++i)
        deckPoints[i] = new int[8];

    cards = new int*[4];
    for(int i=0;i<4;++i)
    {
        cards[i] = new int[8];
        for(int j=0;j<8;++j)
            cards[i][j] = 1;
    }
}

void Game::setGameType()
{
    bool f=0;
    int br=0, g=0;
    char t[4][8];
    while(!f)
    {
        std::cout<<"Player #1, input type of game: "; std::cin>>t[0];
        std::cout<<"Player #2, input type of game: "; std::cin>>t[1];
        std::cout<<"Player #3, input type of game: "; std::cin>>t[2];
        std::cout<<"Player #4, input type of game: "; std::cin>>t[3];

        for(int i=0;i<4;++i)
        {
            if(!strcmp(t[i],"Pass")) br++;
            else g=i;
        }
        if(br==3) {f = 1; std::cout<<"You are playing "<<t[g]<<"!\n";}
        br=0;
        std::cout<<"\n";
    }
    bidder = g;
    int sz = strlen(t[g]) + 1;
    delete[] type;
    type = new char[sz];
    strcpy(type,t[g]);
    setCardPoints();
}

void Game::setCardPoints()
{
    int colour=0;
    bool f=0;
    for(int i=0;i<4;++i)
    {
        deckPoints[i][0] = 0; /// 7
        deckPoints[i][1] = 0; /// 8
        deckPoints[i][3] = 10; /// 10
        deckPoints[i][5] = 3; /// Q
        deckPoints[i][6] = 4; /// K
        deckPoints[i][7] = 11; /// A
    }

    if(!strcmp(getGameType(), "No"))
    {
        for(int i=0;i<4;++i)
        {
            deckPoints[i][2] = 0; /// 9
            deckPoints[i][4] = 2; /// J
        }
    }

    else if(!strcmp(getGameType(), "All"))
    {
        for(int i=0;i<4;++i)
        {
            deckPoints[i][2] = 14; /// 9
            deckPoints[i][4] = 20; /// J
        }
    }
    else if(!strcmp(getGameType(), "Diamonds")) {colour = 0; f=1;}
    else if(!strcmp(getGameType(), "Clubs")) {colour = 1; f=1;}
    else if(!strcmp(getGameType(), "Spades")) {colour = 2; f=1;}
    else {colour = 3; f=1;} ///Hearts

    if(f)
    {
        for(int i=0;i<3;++i)
        {
            deckPoints[i][2] = 0; /// 9
            deckPoints[i][4] = 2; /// J
        }
        deckPoints[colour][2] = 14;
        deckPoints[colour][4] = 20;
    }
}

bool Game::isCardFree(int a, int b)
{
    return cards[a][b];
}

int findMax(int a, int b, int c, int d)
{
    if(a>=b && a>=c && a>=d) return 0;
    if(b>=a && b>=c && b>=d) return 1;
    if(c>=a && c>=b && c>=d) return 2;
    return 3;
}

void Game::gameOn()
{
    std::cout<<"FIRST DEAL:\n";
    for(int i=0;i<4;++i)
        {(*players[i]).firstDeal(cards); std::cout<<"Player #"<<i<<":  "<<(*players[i])<<"\n";}

    std::cout<<"\nSECOND DEAL:\n";
    for(int i=0;i<4;++i)
        {(*players[i]).secondDeal(cards); std::cout<<"Player #"<<i<<":  "<<(*players[i])<<"\n";}

    setGameType();

    std::cout<<"\nTHIRD DEAL:\n";
    for(int i=0;i<4;++i)
        {(*players[i]).thirdDeal(cards); std::cout<<"Player #"<<i+1<<":  "<<(*players[i])<<"\n";}

    int pl=0;
    if(getBidder()==3) pl=game(0);
    else pl=game(getBidder()+1);

    while((*players[0]).getCount() && (*players[1]).getCount() && (*players[2]).getCount() && (*players[3]).getCount())
    {
        int pl1 = pl;
        pl = game(pl1);
    }

    int ptsTeamOne = (*players[0]).getPoints() + (*players[2]).getPoints();
    int ptsTeamTwo = (*players[1]).getPoints() + (*players[3]).getPoints();

    if(ptsTeamOne > ptsTeamTwo && getBidder()==0 || getBidder()==2) std::cout<<"Congratulations, team One! You won your game! Your points are "<<ptsTeamOne<<"\n";
    else if(ptsTeamTwo > ptsTeamOne && getBidder()==1 || getBidder()==3) std::cout<<"Congratulations, team Two! You won your game! Your points are "<<ptsTeamTwo<<"\n";
    else if(ptsTeamTwo > ptsTeamOne && getBidder()==0 || getBidder()==2) std::cout<<"Sorry, team One! Team Two won your game with "<<ptsTeamTwo<<" points.\n";
    else std::cout<<"Sorry, team Two! Team One won your game with "<<ptsTeamOne<<" points.\n";
}

int Game::game(int j)
{
    Card* cards = new Card[4];
    for(int i=0;i<4;++i)
    {
        int m=i+j;
        if(i+j == 4) m=0;
        if(i+j == 5) m=1;
        if(i+j == 6) m=2;
        std::cout<<"Player #"<<m+1<<", throw a card: ";
        std::cin>>cards[m];
        while(!(*players[m]).isCardInDeck(cards[m]))
            {
                std::cout<<"This card is not in your deck! Throw another one!\n";
                std::cin>>cards[m];
            }
        char startType[10];
        if(i==0) strcpy(startType, cards[m].getSuit());

        if(i!=0)
        {
            while(strcmp(cards[m].getSuit(), startType) && (*players[m]).doYouHaveThatSuit(startType))
            {
                std::cout<<"You must chose a card with the leading suit! Throw another one: ";
                std::cin>>cards[m];
            }
        }
        std::cout<<"\n";
    }

    int winner = findMax(deckPoints[cards[0].getCardSuit()][cards[0].getCardRank()],
                         deckPoints[cards[1].getCardSuit()][cards[1].getCardRank()],
                         deckPoints[cards[2].getCardSuit()][cards[2].getCardRank()],
                         deckPoints[cards[3].getCardSuit()][cards[3].getCardRank()]);

    int points = deckPoints[cards[0].getCardSuit()][cards[0].getCardRank()] +
                 deckPoints[cards[1].getCardSuit()][cards[1].getCardRank()] +
                 deckPoints[cards[2].getCardSuit()][cards[2].getCardRank()] +
                 deckPoints[cards[3].getCardSuit()][cards[3].getCardRank()];

    (*players[winner]).setPoints((*players[winner]).getPoints() + points);

    (*players[0]).remove(cards[0]);
    (*players[1]).remove(cards[1]);
    (*players[2]).remove(cards[2]);
    (*players[3]).remove(cards[3]);

    return winner;
}



