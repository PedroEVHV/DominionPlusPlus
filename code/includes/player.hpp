#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <iostream>
#include "card.hpp"


/**
 * @brief Main player class: for now is not abstract as no AI is implemented.
 * 
 */
class Player {
    private:
    std::string id;
    static int idCounter;
    std::string name;
    bool isHuman;
    int victoryPoints;
    int money;

    //For turn management
    int nbCardPlays;
    int nbPurchases;
    int purchasePower;

    

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
    void printSets() const;
    int getNbPurchases() const {return this->nbPurchases;}
    int getPurchasePower() const {return this->purchasePower;}
    int getNbCardPlays() const {return this->nbCardPlays;}

    void setMoney(int money) {this->money = money;}
    void setDeck(Card * copper, Card * domain);
    void setHand();
    void setDiscard(std::vector<Card *> set) {this->discard = set;}
    void setVictoryPoints(int p) {this->victoryPoints = p;}
    void setNbPurchases(int n) {this->nbPurchases = n;}
    void setNbCardPlays(int n) {this->nbCardPlays = n;}
    void setPurchasePower(int n) {this->purchasePower = n;}

    //Alter card sets
    void addCardToDeck(Card * card) {this->deck.push_back(card);}
    void removeCardFromDeck(Card * card) {int i = 0; for(auto c: this->deck) {if(card == c) {this->deck.erase(this->deck.begin() + i); return;} else {i++;}} }
    void clearDeck() {this->deck.clear();}

    void addCardToHand(Card * card) {this->hand.push_back(card);}
    void removeCardFromHand(Card * card) {int i = 0; for(auto c: this->hand) {if(card == c) {this->hand.erase(this->hand.begin() + i); return;} else {i++;}}}
    void clearHand() {this->hand.clear();}

    void addCardToDiscard(Card * card) {this->discard.push_back(card);}
    void removeCardFromDiscard(Card * card) {int i = 0; for(auto c: this->discard) {if(card == c) {this->discard.erase(this->discard.begin() + i); return;} else {i++;}}}
    void clearDiscard() {this->discard.clear();}


    int calculateVictoryPoints();
    bool isInSet(std::vector<Card *> cards, Card * c);
    void showHand();


    std::string toString();
};

#endif 