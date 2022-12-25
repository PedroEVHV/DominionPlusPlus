#ifndef AC_H
#define AC_H

#include "card.hpp"


class ActionCard : public Card {
    protected:
    std::string actionType;

    public:
    
    ActionCard(std::string name, std::string eD);



    void applyEffect();
    std::string toString();

};


#endif