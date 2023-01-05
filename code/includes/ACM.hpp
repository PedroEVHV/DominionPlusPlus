#ifndef ACM_H
#define ACM_H

#include "player.hpp"
#include "game.hpp"
#include "actionCard.hpp"
#include <iostream>

class ACM {
    protected:
    

    public:
    static std::map<std::string, ActionCard*>idents;


    static void setupIdents(std::vector<ActionCard*> cards);

    //
    /*
        Interactions
    */

    static void enterCommand(Player * player, Game * game);
    static bool validateCommand(std::string cmd);
    static void selectEffect(std::string ident, Player * player);
    static void addCard(std::string ident, Player * player);


    /*
        Elementary actions
    */

    static void addPurchasePower(Player * player, int n);
    static void addActions(Player * player, int n);
    static void addPurchases(Player * player, int n);

    /*
        Card effect methods.
    */

    static void TEST1(Player * player);

    static void ATL(Player * player);
    static void AVT(Player * player);
    static void BBL(Player * player);
    static void BCH(Player * player);
    static void BCT(Player * player);
    static void CAV(Player * player);
    static void CHC(Player * player);
    static void CHL(Player * player);
    static void DVS(Player * player);
    static void SPY(Player * player);
    static void FSN(Player * player);
    static void FSL(Player * player);
    static void FGN(Player * player);
    static void JDN(Player * player);
    static void LBT(Player * player);
    static void MRC(Player * player);
    static void MLC(Player * player);
    static void MNE(Player * player);
    static void PTG(Player * player);
    static void RNV(Player * player);
    static void SAT(Player * player);
    static void SRC(Player * player);
    static void VLL(Player * player);
    static void VOL(Player * player);

};










#endif