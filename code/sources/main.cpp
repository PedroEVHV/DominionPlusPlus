#include <iostream>


#include <string>
#include "player.hpp"
#include "moneyCard.hpp"
#include "game.hpp"
#include "ACM.hpp"

int main() {
    srand((unsigned) time(0));

    std::string s = "p ATL";
    if(s.substr(2, 3) == "ATL") {
        std::cout<<"OK"<<std::endl;
    } else {std::cout<<s.substr(2, 3)<<std::endl;}


    
    
    


    //Card creation
    CurseCard c = CurseCard("Malediction", "", -1);
    VictoryCard domain = VictoryCard("Domaine", "", 1);
    VictoryCard duche = VictoryCard("Duche", "", 3);
    VictoryCard province = VictoryCard("Province", "", 6);
    MoneyCard copper = MoneyCard("Cuivre", "", 1);
    MoneyCard silver = MoneyCard("Argent", "", 2);
    MoneyCard gold = MoneyCard("Or", "", 3);

    //Test 
    Player p1 = Player("ronald", false);
    Player p2 = Player("james", false);
    std::vector<Player *> players = {&p1, &p2};
    std::vector<Card *> cards = {};
    Game test = Game(players, cards, &province, &duche, &domain, &c, &copper, &silver, &gold);
    
    
    //test.run();

    enterCommand(&p1, &test);

    return 0;
}//