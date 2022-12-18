#include "card.hpp"

int Card::idCounter = 0;

Card::Card(std::string name, std::string type, std::string effectDesc) {
    this->name = name;
    this->type = type;
    this->effectDesc = effectDesc;
    this->id = type + std::to_string(idCounter);
    idCounter++;

    
}


Card::~Card() {
    
}