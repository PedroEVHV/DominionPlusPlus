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

void Player::setDeck() {
    for(unsigned int i = 0; i < 7; i++) {
        MoneyCard c = MoneyCard("Cuivre", "", 1);
        this->addCardToDeck(&c);
    }
    for(unsigned int i = 0; i < 3; i++) {
        //this->addCardToDeck(&VictoryCard("Cuivre", "", 1));
    }
    
}