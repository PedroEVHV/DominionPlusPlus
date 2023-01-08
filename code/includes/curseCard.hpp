#ifndef CC_H
#define CC_H

#include "card.hpp"
#include "player.hpp"


class CurseCard : public Card {
    private:
    int malus;

    public: 

    CurseCard(std::string name, std::string eD, std::string cmdID, int malus, int cost);
    ~CurseCard();

    
    void removePoints(Player * player);
    std::string toString();
};



#endif 