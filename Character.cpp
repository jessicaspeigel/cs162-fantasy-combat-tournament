/****************************************************
** Author: Jessica Speigel
** Assignment: CS162 cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: 
****************************************************/
#include "Character.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

Character::Character(std::string charType, int armor, int strength, int numLives) {
    this->charType = charType;
    this->name = charType;
    this->armor = armor;
    this->currentStrength = strength;
    this->startStrength = strength;
    this->numLives = numLives;
    this->isDead = false;
    this->currentLife = 0;
}

Character::~Character() {

}


int Character::getArmor() {
    return armor;
}

int Character::getStrength() {
    return currentStrength;
}

void Character::setStrength(int strength) {
    this->currentStrength = strength;
    if (strength <= 0) {
        death();
    }
}

roll_t Character::getAttack() {
    return attackRoll;
}

roll_t Character::getDefense() {
    return defenseRoll;
}

string Character::getType() {
    return charType;
}

void Character::death() {
    // Increment the current life
    currentLife++;
    // Check to see if they're out of lives
    if (currentLife == numLives) {
        isDead = true;
    } else {
        // Tell the user what happened and how many lives are left
//        cout << getType() << " has lost a life. They have " << (numLives - currentLife) << " life left." << endl;
        resetStrength();
    }
}

bool Character::isAlive() {
    return !isDead;
}

void Character::resetStrength() {
    setStrength(startStrength);
}

std::string Character::getName() {
    return name;
}

void Character::setName(std::string name) {
    // Only set the name if the string is more than 1 character
    if (name.length() > 0) {
        this->name = name;
    }
}

int Character::getStrengthCapacity() {
    return startStrength;
}

void Character::recover() {
    // Recovers the character by a random amount
    int recoveryAmount = rand() % (getStrengthCapacity() - getStrength());
    // Set the strength
    setStrength(getStrength() + recoveryAmount);
    // Print some shit
    cout << this->getName() << " is recovered!" << endl;
    cout << "Strength capacity: " << getStrengthCapacity() << " / Current strength: " << getStrength() << " / Random recovery amount: " << recoveryAmount << endl;
}
