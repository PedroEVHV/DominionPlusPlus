/*

______________________________________________________________________________________________________
|                                      |                                                              |
|    $$$$$$$\                          |    DOMINION PLUS PLUS :                                      |
|    $$  __$$\    $$\       $$\        |        Remake of The Dominion game by Rio Grande Games in    |
|    $$ |  $$ |   $$ |      $$ |       |        C++. By Pedro van Hylckama Vlieg.                     |
|    $$ |  $$ |$$$$$$$$\ $$$$$$$$\     |                                                              |
|    $$ |  $$ |\__$$  __|\__$$  __|    |       Code - January 2023                                    |
|    $$ |  $$ |   $$ |      $$ |       |                                                              |
|    $$$$$$$  |   \__|      \__|       |    Refer to the provided documentation for specific          |
|    \_______/                         |    information on this implementation                        |
|______________________________________|______________________________________________________________|

    
    
    

    
    
    
    This is the main execution file. All objects are initialized here. During execution all instances
    will be called through pointers. 

    The project was built using a Ubuntu WSL environment. It his highly recommended to compile the sources
    on a Linux platform. 

    An extensive Doxygen-generated documentation is provided or the entire project.

*/




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
    CurseCard c = CurseCard("Malediction", "", "MAL", -1, 0);
    VictoryCard domain = VictoryCard("Domaine", "", "DMN", 1, 2);
    VictoryCard duche = VictoryCard("Duche", "", "DUC", 3, 5);
    VictoryCard province = VictoryCard("Province", "", "PRV",  6, 8);
    MoneyCard copper = MoneyCard("Cuivre", "", "CVE", 1, 0);
    MoneyCard silver = MoneyCard("Argent", "", "AGN", 2, 3);
    MoneyCard gold = MoneyCard("Or", "", "AUR", 3, 6);
        //Action cards
    ActionCard workshop = ActionCard("Atelier", "", "ATL", false, false, 3);
    ActionCard lumber = ActionCard("Bucheron", "", "BCH", false, false, 3);
    ActionCard cellar = ActionCard("Cave", "", "CAV", false, false, 2);
    ActionCard remodel = ActionCard("Rénovation", "", "RNV", false, false, 4);
    ActionCard chapel = ActionCard("Chappelle", "", "CPL", false, false, 2);
    ActionCard mine = ActionCard("Mine", "", "MNE", false, false, 5);
    ActionCard market = ActionCard("Marché", "", "MRC", false, false, 5);

    //Transfer cards to idents map
    std::vector<Card*> cardsForMap;
    cardsForMap.push_back(&workshop);
    cardsForMap.push_back(&lumber);
    cardsForMap.push_back(&cellar);
    cardsForMap.push_back(&chapel);
    cardsForMap.push_back(&market);
    cardsForMap.push_back(&mine);


    cardsForMap.push_back(&c);
    cardsForMap.push_back(&domain);
    cardsForMap.push_back(&duche);
    cardsForMap.push_back(&province);
    cardsForMap.push_back(&copper);
    cardsForMap.push_back(&silver);
    cardsForMap.push_back(&gold);

    Game::setupIdents(cardsForMap);


    std::cout<<Game::getIdents()["CVE"]->getCost()<<std::endl;

    //Test 
    Player p1 = Player("ronald", false);
    Player p2 = Player("james", false);
    std::vector<Player *> players = {&p1, &p2};

    
    std::vector<Card *> cards = {};
    Game test = Game(players, cards, &province, &duche, &domain, &c, &copper, &silver, &gold);
    
    
    test.run();



    return 0;
}//