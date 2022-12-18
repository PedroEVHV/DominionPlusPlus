#include "moneyCard.hpp"

MoneyCard::MoneyCard(std::string name, std::string eD, int worth, int cost) : Card(name, "Action", eD) {
    this->worth = worth;
    this->cost = cost;
}