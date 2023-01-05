#include <iostream>


#include <string>
#include "player.hpp"
#include "moneyCard.hpp"
#include "actionCard.hpp"
#include "game.hpp"
#include "ACM.hpp"
#include <time.h>

int main() {
    srand((unsigned) time(0));

    //Card creation
        //Other cards
    CurseCard c = CurseCard("Malediction", "", -1);
    VictoryCard domain = VictoryCard("Domaine", "", 1);
    VictoryCard duche = VictoryCard("Duche", "", 3);
    VictoryCard province = VictoryCard("Province", "", 6);
    MoneyCard copper = MoneyCard("Cuivre", "", 1);
    MoneyCard silver = MoneyCard("Argent", "", 2);
    MoneyCard gold = MoneyCard("Or", "", 3);
        //Action cards
    ActionCard workshop = ActionCard("Atelier", "", "ATL", false, false);

    //Transfer cards to idents for Action card Management
    std::vector<ActionCard*> actionCards;
    actionCards.push_back(&workshop);

    ACM::setupIdents(actionCards);

    //Test 
    Player p1 = Player("ronald", false);
    Player p2 = Player("james", false);
    std::vector<Player *> players = {&p1, &p2};
    std::vector<Card *> cards = {};
    Game test = Game(players, cards, &province, &duche, &domain, &c, &copper, &silver, &gold);
    
    
    test.run();

    //acm.enterCommand(&p1, &test);

    return 0;
}//