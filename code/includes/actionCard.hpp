#ifndef AC_H
#define AC_H

#include "card.hpp"
#include "player.hpp"


class ActionCard : public Card {
    protected:
    std::string actionType;
    std::string effectID;

    public:
    
    ActionCard(std::string name, std::string eD, std::string cardActID);
    ~ActionCard();


    void applyEffect(Player * player);
    std::string toString();

};


#endif