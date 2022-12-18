#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include <map>
#include "player.hpp"
#include "card.hpp"
#include "moneyCard.hpp"
#include "curseCard.hpp"
#include "victoryCard.hpp"

class Game {
private:
    std::string id;
    static int idCounter;

    std::vector<Player *> players;
    int playerCount;

    std::map<Card *, int> kingdomCards;
    std::map<Card *, int> otherCards;

public:
    Game(std::vector<Player *> playerList, std::vector<Card *> cardList);
    ~Game();

    //Getters and setters
    std::vector<Player *> getPlayers();
    Player * getPlayerById();
    Player * getPlayerByName();
    int getPlayerCount();

    void setPlayers(std::vector<Player *> playerList);
    void setCardSet(std::vector<std::string> cardList);


    void run();
    void play(Player * player);
    bool checkVictory();


};

#endif