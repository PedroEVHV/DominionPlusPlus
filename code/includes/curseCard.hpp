#ifndef CC_H
#define CC_H

#include "card.hpp"
#include "player.hpp"


class CurseCard : public Card {
    private:
    int malus;

    public: 

    CurseCard(std::string name, std::string eD, int malus);
    ~CurseCard();

    void forceVirtual() {}
    void removePoints(Player * player);
};



#endif 