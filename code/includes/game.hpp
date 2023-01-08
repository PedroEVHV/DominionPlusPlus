#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include "player.hpp"
#include "card.hpp"
#include "moneyCard.hpp"
#include "curseCard.hpp"
#include "victoryCard.hpp"
#include "actionCard.hpp"

class Game {
private:
    std::string id;
    static int idCounter;

    //game info
    int currTurn;
    Player * currPlayer;


    std::vector<Player *> players;
    int playerCount;

    std::map<Card *, int> kingdomCards;
    std::map<Card *, int> otherCards;

    std::vector<Card *> trash;
    
    static std::map<std::string, Card*>idents;


public:
    Game(std::vector<Player *> playerList, std::vector<Card *> cardList, 
            Card * province, Card * duchy, Card * domain, Card * curse,
            Card * copper, Card * silver, Card * gold);
    ~Game();

    //Getters and setters
    std::vector<Player *> getPlayers();
    Player * getPlayerById();
    Player * getPlayerByName();
    int getPlayerCount();
    std::map<Card *, int> getOC() {return this->otherCards;}
    std::vector<Card *> getTrash() {return this->trash;}
    std::map<std::string, Card*> getIdents() {return idents;}

    void toTrash(Card * card, Player * player, bool b);
    void recover(Card * card, Player * player);

    void setPlayers(std::vector<Player *> playerList);
    void setCardSet(std::vector<std::string> cardList);


    void run();
    void play(Player * player);
    bool checkEOG();
    Player * calculateVictor();
    void adjustment(Player * player);

    static bool validateCommand(std::string cmd);
    void enterCommand(Player * player, bool * acted);
    static void setupIdents(std::vector<Card*> cards);

    static void chooseCardsInit(std::vector<Card*> cards);


};

#endif