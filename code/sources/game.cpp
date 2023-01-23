/**
 * @file game.cpp
 * @author Pedro van Hylckama Vlieg (pevhv.2001@gmail.com)
 * @brief File containing method definitions for Game class
 * @version 0.1
 * @date 2023-01-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include "game.hpp"
#include "ACM.hpp"

/**
 * @brief Limit on the amount of cardsets available to the player. Currently used for test purposes and might change from one version to another.
 * 
 */
#define CARDSETS 2

/**
 * @brief idCounter is used to build the Id's for Game instances.
 * 
 */
int Game::idCounter = 0;

std::map<std::string, Card *> Game::idents;

/**
 * @brief sets up the map linking the card pointers to their respective identification strings.
 * 
 * @param cards vector<Card*> of all card pointers necessary for the game.
 */
void Game::setupIdents(std::vector<Card*> cards) {
    for(Card * card: cards) {
        idents.insert(std::pair<std::string, Card*>(card->getCmdID(), card));
    }
}
//


/**
 * @brief Construct a new Game:: Game object. Also sets up the different components of the game, for example, player hands and decks
 * 
 * 
 * @param playerList vector of Player pointers 
 * @param cardList vector of Card pointers. This includes all kingdom cards needed for one game
 * @param province special pointer for province card
 * @param duchy special pointer for duchy card
 * @param domain special pointer for domain card
 * @param curse special pointer for curse card
 * @param copper special pointer for copper card
 * @param silver special pointer for silver card
 * @param gold special pointer for gold card
 */
Game::Game(std::vector<Player *> playerList, std::vector<Card *> cardList, 
            Card * province, Card * duchy, Card * domain, Card * curse, 
            Card * copper, Card * silver, Card * gold) {

    this->id = "GAME" + std::to_string(idCounter);
    idCounter++;
    this->currTurn = 0;
    
    for(unsigned int i = 0; i < cardList.size(); i++) {
        this->kingdomCards.insert(std::pair<Card*, int>(cardList[i], 10));
    }

    this->players = playerList;

    for(unsigned int i = 0; i < players.size(); i++) {
        
        this->players[i]->setDeck(copper, domain);
        this->players[i]->setHand();
    }
   
    this->otherCards.insert(std::pair<Card *, int>(curse, 30));
    this->otherCards.insert(std::pair<Card *, int>(domain, 12));
    this->otherCards.insert(std::pair<Card *, int>(duchy, 12));
    this->otherCards.insert(std::pair<Card *, int>(province, 12));
    
    
}

/**
 * @brief Trashes cards, removing them permanently from the game
 * 
 * @param card selected card to be trashed
 * @param player player acting the trash
 * @param b sould always be called true, used for test purposes 
 */
void Game::toTrash(Card * card, Player * player, bool b) {
    this->trash.push_back(card);
    if(b) {
        player->removeCardFromHand(card);
    }
    
}

/**
 * @brief removes a card from the trash if an action card requires it
 * 
 * @param card selected card
 * @param player player acting the recovery. Recovered card is sent to his dicard pile
 */
void Game::recover(Card * card, Player * player) {
    if(std::find(this->trash.begin(), this->trash.end(), card) != this->trash.end()) {
        int i = 0; for(auto c: this->trash) {if(card == c) {this->trash.erase(this->trash.begin() + i); return;} else {i++;}}
        player->addCardToDiscard(card);
    }
}

/**
 * @brief creates the pile for a kingdom card.
 * 
 * @param card card targeted
 * @param n amount of card on the pile
 */
void Game::setKingdomCardStack(Card * card, int n) {
    this->kingdomCards[card] += n;
}

/**
 * @brief Destroy the Game:: Game object. Standard destruction and memory freeing
 * 
 */
Game::~Game() {
    for(Player * player : players) {
        delete player;
    }
    idents.clear();
    this->players.clear();
    this->otherCards.clear();
    this->kingdomCards.clear();
    this->trash.clear();
    
}


