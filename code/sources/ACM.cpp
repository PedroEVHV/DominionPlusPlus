#include "ACM.hpp"

std::map<std::string, ActionCard *> ActionCardManager::idents;

void ActionCardManager::setupIdents(std::vector<ActionCard*> cards) {
    for(ActionCard * card: cards) {
        ActionCardManager::idents.insert(std::pair<std::string, ActionCard*>(card->getActID(), card));
    }
}

/*
    Enter command function allows the player to choose what to buy

    command: p ATL -> play Atelier
             b ATL -> buy Atelier
*/

void ActionCardManager::enterCommand(Player * player, Game * game) {
    std::string cmd;
    do
    {
        std::cin>>cmd;
    } while (validateCommand(cmd) == false);

    if (cmd[0] == 'p' && cmd[1] == '-')
    {
        selectEffect(cmd.substr(2,3), player);
    }
    

    
}

bool ActionCardManager::validateCommand(std::string cmd) {
    std::cout<<cmd<<" "<<cmd.size()<<std::endl;
    if((cmd[0] == 'p' || cmd[0] == 'b') && (cmd.size() == 5)) {
        return true;
    } else {
        return false;
    }
}
//
void ActionCardManager::selectEffect(std::string ident, Player * player) {
    std::cout<<ident<<std::endl;
    if(ident == "ATL") {
        ATL(player);
    }
}

void ActionCardManager::addCard(std::string ident, Player * player) {
    if(ident == "ATL") {
        
    }
}

/*
    Elementary actions
*/

void ActionCardManager::addPurchasePower(Player * player, int n) {
    player->setPurchasePower(player->getPurchasePower() + n);
}

void ActionCardManager::addPurchases(Player * player, int n) {
    player->setNbPurchases(player->getNbPurchases() + n);
}

void ActionCardManager::addActions(Player * player, int n) {
    player->setNbCardPlays(player->getNbCardPlays() + n);
}

/*
    The different effect rules of action cards are specified below. 
    The applyEffect() method will call one of the following functions.
*/

void ActionCardManager::ATL(Player * player) {
    std::cout<<"Carte Atelier. Choisissez une carte valant au plus 4.\nEntrez un identificateur valide"<<std::endl;
    std::string cmd;
    do
    {
        std::cin>>cmd;
    } while (idents.find(cmd) == idents.end());
    

}