#ifndef VC_H
#define VC_H

#include <string>
#include "card.hpp"
#include "player.hpp"

/**
 * @brief Victory cards provide the player with victory points necessary for them to win.
 * 
 */
class VictoryCard : public Card {
    protected:
    int points;


    public:
    VictoryCard(std::string name, std::string eD, std::string cmdID, int points, int cost);

    
    std::string toString();
    void addPoints(Player * player);
};


#endif