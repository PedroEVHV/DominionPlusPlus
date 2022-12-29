#include "game.hpp"
#include <cstdlib>
#include <time.h>
#include <algorithm>


int Game::idCounter = 0;

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
    //Hand setup
    std::cout<<"creation main. ";
    if(player->getHand().size() > 1) {
        player->clearHand();
    }
    
    std::cout<<"Ajout des cartes"<<std::endl;
    std::vector<int> randInts;
    std::vector<Card *> cards;
    for(int i = 0; i < 5; i++) {
        int random;
        do
        {
            random = rand() % (player->getDeck().size());
            
        } while (std::find(randInts.begin(), randInts.end(), random) != randInts.end());
        
        randInts.push_back(random);
        cards.push_back(player->getDeck()[random]);
        

        player->addCardToHand(player->getDeck()[random]);
        
        
    }
    
    for(Card * card : cards) {
        player->removeCardFromDeck(card);
        
    }
    randInts.clear();
    cards.clear();


    //Action phase
    std::cout<<"Phase action: Voici votre main"<<std::endl;
    for(Card * card : player->getHand()) {
        std::cout<<card->getName() + ", ";
    }

        //card select
    player->setNbCardPlays(1);

    while(player->getNbCardPlays() > 0 && player->getHand().size() > 0) {
        int select;
        Card * selectedCard;
        do
        {
            std::cout<<"\nSelectionner la carte a jouer en donnant le numero de la carte."<<std::endl;
            std::cin>>select;
            
        } while (select > player->getHand().size());
        
        

        //TODO
        //play card effect

        std::cout<<"carte jouee"<<std::endl;
        selectedCard = player->getHand()[select];
        player->removeCardFromHand(selectedCard);
        player->setNbCardPlays(player->getNbCardPlays() - 1);
    }
    std::cout<<"plus d'actions possibles"<<std::endl;
    

    //Purchase phase
    std::cout<<"Phase Achat: Entrez l'identificateur de la carte souhaitée.\n --- Voici votre pouvoir d'achat: "<<player->getPurchasePower()<<" sur "<<player->getNbPurchases()<<" achats."<<std::endl;
    

    //Discard
    for(Card * card : player->getHand()) {
        player->addCardToDiscard(card);
    }
    player->clearHand();

    //Deck reset
    adjustment(player);
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

bool checkStack(Card * card, std::map<Card *, int> map) {
    return map[card] > 0;
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