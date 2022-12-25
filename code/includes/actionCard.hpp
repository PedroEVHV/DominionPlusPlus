#ifndef AC_H
#define AC_H

#include "card.hpp"


class ActionCard : public Card {
    protected:
    std::string actionType;
    int effectID;

    public:
    
    ActionCard(std::string name, std::string eD, int cardActID);
    ~ActionCard();


    void applyEffect();
    std::string toString();

};


#endif