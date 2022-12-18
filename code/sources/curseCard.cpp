#include "curseCard.hpp"
#include <string>


CurseCard::CurseCard(std::string name, std::string eD, int malus) : Card(name, "Malediction", eD) {
    this->malus = malus;
}

CurseCard::~CurseCard() {

}

void CurseCard::removePoints(Player * player) {
    player->setVictoryPoints(player->getVictoryPoints() - this->malus);
}