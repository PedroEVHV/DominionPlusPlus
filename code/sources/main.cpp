#include <iostream>


#include <string>
#include "player.hpp"
#include "moneyCard.hpp"
#include "game.hpp"

int main() {
    srand((unsigned) time(0));

    std::string s = "fdsfvcd";
    std::cout<<"hello"<<std::endl;
    Player p1 = Player("ronald", false);
    Player p2 = Player("james", false);
    MoneyCard copper = MoneyCard("Cuivre", "", 1);
    MoneyCard silver = MoneyCard("Argent", "", 2);
    MoneyCard gold = MoneyCard("Or", "", 3);


    //Card creation
    CurseCard c = CurseCard("Malediction", "", -1);
    VictoryCard domain = VictoryCard("Domaine", "", 1);
    VictoryCard duche = VictoryCard("Duche", "", 3);
    VictoryCard province = VictoryCard("Province", "", 6);

    std::vector<Player *> players = {&p1, &p2};
    std::vector<Card *> cards = {};
    Game test = Game(players, cards, &province, &duche, &domain, &c, &copper, &silver, &gold);
    
    
    test.run();

    p1.addCardToDeck(&c);
    p1.removeCardFromDeck(&c);

    return 0;
}