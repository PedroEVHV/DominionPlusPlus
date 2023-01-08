#ifndef MC_H
#define MC_H

#include "card.hpp"
#include "player.hpp"

class MoneyCard : public Card {
private:
    int worth;
    

    public:

    
    std::string toString();

    MoneyCard(std::string name, std::string eD, std::string cmdID, int worth);
    void addMoney(Player * player);
    ~MoneyCard();
    

};

#endif 