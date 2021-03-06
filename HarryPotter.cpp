/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: harry potter class implementation
****************************************************/

#include "HarryPotter.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::max;

HarryPotter::HarryPotter() : Character("Harry Potter", 0, 10, 2)
{
    attackRoll.numDice = 2, defenseRoll.numDice = 2;
    attackRoll.numDiceSides = 6, defenseRoll.numDiceSides = 6;
    // Set up the array for attack dice
    attackDice = new Die*[attackRoll.numDice];
    for (int i = 0; i < attackRoll.numDice; i++) {
        attackDice[i] = new Die(attackRoll.numDiceSides);
    }
    // Set up the array for defense dice
    defenseDice = new Die*[defenseRoll.numDice];
    for (int i = 0; i < defenseRoll.numDice; i++) {
        defenseDice[i] = new Die(defenseRoll.numDiceSides);
    }
}

HarryPotter::~HarryPotter()
{
    // Clean up the array for attack dice
    for (int i = 0; i < attackRoll.numDice; i++) {
        delete attackDice[i];
    }
    delete [] attackDice;
    // Clean up the array for defense dice
    for (int i = 0; i < defenseRoll.numDice; i++) {
        delete defenseDice[i];
    }
    delete [] defenseDice;
}

int HarryPotter::attack(Character *defender) {
    // Print out the attack information
//    cout << "Attacker charType: " << getType() << endl;
//    cout << "Defender charType: " << defender->getType() << ", Armor: " << defender->getArmor() << ", Strength: " << defender->getStrength() << endl;
//    cout << getType() << "'s attack dice roll: ";

    int attackTotal = 0;
    int currentRoll = 0;
    for (int i = 0; i < attackRoll.numDice; i++) {
        currentRoll  = attackDice[i]->roll();
        attackTotal += currentRoll;
        // Print the roll for the current die
//        cout << " die " << (i + 1) << " (" << currentRoll << ")";
    }
//    cout << " for an attack total of " << attackTotal << endl;
    return attackTotal;
}

void HarryPotter::defend(int attackScore) {
//    cout << getType() << "'s defense dice roll: ";
    int defenseTotal = 0;
    int currentRoll = 0;
    for (int i = 0; i < defenseRoll.numDice; i++) {
        currentRoll  = defenseDice[i]->roll();
        defenseTotal += currentRoll;
        // Print the roll for the current die
//        cout << " die " << (i + 1) << " (" << currentRoll << ")";
    }
//    cout << " for a defense total of " << defenseTotal << endl;

    // Calculate damage and adjust strength
    int damage = max(attackScore - defenseTotal - this->getArmor(), 0);
    int newStrength = this->getStrength() - damage;
    this->setStrength(newStrength);

//    cout << "Total inflicted damage: " << damage << endl;
//    cout << this->getType() << "'s new strength: " << this->getStrength() << endl;
//    cout << endl;
}

void HarryPotter::resetStrength() {
    // Harry Potter's strength is reset to 20 when he dies
    startStrength = 20;
    setStrength(startStrength);
//    cout << "Harry Potter activates Hogwarts and resets strength to 20!" << endl;
}
