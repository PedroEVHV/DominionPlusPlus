#include "actionCard.hpp"
#include "ACM.hpp"

/**
 * @brief Construct a new Action Card:: Action Card object. Uses the react and attack booleans to define its future behaviour whe played
 * 
 * @param name 
 * @param eD 
 * @param cmdID 
 * @param react 
 * @param attack 
 * @param cost 
 */
ActionCard::ActionCard(std::string name, std::string eD, std::string cmdID, bool react, bool attack, int cost) : Card(name, "Action", eD, cmdID, cost) {
    this->effectID = cmdID;
    this->react = react;
    this->attack = attack;
}

/**
 * @brief Basic string output for debug and test purposes
 * 
 * @return std::string 
 */
std::string ActionCard::toString() {
    std::string out = "[Carte Action] " + this->getName() + " -- " + this->cmdID;
    return out;
}


