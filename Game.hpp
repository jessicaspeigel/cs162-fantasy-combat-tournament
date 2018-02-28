/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: header for game class
****************************************************/
#ifndef CS162_FANTASY_COMBAT_GAME_GAME_HPP
#define CS162_FANTASY_COMBAT_GAME_GAME_HPP

#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "Menu.hpp"
#include "Queue.hpp"
#include "InputValidation.hpp"

class Game {
    private:
        Queue* team1;
        Queue* team2;
        Queue* losers;
        Character* player1;
        Character* player2;
        int fight;
        int round;
        int team1Score;
        int team2Score;
        void startGame();
        void runFight();
        bool runRound();

    public:
        Game();
        ~Game();
};

#endif //CS162_FANTASY_COMBAT_GAME_GAME_HPP
