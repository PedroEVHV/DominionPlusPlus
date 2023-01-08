#include "card.hpp"

int Card::idCounter = 0;

Card::Card(std::string name, std::string type, std::string effectDesc, std::string cmdID) {
    this->name = name;
    this->type = type;
    this->effectDesc = effectDesc;
    this->id = type + std::to_string(idCounter);
    this->cmdID = cmdID;
    idCounter++;

    
}


Card::~Card() {
    
}