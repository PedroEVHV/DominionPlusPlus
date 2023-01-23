#ifndef MC_H
#define MC_H

#include "card.hpp"
#include "player.hpp"

/**
 * @brief MoneyCard class: represents in-game currency. At this point three types are implemented : copper, silver and gold coins. In-game currency is used to add purchasing power to a player during buy phase.
 * 
 */
class MoneyCard : public Card {
private:
    int worth;
    

    public:

    
    std::string toString();

    MoneyCard(std::string name, std::string eD, std::string cmdID, int worth, int cost);
    void addMoney(Player * player);

};

#endif 