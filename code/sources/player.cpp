#include "player.hpp"

int Player::idCounter = 0;

Player::Player() {
    this->name = "default";
    this->isHuman = false;
}

Player::Player(std::string name, bool isHuman) {
    this->name = name;
    this->isHuman = isHuman;
}

Player::~Player() {
    this->deck.clear();
    this->hand.clear();
    this->discard.clear();
}