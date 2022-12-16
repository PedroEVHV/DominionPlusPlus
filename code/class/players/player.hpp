#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "code/class/cards/card.hpp"

class Player {
    private:
    std::string id;
    static int idCounter;
    std::string name;
    bool isHuman;
    int victoryPoints;

    std::vector<Card> deck;
    std::vector<Card> hand;
    std::vector<Card> discard;

    public:

    Player(std::string name, bool isHuman);
    ~Player();

};

#endif 