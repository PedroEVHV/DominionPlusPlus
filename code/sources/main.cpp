#include <iostream>


#include <string>
#include "player.hpp"
#include "moneyCard.hpp"
#include "game.hpp"

int main() {
    std::string s = "fdsfvcd";
    std::cout<<"hello"<<std::endl;
    Player p1 = Player("ronald", false);
    Player p2 = Player("james", false);
    MoneyCard m = MoneyCard("r", "r", 2);


    //Card creation
    CurseCard c = CurseCard("Malediction", "", -1);
    VictoryCard domain = VictoryCard("Domaine", "", 1);
    VictoryCard duche = VictoryCard("Duche", "", 3);
    VictoryCard province = VictoryCard("Province", "", 6);

    std::vector<Player *> players = {&p1, &p2};
    std::vector<Card *> cards = {&m};
    Game test = Game(players, cards, &province, &duche, &domain, &c);
    test.run();



    return 0;
}