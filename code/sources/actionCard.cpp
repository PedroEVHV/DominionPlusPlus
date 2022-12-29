#include "actionCard.hpp"
#include "ACM.hpp"


ActionCard::ActionCard(std::string name, std::string eD, std::string cardActID) : Card(name, "Action", eD) {
    this->effectID = cardActID;
}

ActionCard::~ActionCard() {

}

std::string ActionCard::toString() {
    
}

void ActionCard::applyEffect(Player * player) {
    if(this->effectID == "TEST1") {
        TEST1(player);
    }
}


