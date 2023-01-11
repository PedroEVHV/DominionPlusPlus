#include "ACM.hpp"

/*
    Enter command function allows the player to choose what to buy

    command: p ATL -> play Atelier
             b ATL -> buy Atelier
*/



//
void ACM::selectEffect(std::string ident, Player * player, Game * game) {
    std::cout<<ident<<std::endl;
    if(ident == "ATL") {
        ATL(player);
    } else if(ident == "CVE") {
        CVE(player);
    } else if(ident == "AGN") {
        AGN(player);
    } else if(ident == "P$$") {
        P$$(player);
    } else if(ident == "AUR") {
        AUR(player);
    } else if(ident == "ATL") {
        ATL(player);
    } else if(ident == "CPL") {
        CPL(player, game);
    } else if(ident == "BCH") {
        BCH(player);
    } else if(ident == "CAV") {
        CAV(player, game);
    } else if(ident == "FGN") {
        FGN(player, game);
    } else if(ident == "MRC") {
        MRC(player, game);
    } else if(ident == "MNE") {
        MNE(player, game);
    } else if(ident == "RNV") {
        RNV(player, game);
    }
}

bool ACM::addCard(std::string ident, Player * player) {
    if(Game::getIdents()[ident] == nullptr) {
        return false;
    } else {
        player->addCardToHand(Game::getIdents()[ident]);
    }
}

void ACM::addRandomCard(Player * player, Game * game) {
    int randInt = (rand() % player->getDeck().size());
    game->adjustment(player, 1);
    player->addCardToHand(player->getDeck()[randInt]);
}

void ACM::trashCards(Player * player, Game * game, int n) {
    std::string cmd;
    int nbDiscards = 0;
    if(n == -1) {
        
        do
        {
            trashCardUnit(player, game, &cmd);
            
        } while (cmd != "STOP");
        for (unsigned int i = 0; i < nbDiscards; i++)
        {
            player->addCardToHand(player->getDeck()[0]);
            player->getDeck().erase(player->getDeck().begin());
        } 
    } else {
        for (int i = 0; i < n; i++)
        {
            trashCardUnit(player, game, &cmd);
        }
        
        
    }
    
}


void ACM::trashCardUnit(Player * player, Game * game, std::string * cmd) {

    
    std::cin>>*cmd;
    bool discarded = false;
    Card* toBeDiscarded;
    for(Card * card : player->getHand()) {
        if(discarded == false && game->getIdents()[*cmd] == card) {
            player->addCardToDiscard(card);
            toBeDiscarded = card;
            discarded = true;
        }
    }
    player->removeCardFromHand(toBeDiscarded);
}


void ACM::trashAndGet(Player * player, Game * game, bool treasure, int extra) {
    std::cout<<"Choisissez une carte à écarter"<<std::endl;
    std::string cmd;
    if(treasure) {
        do
        {
            std::cin>>cmd;
            if(Game::getIdents()[cmd] != nullptr) {
                if(Game::getIdents()[cmd]->getType() == "Tresor" && player->isInSet(player->getHand(), Game::getIdents()[cmd])) {
                    game->toTrash(Game::getIdents()[cmd], player, true);
                    std::cout<<"Choisissez votre carte"<<std::endl;
                    std::string id;
                    do
                    {
                        
                        std::cout<<"Entrez un identificateur valide.\n";
                        std::cin>>id;
                    } while (addCard(id, player));
                    
                }

            }


        } while (Game::getIdents()[cmd] == nullptr);
    } else {
        do
        {
            std::cout<<"Entrez un identificateur valide"<<std::endl;
            std::cin>>cmd;
        } while (Game::getIdents()[cmd]->getType() != "Tresor" && player->isInSet(player->getHand(), Game::getIdents()[cmd]));
        int worth = Game::getIdents()[cmd]->getCost() + 2;
        do
        {
            std::cout<<"Entrez un identificateur valide"<<std::endl;
            std::cin>>cmd;
            if(Game::getIdents().find(cmd) != Game::getIdents().end()) {
                if(Game::getIdents()[cmd]->getCost() <= worth) {
                    player->addCardToHand(Game::getIdents()[cmd]); //adds to hand and not to deck
                }
            }
        } while ( (Game::getIdents().find(cmd) == Game::getIdents().end() && cmd != "STOP"));
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
        if(Game::getIdents()[cmd] != nullptr && Game::getIdents()[cmd]->getCost() > 4) {
            std::cout<<"Cette carte vaut pus que 4. Choisissez-en une autre.\n";
        }
    } while (Game::getIdents()[cmd] == nullptr);
    

}


void ACM::BCH(Player * player) {
    addPurchases(player, 1);
    addPurchasePower(player, 2);
}


void ACM::CAV(Player * player, Game * game) {
    addActions(player, 1);
    
    std::cout<<"Vous pouvez défausser autant de que vous le souhaitez.\nEntrez un identificateur. Entrez STOP pour passer."<<std::endl;
    
    
    
}


void ACM::CPL(Player * player, Game * game) {
    std::cout<<"Vous pouvez écarter autant de cartes que vous le souhaitez.\nEntrez un identificateur. Entrez STOP pour passer."<<std::endl;
    std::string cmd;
    do
    {
        std::cin>>cmd;
        bool trashed = false;
        Card* tobeTrashed;
        for(Card * card : player->getHand()) {
            if(trashed == false && game->getIdents()[cmd] == card) {
                game->toTrash(card, player, false);
            }
        }
        player->removeCardFromHand(tobeTrashed);
        
    } while (cmd != "STOP");
}

void ACM::FGN(Player * player, Game * game) {
    for(int i = 0; i < 3; i++) {
        addRandomCard(player, game);
    }
}


void ACM::MRC(Player * player, Game * game) {
    addPurchasePower(player, 1);
    addPurchases(player, 1);
    addActions(player, 1);
    addRandomCard(player, game);
}

void ACM::MNE(Player * player, Game * game) {
    trashAndGet(player, game, true, 3);
    
}


void ACM::RNV(Player * player, Game * game) {
    trashAndGet(player, game, false, 2);
}


//Other cards

void ACM::P$$(Player * player) {
    for(Card * card: player->getHand()) {
        if(card->getCmdID() == "CVE") {
            CVE(player);
        } else if(card->getCmdID() == "AGN") {
            AGN(player);
        } else if(card->getCmdID() == "AUR") {
            AUR(player);
        }
    }
}



void ACM::CVE(Player * player) {
    addPurchasePower(player, 1);
}

void ACM::AGN(Player * player) {
    addPurchasePower(player, 2);
}

void ACM::AUR(Player * player) {
    addPurchasePower(player, 3);
}