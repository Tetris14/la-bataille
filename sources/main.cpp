/*
** TRISTAN GORY PROJECT, 2022
** la bataille
** File description:
** from the famous la bataille game
*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "labataille.hpp"

int main(int ac, char **av)
{
    int nb_players = 0;

    if (ac != 2) {
        std::cerr << "Usage: ./labataille nb_players" << std::endl;
        return (84);
    }
    for (size_t i = 0; i != strlen(av[1]); i += 1) {
        if (!isdigit(av[1][i])) {
            std::cerr << "Usage: ./labataille nb_players <- is a number without any other char than digits from 0 to 9" << std::endl;
            return -1;
        }
    }
    nb_players = atoi(av[1]);
    labataille game(nb_players);
    game.shuffleDeck();
    game.setPlayers();
    game.playGame();
    return 0;
}