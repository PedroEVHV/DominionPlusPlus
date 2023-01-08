#ifndef AC_H
#define AC_H

#include "card.hpp"
#include "player.hpp"


class ActionCard : public Card {
    protected:
    std::string actionType;
    std::string effectID;
    bool react;
    bool attack;

    public:
    
    ActionCard(std::string name, std::string eD, std::string cmdID, bool react, bool attack, int cost);
    ~ActionCard();

    std::string getActID() {return this->effectID;}
    std::string getActionType() {return this->actionType;}
    bool getReact() {return this->react;}
    bool getAttack() {return this->attack;}



    void applyEffect(Player * player);
    std::string toString();

};


#endif