#include "ACM.hpp"

/*
    Enter command function allows the player to choose what to buy

    command: p ATL -> play Atelier
             b ATL -> buy Atelier
*/



//
void ACM::selectEffect(std::string ident, Player * player, std::map<std::string, Card*> idents) {
    std::cout<<ident<<std::endl;
    if(ident == "ATL") {
        ATL(player, idents);
    } else if(ident == "CVE") {
        CVE(player);
    } else if(ident == "AGN") {
        AGN(player);
    } else if(ident == "AUR") {
        AUR(player);
    } 
}

void ACM::addCard(std::string ident, Player * player) {
    if(ident == "ATL") {
        
    }
}

/*
    Elementary actions
*/

void ACM::addPurchasePower(Player * player, int n) {
    player->setPurchasePower(player->getPurchasePower() + n);
}

void ACM::addPurchases(Player * player, int n) {
    player->setNbPurchases(player->getNbPurchases() + n);
}

void ACM::addActions(Player * player, int n) {
    player->setNbCardPlays(player->getNbCardPlays() + n);
}

/*
    The different effect rules of action cards are specified below. 
    The applyEffect() method will call one of the following functions.
*/

void ACM::ATL(Player * player, std::map<std::string, Card*> idents) {
    std::cout<<"Carte Atelier. Choisissez une carte valant au plus 4.\nEntrez un identificateur valide"<<std::endl;
    std::string cmd;
    do
    {
        std::cin>>cmd;
        if(idents.find(cmd) != idents.end() && idents[cmd]->getCost() > 4) {
            std::cout<<"Cette carte vaut pus que 4. Choisissez-en une autre.\n";
        }
    } while (idents.find(cmd) == idents.end());
    

}


void ACM::BCH(Player * player) {
    addPurchases(player, 1);
    addPurchasePower(player, 2);
}


void ACM::CAV(Player * player, std::map<std::string, Card*> idents, Game * game) {
    addActions(player, 1);
    std::string cmd;
    unsigned int nbDiscards = 0;
    std::cout<<"Vous pouvez défausser autant de que vous le souhaitez.\nEntrez un identificateur. Entrez STOP pour passer."<<std::endl;
    do
    {
        std::cin>>cmd;
        bool discarded = false;
        Card* toBeDiscarded;
        for(Card * card : player->getHand()) {
            if(discarded == false && idents[cmd] == card) {
                player->addCardToDiscard(card);
                toBeDiscarded = card;
                discarded = true;
            }
        }
        player->removeCardFromHand(toBeDiscarded);
        
    } while (cmd != "STOP");
    for (unsigned int i = 0; i < nbDiscards; i++)
    {
        player->addCardToHand(player->getDeck()[0]);
        player->getDeck().erase(player->getDeck().begin());
    }
    
    
}


void ACM::CPL(Player * player) {
    
}


//Other cards

void ACM::CVE(Player * player) {
    player->setPurchasePower(player->getPurchasePower() + 1);
}

void ACM::AGN(Player * player) {
    player->setPurchasePower(player->getPurchasePower() + 2);
}

void ACM::AUR(Player * player) {
    player->setPurchasePower(player->getPurchasePower() + 3);
}