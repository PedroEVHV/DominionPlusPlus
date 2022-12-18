#ifndef CARD_H
#define CARD_H

#include <string>
#include <vector>



class Card {
    protected:
    std::string id;
    static int idCounter;
    std::string name;
    std::string type;
    std::string effectDesc;
    int cost;
    //sprite
    
    public:
    virtual void forceVirtual() = 0;

    Card(std::string name, std::string type, std::string effectDesc);
    ~Card();

    std::string getName() const {return this->name;}
    std::string getType() const {return this->type;}
    std::string getEffect() const {return this->effectDesc;}
    std::string getID() const {return this->id;}
    int getIdCounter() const {return idCounter;}
    int getCost() const {return this->cost;}

};


#endif