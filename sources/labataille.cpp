/*
** TRISTAN GORY PROJECT, 2022
** la-bataille
** File description:
** labataille
*/

#include <iostream>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <ctime>
#include <map>
#include "labataille.hpp"

labataille::labataille(int nb_players)
{
    int color = 1;
    int power = 2;

    this->nb_players = nb_players;
    while (color != 5) {
        for (int i = 0; i != 13; i += 1) {
            mainDeck.push_back(std::make_unique<card>(color, power));
            power += 1;
        }
        color += 1;
        power = 2;
    }
}

labataille::~labataille()
{
}

void labataille::printDeck() const noexcept
{
    for (size_t i = 0; i != mainDeck.size(); i += 1) {
        std::cout << mainDeck[i]->getPower() << " " << mainDeck[i]->getColor() << std::endl;
    }
}

int myrandom (int i) { return std::rand()%i;}

void labataille::shuffleDeck() noexcept
{
    std::srand ( unsigned ( std::time(0) ) );
    std::random_shuffle(std::begin(mainDeck), std::end(mainDeck), myrandom);
}

void labataille::printPlayersCards() const noexcept
{
    for (size_t i = 0; i != players.size(); i += 1) {
        printf("\nPlayer %ld\n", i + 1);
        players.at(i)->printDeck();
    }
}

void labataille::setPlayers() noexcept
{
    int h = 0;

    for (int i = 0; i != nb_players; i += 1) {
        players.push_back(std::make_unique<player>());
    }
    for (size_t j = 0; j != mainDeck.size(); j += 1) {
        players.at(h)->addCard(mainDeck.at(j)->getColor(), mainDeck.at(j)->getPower());
        h += 1;
        if (h == nb_players)
            h = 0;
    }
}

int labataille::getPlayersNbCards() const noexcept
{
    int nb_cards = 0;

    for (size_t i = 0; i != players.size(); i += 1) {
        nb_cards += players.at(i)->getNbCards();
    }
    return nb_cards;
}

int labataille::isPlayerFull() const noexcept
{
    for (size_t i = 0; i != players.size(); i += 1) {
        if (players.at(i)->getNbCards() == 52)
            return i;
    }
    return -1;
}

int whoWon(std::vector<std::pair<card, int>> playedCards)
{
    int winner;

    for (size_t i = 1; i < playedCards.size(); i += 1) {
        if (playedCards.at(0).first.getPower() < playedCards.at(i).first.getPower())
            playedCards.at(0) = playedCards.at(i);
    }
    winner = playedCards.at(0).second;
    return winner;
}

void labataille::playGame()
{
    char input;
    int round_winner;
    std::vector<std::pair<card, int>> playedCards;

    while(isPlayerFull() == -1) {
        for (int i = 0; i < nb_players; i += 1) {
            if (players.at(i)->getNbCards() <= 0) {
                players.erase(players.begin() + i);
                nb_players -= 1;
            }
        }
        for (int i = 0; i < nb_players; i += 1) {
            std::cout << "player " << i + 1 << " has : " << players.at(i)->getNbCards() << "cards" << std::endl;
        }
        printf("\n");
        for (int i = 0; i < nb_players; i += 1) {
            // printf("Player %d\n", i + 1);
            // printf("press 'a then enter' to play a card\n");
            // std::cin >> input;
            std::cout << "player " << i + 1 << " played : " << players.at(i)->getCard().getPower() << std::endl;
            playedCards.push_back(std::make_pair(players.at(i)->getCard(), i));
            players.at(i)->popLastCard();
        }
        round_winner = whoWon(playedCards);
        if (round_winner == -1)
            break;
        std::cout << "\nthe winner is player : " << round_winner + 1 << "\n" << std::endl;
        for (int i = 0; i < nb_players; i += 1) {
            players.at(round_winner)->addCard(playedCards.at(i).first.getColor(), playedCards.at(i).first.getPower());
        }
        playedCards.clear();
    }
}