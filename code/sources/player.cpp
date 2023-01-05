#include "player.hpp"
#include "moneyCard.hpp"
#include "victoryCard.hpp"
#include "actionCard.hpp"

#include <algorithm>

int Player::idCounter = 0;
//
Player::Player() {
    this->name = "default";
    this->isHuman = false;
    this->id = "P" + std::to_string(idCounter);
    idCounter++;
    this->money = 0;
    this->nbCardPlays = 0;
    this->purchasePower = 0;
    this->nbPurchases = 0;
}

Player::Player(std::string name, bool isHuman) {
    this->name = name;
    this->isHuman = isHuman;
    this->id = "P" + std::to_string(idCounter);
    idCounter++;
    this->money = 0;
    this->purchasePower = 0;
    this->nbCardPlays = 0;
    this->nbPurchases = 0;
}

Player::~Player() {
    this->deck.clear();
    this->hand.clear();
    this->discard.clear();
}


void Player::printSets() const {
    std::cout<<"Cartes: "<<std::endl;
    std::cout<<"deck: "<<this->deck.size()<<"; main: "<<this->hand.size()<<"; defausse: "<<this->discard.size()<<std::endl;
}

void Player::setDeck(Card * copper, Card * domain) {
    for(unsigned int i = 0; i < 7; i++) {
        this->addCardToDeck(copper);
    }
    for(unsigned int i = 0; i < 3; i++) {
        this->addCardToDeck(domain);
    }
    
}

void Player::setHand() {
    std::cout<<"creation main. ";
    if(this->getHand().size() > 1) {
        this->clearHand();
    }
    
    std::cout<<"Ajout des cartes"<<std::endl;
    std::vector<int> randInts;
    std::vector<Card *> cards;
    for(int i = 0; i < 5; i++) {
        int random;
        do
        {
            random = rand() % (this->getDeck().size());
            
        } while (std::find(randInts.begin(), randInts.end(), random) != randInts.end());
        
        randInts.push_back(random);
        cards.push_back(this->getDeck()[random]);
        

        this->addCardToHand(this->getDeck()[random]);
        
        
    }

    for(Card * card : cards) {
        this->removeCardFromDeck(card);
        
    }
    randInts.clear();
    cards.clear();
}

int Player::calculateVictoryPoints() {
        for(auto c: this->deck) {
            if(c->getType() == "Victoire") {
                if(c->getName() == "Domaine") {
                    this->setVictoryPoints(this->victoryPoints + 1);
                } else if(c->getName() == "Duche") {
                    this->setVictoryPoints(this->victoryPoints + 3);
                } else {
                    this->setVictoryPoints(this->victoryPoints + 6);
                }
            } else if(c->getType() == "Malediction") {
                this->setVictoryPoints(this->victoryPoints - 1);
            }
        }
        for(auto c: this->hand) {
            if(c->getType() == "Victoire") {
                if(c->getName() == "Domaine") {
                    this->setVictoryPoints(this->victoryPoints + 1);
                } else if(c->getName() == "Duche") {
                    this->setVictoryPoints(this->victoryPoints + 3);
                } else {
                    this->setVictoryPoints(this->victoryPoints + 6);
                }
            } else if(c->getType() == "Malediction") {
                this->setVictoryPoints(this->victoryPoints - 1);
            }
        }
        for(auto c: this->discard) {
            if(c->getType() == "Victoire") {
                if(c->getName() == "Domaine") {
                    this->setVictoryPoints(this->victoryPoints + 1);
                } else if(c->getName() == "Duche") {
                    this->setVictoryPoints(this->victoryPoints + 3);
                } else {
                    this->setVictoryPoints(this->victoryPoints + 6);
                }
            } else if(c->getType() == "Malediction") {
                this->setVictoryPoints(this->victoryPoints - 1);
            }
        }

        return this->victoryPoints;
    }

bool Player::isInSet(std::vector<Card*> cards, Card * c) {
    return std::find(cards.begin(), cards.end(), c) != cards.end();
}

std::string Player::toString() {
    std::string out = "Joueur: " + this->id + "\n   nom: " + this->name + " , humain: ";
    if(this->isHuman) {
        out += "true \n";
    } else {
        out += "false \n";
    }
    out += "main: ";
    for(auto c: this->hand) {
        
    }
}

