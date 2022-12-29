#include "player.hpp"
#include "moneyCard.hpp"
#include "victoryCard.hpp"
#include "actionCard.hpp"

int Player::idCounter = 0;

Player::Player() {
    this->name = "default";
    this->isHuman = false;
    this->id = "P" + std::to_string(idCounter);
    idCounter++;
    this->money = 0;
}

Player::Player(std::string name, bool isHuman) {
    this->name = name;
    this->isHuman = isHuman;
    this->id = "P" + std::to_string(idCounter);
    idCounter++;
    this->money = 0;
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

