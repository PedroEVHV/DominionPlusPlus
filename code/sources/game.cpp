#include "game.hpp"
#include "ACM.hpp"
#include <cstdlib>
#include <time.h>
#include <algorithm>


int Game::idCounter = 0;
//
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
    }
   
    this->otherCards.insert(std::pair<Card *, int>(curse, 30));
    this->otherCards.insert(std::pair<Card *, int>(domain, 12));
    this->otherCards.insert(std::pair<Card *, int>(duchy, 12));
    this->otherCards.insert(std::pair<Card *, int>(province, 12));
    
    
}

Game::~Game() {
    
}

void Game::run() {
    std::cout<<"Demarrage partie: "<<std::endl;
    int nbtest = 0; //TESTS
    while(this->checkEOG() == true && nbtest < 4) { //TESTS
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

void Game::play(Player * player) {

    std::cout<<"Voici votre main"<<std::endl;
    for(Card * card : player->getHand()) {
        std::cout<<card->getName() + ", ";
    }
    std::cout<<"Voici votre pouvoir d'achat: "<<player->getPurchasePower()<<" sur "<<player->getNbPurchases()<<" achats."<<std::endl;

        //card select
    player->setNbCardPlays(1);
    bool acted = false;

    do
    {
        ACM::enterCommand(player, this);
    } while (player->getNbCardPlays() > 0 || player->getNbPurchases() > 0);
    
    


    /* A REMPLACER
    while(player->getNbCardPlays() > 0 && player->getHand().size() > 0) {
        unsigned int select;
        Card * selectedCard;
        do
        {
            std::cout<<"\nSelectionner la carte a jouer en donnant le numero de la carte."<<std::endl;
            std::cin>>select;
            
        } while (select > player->getHand().size());
    
        

        //TODO
        //play card effect

        //If card is attack type, enable reaction

        std::cout<<"carte jouee"<<std::endl;
        selectedCard = player->getHand()[select];
        player->removeCardFromHand(selectedCard);
        player->setNbCardPlays(player->getNbCardPlays() - 1);
        
    
    }
    */
    std::cout<<"plus d'actions possibles"<<std::endl;
    

    
    

    //Discard
    for(Card * card : player->getHand()) {
        player->addCardToDiscard(card);
    }
    player->clearHand();

    //Deck reset
    adjustment(player);
    player->setHand();
    std::cout<<"termine!"<<std::endl;
}

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

void Game::adjustment(Player * player) {
    
    if(player->getDeck().size() < 5) {
        std::cout<<"Ajustement"<<std::endl;
        for(Card * card : player->getDiscard()) {
            player->addCardToDeck(card);
            
        }
        player->clearDiscard();
    }
}