/**
 * @brief Main game loop. All interactions are done within it's scope
 * 
 */
void Game::run() {
    std::cout<<"Demarrage partie: "<<std::endl;
    int nbtest = 0; //TESTS
    while(this->checkEOG() == true && nbtest < 1000) { //TESTS
        std::cout<<"Tour " + this->currTurn<<std::endl;
        for(Player * player: this->players) {
            this->currPlayer = player;
            std::cout<<this->currPlayer->getName() + " joue actuellement...\n";
            
            this->play(currPlayer);
            
            nbtest++; //TESTS

        }
    }

    std::cout<<"Partie terminee.\nLe gagnant est: " + this->calculateVictor()->getName()<<std::endl;
}


/**
 * @brief Checks if the game meets the end-game conditions
 * 
 * @return true if game should end
 * @return false if otherwise
 */
bool Game::checkEOG() {
    std::cout<<"Verification fin de jeu... ";
    int amount = 0;
    for(const std::pair<Card *, int> elem : this->otherCards) {
        
        if(elem.first->getName() == "Province" && elem.second == 0) {
            std::cout<<"Toutes les cartes province ont ete utilisees!"<<std::endl;
            return false;
        }
        else if(elem.second == 0) {
            std::cout<<"pile vide! ";
            amount++;
        }
        if(amount >= 3) {
            std::cout<<"3 piles ont ete epuisees!"<<std::endl;
            return false;
        }
    }
    std::cout<<"Verification terminee"<<std::endl;
    return true;

}


/**
 * @brief Method for managing a player's actions during his turn.
 * 
 * @param player player currently playing
 */
void Game::play(Player * player) {

    player->showHand();
        //card select
    player->setNbCardPlays(1);
    player->setNbPurchases(1);
    player->setPurchasePower(0);
    

    bool acted = false;

    do {
        std::cout<<"Voici votre pouvoir d'achat: "<<player->getPurchasePower()<<" sur "<<player->getNbPurchases()<<" achats."<<std::endl<<"et vous pouvez jouer encore "<<player->getNbCardPlays()<<" cartes."<<std::endl;

        this->enterCommand(player, &acted);
    } while (player->getNbCardPlays() > 0 || player->getNbPurchases() > 0);
    
    std::cout<<"plus d'actions possibles"<<std::endl;
    

    
    

    //Discard
    for(Card * card : player->getHand()) {
        player->addCardToDiscard(card);
    }
    player->clearHand();

    //Deck reset
    if(player->getHand().size() > 1) {
        for(Card * card : player->getHand()) {
            player->addCardToDiscard(card);
        }
        player->clearHand();
    }
    adjustment(player, 5);

    player->setHand();
    std::cout<<"termine!"<<std::endl;
}

/**
 * @brief Returns the player with the highest amount of Victory Points. If multiple winners are detected only the first one is returned (no draws allowed here !)
 * 
 * @return Player* the winner
 */
Player * Game::calculateVictor() {
    Player * victor;
    int points = 0;
    for(auto p: this->players) {
        if(p->calculateVictoryPoints() > points) {
            victor = p;
            points = p->getVictoryPoints();
        }
    }
    return victor;
}

/**
 * @brief Resets decks and discards if there are not enough cards to pick for next turn or for next action
 * 
 * @param player player whose sets are adjusted
 * @param n threshold at which point an adjustment is considered necessary, e.g. if n = 4, adjustment will start if there are less than 4 cards in the deck
 */
void Game::adjustment(Player * player, unsigned int n) {
    
    if(player->getDeck().size() < n) {
        std::cout<<"Ajustement"<<std::endl;
        for(Card * card : player->getDiscard()) {
            player->addCardToDeck(card);
            
        }
        player->clearDiscard();
    }
}

/**
 * @brief Recieves player command and verifies it
 * 
 * @param cmd 
 * @return true if the command can be interpreted
 * @return false if not
 */
