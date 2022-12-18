#include <iostream>


#include <string>
#include "player.hpp"
#include "moneyCard.hpp"

int main() {
    std::string s = "fdsfvcd";
    std::cout<<"hello"<<std::endl;
    Player p = Player("r", false);
    MoneyCard m = MoneyCard("r", "r", 2);

    p.setDeck();
    p.addCardToDeck(&m);
    



    return 0;
}