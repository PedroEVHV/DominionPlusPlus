#include "game.hpp"


int Game::idCounter = 0;

Game::Game(std::vector<Player *> playerList, std::vector<Card *> cardList) {

    this->id = "GAME" + std::to_string(idCounter);
    idCounter++;
    
    
    
    for(unsigned int i = 0; i < cardList.size(); i++) {
        this->kingdomCards.insert(std::pair<Card*, int>(cardList[i], 10));
    }
    for(unsigned int i = 0; i < playerList.size(); i++) {
        this->players.push_back(playerList[i]);
        this->players[i]->setDeck();
    }

    CurseCard c = CurseCard("Malediction", "", -1);
    VictoryCard domain = VictoryCard("Domaine", "", 1);
    VictoryCard duche = VictoryCard("Duche", "", 1);
    VictoryCard province = VictoryCard("Province", "", 1);
    this->otherCards.insert(std::pair<Card *, int>(&c, 30));
    this->otherCards.insert(std::pair<Card *, int>(&domain, 12));
    this->otherCards.insert(std::pair<Card *, int>(&duche, 12));
    this->otherCards.insert(std::pair<Card *, int>(&province, 12));
    
    
}

Game::~Game() {
    
}

void Game::run() {

}

bool Game::checkEOG() {
    int amount;
    for(const auto& elem : this->otherCards) {
        if(elem.first->getName() == "Province" && elem.second == 0) {
            return false;
        }
        else if(elem.second == 0) {
            amount++;
        }
        if(amount >= 3) {
            return true;
        }
    }

}

Player * Game::calculateVictor() {
    Player * victor;
    int points = 0;
    for(auto p: this->players) {
        
    }
}

bool checkStack(Card * card, std::map<Card *, int> map) {
    return map[card] > 0;
}