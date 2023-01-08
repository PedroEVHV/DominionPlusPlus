#ifndef CARD_H
#define CARD_H

#include <string>
#include <vector>



class Card {
    protected:
    std::string id;
    std::string cmdID;
    static int idCounter;
    std::string name;
    std::string type;
    std::string effectDesc;
    int cost;
    //sprite
    
    public:
    
    virtual std::string toString() = 0;

    Card(std::string name, std::string type, std::string effectDesc, std::string cmdID);
    ~Card();

    std::string getName() const {return this->name;}
    std::string getType() const {return this->type;}
    std::string getEffect() const {return this->effectDesc;}
    std::string getID() const {return this->id;}
    std::string getCmdID() const {return this->cmdID;}
    int getIdCounter() const {return idCounter;}
    int getCost() const {return this->cost;}

};


#endif