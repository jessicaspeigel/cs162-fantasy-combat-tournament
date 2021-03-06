/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: harry potter class header
****************************************************/
#ifndef CS162_FANTASY_COMBAT_GAME_HARRYPOTTER_HPP
#define CS162_FANTASY_COMBAT_GAME_HARRYPOTTER_HPP

#include "Character.hpp"

class HarryPotter: public Character {
private:

public:
    HarryPotter();
    ~HarryPotter();
    int attack(Character *defender);
    void defend(int attack);
    void resetStrength();
};

#endif //CS162_FANTASY_COMBAT_GAME_HARRYPOTTER_HPP
