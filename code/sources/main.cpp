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
    CurseCard c = CurseCard("Malediction", "", "MAL", -1);
    VictoryCard domain = VictoryCard("Domaine", "", "DMN", 1);
    VictoryCard duche = VictoryCard("Duche", "", "DUC", 3);
    VictoryCard province = VictoryCard("Province", "", "PRV",  6);
    MoneyCard copper = MoneyCard("Cuivre", "", "CVE", 1);
    MoneyCard silver = MoneyCard("Argent", "", "AGN", 2);
    MoneyCard gold = MoneyCard("Or", "", "AUR", 3);
        //Action cards
    ActionCard workshop = ActionCard("Atelier", "", "ATL", false, false);
    ActionCard lumber = ActionCard("Bucheron", "", "BCH", false, false);
    ActionCard cellar = ActionCard("Cave", "", "CAV", false, false);

    //Transfer cards to idents map
    std::vector<Card*> cardsForMap;
    cardsForMap.push_back(&workshop);
    cardsForMap.push_back(&lumber);

    cardsForMap.push_back(&c);
    cardsForMap.push_back(&domain);
    cardsForMap.push_back(&duche);
    cardsForMap.push_back(&province);
    cardsForMap.push_back(&copper);
    cardsForMap.push_back(&silver);
    cardsForMap.push_back(&gold);

    Game::setupIdents(cardsForMap);

    //Test 
    Player p1 = Player("ronald", false);
    Player p2 = Player("james", false);
    std::vector<Player *> players = {&p1, &p2};

    
    std::vector<Card *> cards = {};
    Game test = Game(players, cards, &province, &duche, &domain, &c, &copper, &silver, &gold);
    
    
    test.run();



    return 0;
}//