#include "victoryCard.hpp"

VictoryCard::VictoryCard(std::string name, std::string eD, int points) : Card(name, "Victoire", eD){
    this->points = points;
}

VictoryCard::~VictoryCard() {

}

std::string VictoryCard::toString() {
    
}

void VictoryCard::addPoints(Player * player) {
    player->setVictoryPoints(player->getVictoryPoints() + this->points);
}

