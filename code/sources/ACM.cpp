#include "ACM.hpp"

/*
    Enter command function allows the player to choose what to buy

    command: p ATL -> play Atelier
             b ATL -> buy Atelier
*/



//
/**
 * @brief calls card effect
 * 
 * @param ident card id 
 * @param player current player
 * @param game current game
 */
void ACM::selectEffect(std::string ident, Player * player, Game * game) {
    std::cout<<ident<<std::endl;
    if(ident == "ATL") {
        ATL(player, game);
    } else if(ident == "CVE") {
        CVE(player);
    } else if(ident == "AGN") {
        AGN(player);
    } else if(ident == "P__") {
        P__(player);
    } else if(ident == "AUR") {
        AUR(player);
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
    } else if(ident == "VLL") {
        VLL(player, game);
    } else if(ident == "SAT") {
        SAT(player, game);
    }
}

/**
 * @brief Elementary action. Adds a card to the hand from the deck
 * 
 * @param ident id of card 
 * @param player player to give the card to
 * @return true 
 * @return false 
 */
bool ACM::addCard(std::string ident, Player * player) {
    if(Game::getIdents()[ident] == nullptr) {
        return false;
    } else {
        player->addCardToDiscard(Game::getIdents()[ident]);
        return true;
    }
}

/**
 * @brief Picks a card from the deck
 * 
 * @param player player picking card
 * @param game current game
 */
void ACM::addRandomCard(Player * player, Game * game) {
    game->adjustment(player, 1);
    int randInt = (rand() % player->getDeck().size());
    player->addCardToHand(player->getDeck()[randInt]);
}


/**
 * @brief adds multiple random cards
 * 
 * @param player player picking cards
 * @param game current game
 * @param nb nb of times addRandomCard() will be called
 */
void ACM::addRandomCardMult(Player * player, Game * game, int nb) {
    for(int i = 0; i < nb; i++) {
        addRandomCard(player, game);
    }
}


/**
 * @brief allows player to trash multiple cards
 * 
 * @param player player trashing card
 * @param game current game
 * @param n maximum cards that can be trashed
 */
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

/**
 * @brief Method for trashing only one card.
 * 
 * @param player player trashing card
 * @param game current game
 * @param cmd id of card to be trashed
 */
void ACM::trashCardUnit(Player * player, Game * game, std::string * cmd) {

    
    std::cin>>*cmd;
    bool discarded = false;
    Card* toBeTrashed;
    for(Card * card : player->getHand()) {
        if(discarded == false && game->getIdents()[*cmd] == card) {
            
            toBeTrashed = card;
            discarded = true;
            game->toTrash(toBeTrashed, player, true);
        }
    }
    player->removeCardFromHand(toBeTrashed);
}


