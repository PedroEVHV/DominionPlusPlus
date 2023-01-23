#include "player.hpp"
#include "moneyCard.hpp"
#include "victoryCard.hpp"
#include "actionCard.hpp"

#include <algorithm>
/**
 * @brief id Counter used to build player ids
 * 
 */
int Player::idCounter = 0;
//

/**
 * @brief Construct a new Player:: Player object. Constructor for player instances. Default constructor for test purposes
 * 
 */
Player::Player() {
    this->name = "default";
    this->isHuman = false;
    this->id = "P" + std::to_string(idCounter);
    idCounter++;
    this->money = 0;
    this->nbCardPlays = 0;
    this->purchasePower = 0;
    this->nbPurchases = 0;
}

/**
 * @brief Construct a new Player:: Player object. Constructor for human and AI players
 * 
 * @param name selected name for the player
 * @param isHuman determines if the player will be AI or human
 */
Player::Player(std::string name, bool isHuman) {
    this->name = name;
    this->isHuman = isHuman;
    this->id = "P" + std::to_string(idCounter);
    idCounter++;
    this->money = 0;
    this->purchasePower = 0;
    this->nbCardPlays = 0;
    this->nbPurchases = 0;
}

/**
 * @brief Destroy the Player:: Player object. Standard destruction and memory freeing
 * 
 */
Player::~Player() {
    this->deck.clear();
    this->discard.clear();
    this->hand.clear();
}

/**
 * @brief Prints the size of the different card sets. Used for debug purposes
 * 
 */
void Player::printSets() const {
    std::cout<<"Cartes: "<<std::endl;
    std::cout<<"deck: "<<this->deck.size()<<"; main: "<<this->hand.size()<<"; defausse: "<<this->discard.size()<<std::endl;
}

/**
 * @brief Sets up the starting deck
 * 
 * @param copper pointer for the copper card
 * @param domain pointer for the domain card
 */
void Player::setDeck(Card * copper, Card * domain) {
    for(unsigned int i = 0; i < 7; i++) {
        this->addCardToDeck(copper);
    }
    for(unsigned int i = 0; i < 3; i++) {
        this->addCardToDeck(domain);
    }
    
}

/**
 * @brief sets up hand for next turn.
 * 
 */
void Player::setHand() {
    std::cout<<"creation main. ";
    
    
    std::cout<<"Ajout des cartes"<<std::endl;
    std::vector<int> randInts;
    std::vector<Card *> cards;
    for(int i = 0; i < 5; i++) {
        int random;
        this->printSets();
        do
        {
            random = rand() % (this->getDeck().size());
            for(unsigned int j = 0; j < randInts.size(); j++) {
                std::cout<<randInts[j]<<" ";
            }
            std::cout<<"\n";
            
        } while (std::find(randInts.begin(), randInts.end(), random) != randInts.end());
        
        randInts.push_back(random);
        cards.push_back(this->getDeck()[random]);
        

        this->addCardToHand(this->getDeck()[random]);
        
        
    }
    this->printSets();

    for(Card * card : cards) {
        this->removeCardFromDeck(card);
        
    }
    randInts.clear();
    cards.clear();
    this->printSets();
}


/**
 * @brief calculates the amount of Victory points. Used for determining the winner
 * 
 * @return int amount of Vps
 */
int Player::calculateVictoryPoints() {
        for(auto c: this->deck) {
            if(c->getType() == "Victoire") {
                if(c->getName() == "Domaine") {
                    this->setVictoryPoints(this->victoryPoints + 1);
                } else if(c->getName() == "Duche") {
                    this->setVictoryPoints(this->victoryPoints + 3);
                } else {
                    this->setVictoryPoints(this->victoryPoints + 6);
                }
            } else if(c->getType() == "Malediction") {
                this->setVictoryPoints(this->victoryPoints - 1);
            }
        }
        for(auto c: this->hand) {
            if(c->getType() == "Victoire") {
                if(c->getName() == "Domaine") {
                    this->setVictoryPoints(this->victoryPoints + 1);
                } else if(c->getName() == "Duche") {
                    this->setVictoryPoints(this->victoryPoints + 3);
                } else {
                    this->setVictoryPoints(this->victoryPoints + 6);
                }
            } else if(c->getType() == "Malediction") {
                this->setVictoryPoints(this->victoryPoints - 1);
            }
        }
        for(auto c: this->discard) {
            if(c->getType() == "Victoire") {
                if(c->getName() == "Domaine") {
                    this->setVictoryPoints(this->victoryPoints + 1);
                } else if(c->getName() == "Duche") {
                    this->setVictoryPoints(this->victoryPoints + 3);
                } else {
                    this->setVictoryPoints(this->victoryPoints + 6);
                }
            } else if(c->getType() == "Malediction") {
                this->setVictoryPoints(this->victoryPoints - 1);
            }
        }

        return this->victoryPoints;
    }

/**
 * @brief Checks if a card exists in a specific sets
 * 
 * @param cards set in which to search
 * @param c card to be searched
 * @return true if found
 * @return false if not
 */
bool Player::isInSet(std::vector<Card*> cards, Card * c) {
    return std::find(cards.begin(), cards.end(), c) != cards.end();
}

/**
 * @brief Displays the cards the player has in hand
 * 
 */
void Player::showHand() {
    std::cout<<"Voici votre main"<<std::endl;
    for(Card * card : this->getHand()) {
        std::cout<<card->getName() + " ";
    }
    std::cout<<std::endl;
}

/**
 * @brief Returns a string to display player info. Used for debug purposes
 * 
 * @return std::string 
 */
std::string Player::toString() {
    std::string out = "Joueur: " + this->id + "\n   nom: " + this->name + " , humain: ";
    if(this->isHuman) {
        out += "true \n";
    } else {
        out += "false \n";
    }
    out += "main: ";
    for(auto c: this->hand) {
        
    }
}

