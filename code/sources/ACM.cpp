#include "ACM.hpp"

std::map<std::string, ActionCard *> ACM::idents;

void ACM::setupIdents(std::vector<ActionCard*> cards) {
    for(ActionCard * card: cards) {
        ACM::idents.insert(std::pair<std::string, ActionCard*>(card->getActID(), card));
    }
}

/*
    Enter command function allows the player to choose what to buy

    command: p ATL -> play Atelier
             b ATL -> buy Atelier
*/

void ACM::enterCommand(Player * player, Game * game) {
    std::string cmd;
    do
    {
        std::cin>>cmd;
    } while (validateCommand(cmd) == false);

    if (cmd[0] == 'p' && cmd[1] == '-')
    {
        ActionCard * card = idents[cmd];
        if(player->getNbCardPlays() > 0 && player->isInSet(player->getHand(), card)) {
            selectEffect(cmd.substr(2,3), player);
        } else {
            std::cout<<"Erreur carte non jouée"<<std::endl;
        }
        
    } else if(cmd[0] == 'b' && cmd[1] == '-') {
        std::cout<<"Vous avez choisi de faire un achat. Jouer une carte action ne sera plus possible."<<std::endl;
        Card * card = idents[cmd.substr(2,3)];
        if (card->getCost() < player->getPurchasePower())
        {
            std::cout<<"Carte achetee"<<std::endl;
            player->addCardToDiscard(card);
        } else {
            std::cout<<"Vous ne pouvez pas acheter cette carte"<<std::endl;
        }
        
    } else if(cmd[0] == 'c') {
        std::cout<<"Vous avez choisi de finir votre tour"<<std::endl;
        player->setNbCardPlays(0);
        player->setNbPurchases(0);
    } else if(cmd[0] == 's') {
        std::cout<<"Vous avez choisi de declarer forfait\nEtes-vous sur? O/N"<<std::endl;
        std::string surrender;
        do
        {
            std::cin>>surrender;
        } while (surrender != "O" && surrender != "N");
        
        if(surrender == "O") {
            //surrender
        }
        
    }
    

    
}

bool ACM::validateCommand(std::string cmd) {
    std::cout<<cmd<<" "<<cmd.size()<<std::endl;
    if((cmd[0] == 'p' || cmd[0] == 'b') && (cmd.size() == 5)) {
        return true;
    } else {
        return false;
    }
}
//
void ACM::selectEffect(std::string ident, Player * player) {
    std::cout<<ident<<std::endl;
    if(ident == "ATL") {
        ATL(player);
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

void ACM::ATL(Player * player) {
    std::cout<<"Carte Atelier. Choisissez une carte valant au plus 4.\nEntrez un identificateur valide"<<std::endl;
    std::string cmd;
    do
    {
        std::cin>>cmd;
    } while (idents.find(cmd) == idents.end());
    

}