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
    
    ActionCard(std::string name, std::string eD, std::string cardActID, bool react, bool attack);
    ~ActionCard();


    void applyEffect(Player * player);
    std::string toString();

};


#endif