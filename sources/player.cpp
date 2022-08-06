/*
** TRISTAN GORY PROJECT, 2022
** la-bataille
** File description:
** player
*/

#include <iostream>
#include "player.hpp"

player::player()
{
}

void player::addCard(int color, int power)
{
    playerDeck.push_back(std::make_unique<card>(color, power));
}

void player::printDeck() const noexcept
{
    for (size_t i = 0; i != playerDeck.size(); i += 1) {
        std::cout << playerDeck[i]->getPower() << " " << playerDeck[i]->getColor() << std::endl;
    }
}