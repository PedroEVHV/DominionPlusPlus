#include "actionCard.hpp"
#include "ACM.hpp"


ActionCard::ActionCard(std::string name, std::string eD, std::string cmdID, bool react, bool attack, int cost) : Card(name, "Action", eD, cmdID, cost) {
    this->effectID = cmdID;
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


