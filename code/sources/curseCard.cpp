#include "curseCard.hpp"
#include <string>


CurseCard::CurseCard(std::string name, std::string eD, std::string cmdID,  int malus, int cost) : Card(name, "Malediction", eD, cmdID, cost) {
    this->malus = malus;
}

std::string CurseCard::toString() {
    
}

void CurseCard::removePoints(Player * player) {
    player->setVictoryPoints(player->getVictoryPoints() - this->malus);
}