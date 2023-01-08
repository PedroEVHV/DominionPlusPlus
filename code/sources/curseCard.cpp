#include "curseCard.hpp"
#include <string>


CurseCard::CurseCard(std::string name, std::string eD, std::string cmdID,  int malus) : Card(name, "Malediction", eD, cmdID) {
    this->malus = malus;
}

CurseCard::~CurseCard() {

}

std::string CurseCard::toString() {
    
}

void CurseCard::removePoints(Player * player) {
    player->setVictoryPoints(player->getVictoryPoints() - this->malus);
}