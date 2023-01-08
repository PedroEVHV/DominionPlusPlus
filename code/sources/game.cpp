#include "game.hpp"
#include "ACM.hpp"

#define CARDSETS 2


int Game::idCounter = 0;

std::map<std::string, Card *> Game::idents;

void Game::setupIdents(std::vector<Card*> cards) {
    for(Card * card: cards) {
        idents.insert(std::pair<std::string, Card*>(card->getCmdID(), card));
    }
}
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
        this->players[i]->setHand();
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
        std::cout<<card->getName() + " ";
    }
    std::cout<<std::endl;
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


bool Game::validateCommand(std::string cmd) {
    if(((cmd[0] == 'p' || cmd[0] == 'b') && (cmd.size() == 5)) || ((cmd[0] == 'c' || cmd[0] == 's') && cmd.size() == 1) ) {
        return true;
    } else {
        return false;
    }
}


void Game::enterCommand(Player * player, bool * acted) {
    std::string cmd;
    do {
        std::cin>>cmd;
    } while (validateCommand(cmd) == false);

    if (cmd[0] == 'p' && cmd[1] == '-') {
        if(!*acted) {
           Card * card = idents[cmd.substr(2,3)];
            if(player->getNbCardPlays() > 0 && player->isInSet(player->getHand(), card)) {
                if(cmd.substr(2,3) != "CVE" && cmd.substr(2,3) != "AGN" && cmd.substr(2,3) != "AUR") {
                    player->setNbCardPlays(player->getNbCardPlays() - 1);
                }
                ACM::selectEffect(cmd.substr(2,3), player, idents);
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
        if (card->getCost() < player->getPurchasePower() && this->kingdomCards[card] > 0 && player->getNbPurchases() > 0 && card->getCost() <= player->getPurchasePower()) {
            std::cout<<"Carte achetee"<<std::endl;
            player->addCardToDiscard(card);
            player->setNbPurchases(player->getNbPurchases() - 1);
            player->setPurchasePower(player->getPurchasePower() - card->getCost());
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
        }
        
    }
}


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