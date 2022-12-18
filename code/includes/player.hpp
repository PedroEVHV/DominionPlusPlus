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
    std::vector<Card *> getDeck() const {return this->deck;}
    std::vector<Card *> getHand() const {return this->hand;}
    std::vector<Card *> getDiscard() const {return this->discard;}
    std::string getName() const {return this->name;}
    bool getIsHuman() const {return this->isHuman;}
    int getVictoryPoints() const {return this->victoryPoints;}
    int getMoney() const {return this->money;}

    void setMoney(int money) {this->money = money;}
    void setDeck();
    void setHand(std::vector<Card *> set) {this->hand = set;}
    void setDiscard(std::vector<Card *> set) {this->discard = set;}
    void setVictoryPoints(int p) {this->victoryPoints = p;}

    //Alter card sets
    void addCardToDeck(Card * card) {this->deck.push_back(card);}
    void removeCardFromDeck(Card * card) {int i = 0; for(auto c: this->deck) {if(card == c) {this->deck.erase(this->deck.begin() + i);} else {i++;}}}

    void addCardToHand(Card * card) {this->hand.push_back(card);}
    void removeCardFromHand(Card * card) {int i = 0; for(auto c: this->hand) {if(card == c) {this->hand.erase(this->hand.begin() + i);} else {i++;}}}
    
    void addCardToDiscard(Card * card) {this->discard.push_back(card);}
    void removeCardFromDiscard(Card * card) {int i = 0; for(auto c: this->discard) {if(card == c) {this->discard.erase(this->discard.begin() + i);} else {i++;}}}

    int calculateVictoryPoints() {
        for(auto c: this->deck) {
            if(c->getType() == "Victoire") {
                
            }
        }
    }

};

#endif 