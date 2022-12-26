#include "game.hpp"
#include <cstdlib>
#include <time.h>


int Game::idCounter = 0;

Game::Game(std::vector<Player *> playerList, std::vector<Card *> cardList, 
            Card * province, Card * duchy, Card * domain, Card * curse, 
            Card * copper, Card * silver, Card * gold) {

    this->id = "GAME" + std::to_string(idCounter);
    idCounter++;
    this->currTurn = 0;
    
    srand((unsigned) time(0));
    
    for(unsigned int i = 0; i < cardList.size(); i++) {
        this->kingdomCards.insert(std::pair<Card*, int>(cardList[i], 10));
    }
    for(unsigned int i = 0; i < playerList.size(); i++) {
        this->players.push_back(playerList[i]);
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
    while(this->checkEOG() == true) {
        std::cout<<"Tour " + this->currTurn<<std::endl;
        for(unsigned int i = 0; i < this->players.size(); i++) {
            this->currPlayer = players[i];
            std::cout<<this->currPlayer->getName() + " joue actuellement...\n";
            this->play(currPlayer);

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
    for(int i = 0; i < 5; i++) {

    }

    //Action phase
    std::cout<<"Phase action: Voici votre main"<<std::endl;
    for(Card * card : player->getHand()) {
        std::cout<<card->getName() + " ";
    }
    std::cout<<"\nSelectionner la carte a jouer en donnant le numero de la carte."<<std::endl;
    


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