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
    int money;

    

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
    int getMoney();

    void setMoney(int money);
    void setDeck();
    void setHand();
    void setDiscard();
    void setVictoryPoints(int p);

    //Alter card sets
    void addCardToDeck(Card * card);
    void removeCardFromDeck(Card * card);

    void addCardToHand(Card * card);
    void removeCardFromHand(Card * card);
    
    void addCardToDiscard(Card * card);
    void removeCardFromDiscard(Card * card);




};

#endif 