#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "card.hpp"

class Player {
    private:
    std::string id;
    static int idCounter;
    std::string name;
    bool isHuman;
    int victoryPoints;

    

    std::vector<Card *> deck;
    std::vector<Card *> hand;
    std::vector<Card *> discard;

    public:

    Player();
    Player(std::string name, bool isHuman);

    ~Player();

    //Getters and setters
    std::vector<Card *> getDeck();
    std::vector<Card *> getHand();
    std::vector<Card *> getDiscard();
    std::string getName();
    bool getIsHuman();
    int getVictoryPoints();

    void setDeck(std::vector<Card *> set);
    void setHand();
    void setDiscard();
    void setVictoryPoints(int p);
    

};

#endif 