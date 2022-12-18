#ifndef CARD_H
#define CARD_H

#include <string>
#include <vector>


class Card {
    private:
    std::string id;
    static int idCounter;
    std::string name;
    std::string type;
    std::string effectDesc;
    //sprite
    public:
    virtual void applyEffect() = 0;

    Card(std::string name, std::string type, std::string effectDesc);
    ~Card();

};


#endif