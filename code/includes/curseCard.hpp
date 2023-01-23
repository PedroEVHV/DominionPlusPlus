#ifndef CC_H
#define CC_H

#include "card.hpp"
#include "player.hpp"

/**
 * @brief Class for the curse card. Allows for removing Victory points of players.
 * 
 */
class CurseCard : public Card {
    private:
    int malus;

    public: 

    CurseCard(std::string name, std::string eD, std::string cmdID, int malus, int cost);


    
    void removePoints(Player * player);
    std::string toString();
};



#endif 