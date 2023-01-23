#include "card.hpp"

/**
 * @brief idCounter is used to build the Id's for Card instances.
 * 
 */
int Card::idCounter = 0;

/**
 * @brief Construct a new Card:: Card object. standard constructor for all cards. Each inherited class has a specific constructor.
 * 
 * @param name 
 * @param type 
 * @param effectDesc 
 * @param cmdID 
 * @param cost 
 */
Card::Card(std::string name, std::string type, std::string effectDesc, std::string cmdID, int cost) {
    this->name = name;
    this->type = type;
    this->effectDesc = effectDesc;
    this->id = type + std::to_string(idCounter);
    this->cmdID = cmdID;
    this->cost = cost;
    idCounter++;

    
}


Card::~Card() {
    
}