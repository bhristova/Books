#pragma once

#include "Card.h"
#include "Player.h"

class Player;

class Game
{
public:
    Game();

    const char* getGameType() const {return type;}
    int getBidder() const {return bidder;}

    void setGameType();
    void setCardPoints();

    void gameOn();
    int game(int);

    bool isCardFree(int a, int b);

private:
    char* type; /// the type of the current game - All, No, Diamonds, Clubs, Spades, Hearts
    int** deckPoints; /// the points each card carries according to the type of the current game
    int** cards; /// all 32 cards - true if a card has not been dealt to a player, false otherwise
    Player** players; /// the players in the game - 4
    int bidder;
};


