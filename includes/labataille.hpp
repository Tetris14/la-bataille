/*
** TRISTAN GORY PROJECT, 2022
** la bataille
** File description:
** the famous la bataille game from the XIV century
*/

#ifndef LABATAILLE_HPP_
#define LABATAILLE_HPP_

#include <memory>
#include <vector>
#include "card.hpp"
#include "player.hpp"

class labataille
{
    public:
        labataille(int nb_players);
        ~labataille();
        inline void setNbPlayers(int nbPlayers) { nb_players = nbPlayers; };
        inline int getNbPlayers() const noexcept { return nb_players; };
        void printDeck() const noexcept;
        void shuffleDeck() noexcept;
        void setPlayers() noexcept;
        void printPlayersCards() const noexcept;
        void playGame();
        int getPlayersNbCards() const noexcept;
        int isPlayerFull() const noexcept;
    private:
        int nb_players;
        std::vector<std::unique_ptr<card>> mainDeck;
        std::vector<std::unique_ptr<player>> players;
};

#endif /* !LABATAILLE_HPP_ */