void ACM::trashAndGet(Player * player, Game * game, bool treasure, int extra) {
    std::cout<<"Choisissez une carte à écarter"<<std::endl;
    std::string cmd;
    if(treasure) {
        do
        {
            std::cin>>cmd;
            if(Game::getIdents()[cmd] != nullptr) {
                if(Game::getIdents()[cmd]->getType() == "Tresor" && player->isInSet(player->getHand(), Game::getIdents()[cmd]) && game->getKingdomCards().find( Game::getIdents()[cmd]) != game->getKingdomCards().end()) {
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
            std::cout<<"Maintenant choisissez la nouvelle carte trésor.\nEntrez un identificateur valide"<<std::endl;
            std::cin>>cmd;
            if(Game::getIdents().find(cmd) != Game::getIdents().end()) {
                if(Game::getIdents()[cmd]->getCost() <= worth) {
                    player->addCardToHand(Game::getIdents()[cmd]); //adds to hand and not to deck
                }
            }
        } while ( (Game::getIdents().find(cmd) == Game::getIdents().end() && cmd != "STOP"));
    }


    
    
}


void ACM::addCurseUnit(Player * player, Game * game, Card * c) {
    player->addCardToDiscard(c);
}



void ACM::curseTarget(Player * player, Player * target, Game * game, int n) {
    Card * curse = Game::getIdents()["MAL"];
    if(curse == nullptr) {std::cout<<"Fatal error."<<std::endl; exit(0);}
    if(game->getKingdomCards()[curse] > n) {
        game->setKingdomCardStack(curse, -n);
        for(int i = 0; i < n; i++) {
            addCurseUnit(target, game, curse);
        }
    }
}


void ACM::cursePlayers(Player * player, Game * game, int n) {
    for(Player * p: game->getPlayers()) {
        curseTarget(player, p, game, n);
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

void ACM::ATL(Player * player, Game * game) {
    std::cout<<"Carte Atelier. Choisissez une carte valant au plus 4.\nEntrez un identificateur valide"<<std::endl;
    std::string cmd;
    do
    {
        std::cin>>cmd;
        if(Game::getIdents()[cmd] != nullptr && Game::getIdents()[cmd]->getCost() > 4) {
            if(game->getKingdomCards().find(Game::getIdents()[cmd]) != game->getKingdomCards().end())
            std::cout<<"Cette carte vaut plus que 4. Choisissez-en une autre.\n";
        }
    } while (Game::getIdents()[cmd] == nullptr);
    player->addCardToDiscard(Game::getIdents()[cmd]);
    game->getKingdomCards()[Game::getIdents()[cmd]]--;
    

}


void ACM::BCH(Player * player) {
    addPurchases(player, 1);
    addPurchasePower(player, 2);
}


void ACM::CAV(Player * player, Game * game) {
    addActions(player, 1);
    std::string cmd;
    std::vector<Card*> tobeDiscarded;
    std::cout<<"Vous pouvez défausser autant de cartes que vous le souhaitez.\nEntrez un identificateur. Entrez STOP pour passer."<<std::endl;
    int cpt = 0;
    do {
        std::cout<<"Entrez un identificateur.\n";
        std::cin>>cmd;
        if(Game::getIdents()[cmd] != nullptr && player->isInSet(player->getHand(), Game::getIdents()[cmd])) {
            tobeDiscarded.push_back(Game::getIdents()[cmd]);
            cpt++;
        }
    } while(cmd != "STOP" && player->getHand().size() > 0);
    for(Card * card : tobeDiscarded) {
        player->removeCardFromHand(card);
        player->addCardToDiscard(card);
    }
    addRandomCardMult(player, game, cpt);
    
    
}


void ACM::CPL(Player * player, Game * game) {
    std::cout<<"Vous pouvez écarter autant de cartes que vous le souhaitez.\nEntrez un identificateur. Entrez STOP pour passer."<<std::endl;
    std::string cmd;
    do
    {
        std::cin>>cmd;
        bool trashed = false;
        Card* tobeTrashed = nullptr;
        for(Card * card : player->getHand()) {
            if(trashed == false && game->getIdents()[cmd] == card) {
                game->toTrash(card, player, false);
            }
        }
        if(tobeTrashed != nullptr) {player->removeCardFromHand(tobeTrashed);}
        
        
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


void ACM::SRC(Player * player, Game * game) {
    addRandomCardMult(player, game, 2);
    cursePlayers(player, game, 2);
}


void ACM::VLL(Player * player, Game * game) {
    addActions(player, 2);
    addRandomCard(player, game);
}

void ACM::SAT(Player * player, Game * game) {
    std::string cmd;
    do
    {
        std::cout<<"Choisissez une carte de votre main à jouer deux fois. Entrez un identificateur valide. \nEntrez STOP si vous n'avez plus de cartes en main"<<std::endl;
        std::cin>>cmd;
    } while (Game::getIdents()[cmd] != nullptr && player->isInSet(player->getHand(), Game::getIdents()[cmd]));
    selectEffect(cmd, player, game);
    selectEffect(cmd, player, game);
    
}


//Other cards

void ACM::P__(Player * player) {
    std::vector<Card *> played;
    for(Card * card: player->getHand()) {
        if(card->getCmdID() == "CVE") {
            CVE(player);
            played.push_back(card);
        } else if(card->getCmdID() == "AGN") {
            AGN(player);
            played.push_back(card);
        } else if(card->getCmdID() == "AUR") {
            AUR(player);
            played.push_back(card);
        }
    }
    for(Card * card : played) {
        player->removeCardFromHand(card);
        player->addCardToDiscard(card);
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