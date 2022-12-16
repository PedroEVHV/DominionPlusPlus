#include "card.hpp"

Card::Card(std::string name, std::string type, std::string effectDesc) {
    this->name = name;
    this->type = type;
    this->effectDesc = effectDesc;
    this->id = type + std::to_string(idCounter);
    idCounter++;

    
}