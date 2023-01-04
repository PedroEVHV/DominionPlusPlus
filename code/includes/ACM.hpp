#ifndef ACM_H
#define ACM_H

#include "player.hpp"
#include "game.hpp"
#include <iostream>

std::map<std::string, Card*>idents;

/*
    Interactions
*/

void enterCommand(Player * player, Game * game);
bool validateCommand(std::string cmd);
void selectEffect(std::string ident, Player * player);
void addCard(std::string ident, Player * player);


/*
    Elementary actions
*/

void addPurchasePower(Player * player, int n);
void addActions(Player * player, int n);
void addPurchases(Player * player, int n);

/*
    Card effect methods.
*/

void TEST1(Player * player);

void ATL(Player * player);
void AVT(Player * player);
void BBL(Player * player);
void BCH(Player * player);
void BCT(Player * player);
void CAV(Player * player);
void CHC(Player * player);
void CHL(Player * player);
void DVS(Player * player);
void SPY(Player * player);
void FSN(Player * player);
void FSL(Player * player);
void FGN(Player * player);
void JDN(Player * player);
void LBT(Player * player);
void MRC(Player * player);
void MLC(Player * player);
void MNE(Player * player);
void PTG(Player * player);
void RNV(Player * player);
void SAT(Player * player);
void SAT(Player * player);
void SRC(Player * player);
void VLL(Player * player);
void VOL(Player * player);

#endif