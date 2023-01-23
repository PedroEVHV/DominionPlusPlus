#include "victoryCard.hpp"

/**
 * @brief Construct a new Victory Card:: Victory Card object
 * 
 * @param name 
 * @param eD 
 * @param cmdID 
 * @param points 
 * @param cost 
 */
VictoryCard::VictoryCard(std::string name, std::string eD, std::string cmdID, int points, int cost) : Card(name, "Victoire", eD, cmdID, cost){
    this->points = points;
}

/**
 * @brief Basic string output for test and debug purposes
 * 
 * @return std::string 
 */
std::string VictoryCard::toString() {
    std::string out = "[Carte Victoire] " + this->name + " -- " + this->cmdID;
    return out;
}

/**
 * @brief Adds victory points to players holding these cards
 * 
 * @param player 
 */
void VictoryCard::addPoints(Player * player) {
    player->setVictoryPoints(player->getVictoryPoints() + this->points);
}

