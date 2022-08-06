/*
** EPITECH PROJECT, 2022
** la bataille
** File description:
** player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <vector>
#include <memory>
#include "card.hpp"

class player
{
    public:
        player();
        ~player() = default;
        void addCard(int color, int power);
        void printDeck() const noexcept;
        inline int getNbCards() const noexcept { return playerDeck.size(); };
    private:
        std::vector<std::unique_ptr<card>> playerDeck;
};


#endif /* !PLAYER_HPP_ */