#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include "player.hpp"
#include "card.hpp"

class Game {
private:
    std::string id;
    static int idCounter;

    std::vector<Player *> players;
    int playerCount;

    std::vector<Card *> kingdomCards;

public:
    Game(std::vector<Player> &playerList, std::vector<Card> &cardList);
    ~Game();

};

#endif