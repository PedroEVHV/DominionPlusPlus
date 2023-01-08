#include "moneyCard.hpp"

MoneyCard::MoneyCard(std::string name, std::string eD, std::string cmdID,  int worth, int cost) : Card(name, "Tresor", eD, cmdID, cost) {
    this->worth = worth;
    this->cost = cost;
    if(worth == 1) {
        this->name = "Cuivre";
    } else if(worth == 2) {
        this->name = "Argent";
    } else {
        this->name = "Or";
    }
}

MoneyCard::~MoneyCard() {}

std::string MoneyCard::toString() {
    
}

void MoneyCard::addMoney(Player * player) {
    player->setMoney(player->getMoney() + this->worth);
}