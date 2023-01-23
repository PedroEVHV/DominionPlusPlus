#include "curseCard.hpp"
#include <string>

/**
 * @brief Construct a new Curse Card:: Curse Card object
 * 
 * @param name 
 * @param eD 
 * @param cmdID 
 * @param malus 
 * @param cost 
 */
CurseCard::CurseCard(std::string name, std::string eD, std::string cmdID,  int malus, int cost) : Card(name, "Malediction", eD, cmdID, cost) {
    this->malus = malus;
}

/**
 * @brief Basic string output for test and debug purposes
 * 
 * @return std::string 
 */
std::string CurseCard::toString() {
    std::string out = "[Carte Malédiction] " + this->name + " -- " + this->cmdID;
    return out;
}

/**
 * @brief Removes points from the player holding this card
 * 
 * @param player 
 */
void CurseCard::removePoints(Player * player) {
    player->setVictoryPoints(player->getVictoryPoints() - this->malus);
}