bool Game::validateCommand(std::string cmd, std::map<Card *, int> kc) {
    
    if((((cmd[0] == 'p' || cmd[0] == 'b') && (cmd.size() == 5) && (Game::getIdents()[cmd.substr(2,3)] != nullptr)) 
        || (((cmd[0] == 'c' || cmd[0] == 's') && cmd.size() == 1))) 
        || (cmd == "p-P__")) {
        Card * c = Game::getIdents()[cmd.substr(2,3)];
        
        return (kc.find(c) != kc.end() || cmd == "p-P__" || cmd.substr(0, 1) == "b");
    } else {
        return false;
    }
}

/**
 * @brief Allows the player to enter a command corresponding to their game move. Commands will be verified and interpreted if correct.
 * 
 * @param player player entering command
 * @param acted boolean defining if the player has finished the action phase
 */
void Game::enterCommand(Player * player, bool * acted) {
    std::string cmd;
    do {
        std::cout<<"Entrez une commande valide"<<std::endl;
        std::cin>>cmd;
    } while (validateCommand(cmd, this->kingdomCards) == false);

    

    if (cmd[0] == 'p' && cmd[1] == '-') {
        if(!*acted) {
           Card * card = idents[cmd.substr(2,3)];
            if((player->getNbCardPlays() > 0 && player->isInSet(player->getHand(), card))||cmd.substr(2,3) == "P__") {
                if(cmd.substr(2,3) != "CVE" && cmd.substr(2,3) != "AGN" && cmd.substr(2,3) != "AUR") {
                    player->setNbCardPlays(player->getNbCardPlays() - 1);
                }
                ACM::selectEffect(cmd.substr(2,3), player, this);
                player->removeCardFromHand(card);
                player->showHand();
            } else {
                std::cout<<"Erreur carte non jouée"<<std::endl;
            } 
        } else {
            std::cout<<"Attention vous avez passé la phase action"<<std::endl;
        }
    } else if(cmd[0] == 'b' && cmd[1] == '-') {
        *acted = true;
        std::cout<<"Vous avez choisi de faire un achat. Jouer une carte action ne sera plus possible."<<std::endl;
        player->setNbCardPlays(0);
        Card * card = idents[cmd.substr(2,3)];
        if (card->getCost() <= player->getPurchasePower() && ((card->getType() == "Action" && this->kingdomCards[card] > 0) || card->getType() != "Action")
             && player->getNbPurchases() > 0
             && (card->getCmdID() == "CVE" || card->getCmdID() == "AGN" || card->getCmdID() == "AUR" || card->getCmdID() == "MAL" || card->getCmdID() == "DMN" || card->getCmdID() == "DUC" || card->getCmdID() == "PRV")) {
            std::cout<<"Carte achetee"<<std::endl;
            player->addCardToDiscard(card);
            player->setNbPurchases(player->getNbPurchases() - 1);
            player->setPurchasePower(player->getPurchasePower() - card->getCost());
            if(card->getType() == "Action") {
                this->kingdomCards[card]--;
            }
        } else {
            std::cout<<"Vous ne pouvez pas acheter cette carte.";
            if(card->getCost() > player->getPurchasePower()) {
                std::cout<<" La carte est trop chère\n";
            } else {std::cout<<std::endl;}
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
            exit(0);
        }
        
    }
}

/**
 * @brief Kingdom card selection choice. 
 * 
 * @param cards All possible kingdom cards.
 */
void Game::chooseCardsInit(std::vector<Card *> cards) {
    int cmd;
    std::cout<<"Choisissez un set de cartes royaume"<<std::endl;
    do {
        std::cout<<"Entrez le numéro correspondant"<<std::endl;
        std::cin>>cmd;
    } while (cmd < CARDSETS);
    
    switch (cmd)
    {
    case 1:
        
        break;
    
    case 2:
        break;
    }

}