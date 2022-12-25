#include "actionCard.hpp"

ActionCard::ActionCard(std::string name, std::string eD, int cardActID) : Card(name, "Action", eD) {
    this->effectID = cardActID;
}

ActionCard::~ActionCard() {

}

std::string ActionCard::toString() {
    
}

void ActionCard::applyEffect() {
    switch (this->effectID)
    {
    case 1:
        
        break;
    
    default:
        break;
    }
}


/*
    The different effect rules of action cards are specified below. 
    The applyEffect() method will call one of the following functions.
*/

