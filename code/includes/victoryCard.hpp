#ifndef VC_H
#define VC_H

#include <string>
#include "card.hpp"
#include "player.hpp"

class VictoryCard : public Card {
    protected:
    int points;


    public:
    VictoryCard(std::string name, std::string eD, int points);
    ~VictoryCard();

    
    std::string toString();
    void addPoints(Player * player);
};


#endif