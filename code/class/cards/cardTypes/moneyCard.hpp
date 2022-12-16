#ifndef MC_H
#define MC_H

#include "code/class/cards/card.hpp"

class MoneyCard : public Card {
private:
    int worth;
    int cost;

    public:
    MoneyCard(std::string name, std::string eD, int worth, int cost);
    virtual void applyEffect() = 0;
};

#endif 