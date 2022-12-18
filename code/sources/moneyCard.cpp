#include "moneyCard.hpp"

MoneyCard::MoneyCard(std::string name, std::string eD, int worth) : Card(name, "Tresor", eD) {
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

void MoneyCard::addMoney(Player * player) {
    player->setMoney(player->getMoney() + this->worth);
}