#include "ACM.hpp"

/*
    Enter command function allows the player to choose what to buy

    command: p ATL -> play Atelier
             b ATL -> buy Atelier
*/

void enterCommand(Player * player, Game * game) {
    std::string cmd;
    do
    {
        std::cin>>cmd;
    } while (validateCommand(cmd) == false);

    if (cmd[0] == 'p')
    {
        selectEffect(cmd.substr(2,3), player);
    }
    

    
}

bool validateCommand(std::string cmd) {
    if((cmd[0] == 'p' || cmd[0] == 'b') && (cmd.size() == 5)) {
        return true;
    } else {
        return false;
    }
}
//
void selectEffect(std::string ident, Player * player) {
    if(ident == "ATL") {
        ATL(player);
    }
}

void addCard(std::string ident, Player * player) {
    if(ident == "ATL") {
        
    }
}

/*
    Elementary actions
*/

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

void ATL(Player * player) {
    std::cout<<"Carte Atelier. Choisissez une carte valant au plus 4.\nEntrez un identificateur valide"<<std::endl;
    std::string cmd;
    do
    {
        std::cin>>cmd;
    } while (idents.find(cmd) == idents.end());
    

}