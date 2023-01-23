#include "victoryCard.hpp"

VictoryCard::VictoryCard(std::string name, std::string eD, std::string cmdID, int points, int cost) : Card(name, "Victoire", eD, cmdID, cost){
    this->points = points;
}

std::string VictoryCard::toString() {
    
}

void VictoryCard::addPoints(Player * player) {
    player->setVictoryPoints(player->getVictoryPoints() + this->points);
}

