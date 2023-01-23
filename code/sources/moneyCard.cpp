#include "moneyCard.hpp"

/**
 * @brief Construct a new Money Card:: Money Card object
 * 
 * @param name 
 * @param eD 
 * @param cmdID 
 * @param worth 
 * @param cost 
 */
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

/**
 * @brief Basic string output for debug and test purposes
 * 
 * @return std::string 
 */
std::string MoneyCard::toString() {
    std::string out = "[Carte Trésor]" + this->name + " -- " + this->cmdID;
    return out;
}
/**
 * @brief Adds Money to a player. Unused for now as rendered obsolete by a similar function in ACM class
 * 
 * @param player 
 */
void MoneyCard::addMoney(Player * player) {
    player->setMoney(player->getMoney() + this->worth);
}