#include "actionCard.hpp"
#include "ACM.hpp"


ActionCard::ActionCard(std::string name, std::string eD, std::string cardActID, bool react, bool attack) : Card(name, "Action", eD) {
    this->effectID = cardActID;
    this->react = react;
    this->attack = attack;
}

ActionCard::~ActionCard() {

}

std::string ActionCard::toString() {
    
}

void ActionCard::applyEffect(Player * player) {
    if(this->effectID == "ATL") {
        
    }
}


