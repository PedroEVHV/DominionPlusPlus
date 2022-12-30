#include "ACM.hpp"

void addPurchasePower(Player * player, int n) {
    player->setPurchasePower(player->getPurchasePower() + n);
}

void addPurchases(Player * player, int n) {
    player->setNbPurchases(player->getNbPurchases() + n);
}

void addActions(Player * player, int n) {
    player->setNbCardPlays(player->getNbCardPlays() + n);
}

/*
    The different effect rules of action cards are specified below. 
    The applyEffect() method will call one of the following functions.
*/



void TEST1(Player * player) {
    std::cout<<"hello"<<std::endl;
}