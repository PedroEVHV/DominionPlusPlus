#ifndef ACM_H
#define ACM_H

#include "player.hpp"
#include "actionCard.hpp"
#include "game.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <map>

class ACM {
    protected:
    

    public:

    //
    /*
        Interactions
    */

    static void selectEffect(std::string ident, Player * player, Game * game);
    static bool addCard(std::string ident, Player * player);
    static void addRandomCard(Player * player, Game * game);
    static void addRandomCardMult(Player * player, Game * game, int nb);
    static void trashCards(Player * player, Game * game, int n);
    static void trashCardUnit(Player * player, Game * game, std::string * cmd);
    static void trashAndGet(Player * player, Game * game, bool treasure, int extra);


    /*
        Elementary actions
    */

    static void addPurchasePower(Player * player, int n);
    static void addActions(Player * player, int n);
    static void addPurchases(Player * player, int n);
    static void addCurseUnit(Player * player, Game * game, Card * c);
    static void cursePlayers(Player * player, Game * game, int n);
    static void curseTarget(Player * player, Player * target, Game * game, int n);

    /*
        Card effect methods.
    */

    static void TEST1(Player * player);

    static void ATL(Player * player);
    static void AVT(Player * player);
    static void BBL(Player * player);
    static void BCH(Player * player);
    static void BCT(Player * player);
    static void CAV(Player * player, Game * game);
    static void CHC(Player * player);
    static void CHL(Player * player);
    static void CPL(Player * player, Game * game);
    static void DVS(Player * player);
    static void SPY(Player * player);
    static void FSN(Player * player);
    static void FSL(Player * player);
    static void FGN(Player * player, Game * game);
    static void JDN(Player * player);
    static void LBT(Player * player);
    static void MRC(Player * player, Game * game);
    static void MLC(Player * player);
    static void MNE(Player * player, Game * game);
    static void PTG(Player * player);
    static void RNV(Player * player, Game * game);
    static void SAT(Player * player);
    static void SRC(Player * player, Game * game);
    static void VLL(Player * player, Game * game);
    static void VOL(Player * player);

    //Other cards

    static void P$$(Player * player);

    static void CVE(Player * player);
    static void AGN(Player * player);
    static void AUR(Player * player);

};










#endif