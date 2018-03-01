/****************************************************
** Author: Jessica Speigel
** Assignment: CS162 cs162_fantasy_combat_game
** Date: 02/12/2018
** Description: 
****************************************************/

#include "Game.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::max;

/****************************************************
** CONSTRUCTORS
****************************************************/

Game::Game() {
    // Default constructor sets up teams
    vector<string> charMenuItems = {"Vampire", "Barbarian", "Blue Men", "Medusa", "Harry Potter"};
    Menu charMenu("Choose a character:", charMenuItems);
    // Create a character pointer to hold the characters
    playerPtr = nullptr;
    // Create Team 1
    team1 = new Queue;
    team1Score = 0;
    cout << "Team 1:" << endl;
    int team1NumPlayers = getIntegerWithMin("How many fighters should Team 1 have? (Min. 1)", 1);
    for (int i = 0; i < team1NumPlayers; i++) {
        // Add a player
        int charType = 0;
        string name = "";
        charType = charMenu.showMenu();
        if (charType == 1) {
            // Vampire
            playerPtr = new Vampire;
        } else if (charType == 2) {
            // Barbarian
            playerPtr = new Barbarian;
        } else if (charType == 3) {
            // Blue Men
            playerPtr = new BlueMen;
        } else if (charType == 4) {
            // Medusa
            playerPtr = new Medusa;
        } else if (charType == 5) {
            // Harry Potter
            playerPtr = new HarryPotter;
        }
        // Get a name
        name = getString("Enter a name for your fighter:", 0);
        playerPtr->setName(name);
        team1->addBack(playerPtr);
    }
    // Create Team 2
    team2 = new Queue;
    team2Score = 0;
    cout << "Team 2:" << endl;
    int team2NumPlayers = getIntegerWithMin("How many fighters should Team 2 have? (Min. 1)", 1);
    for (int i = 0; i < team2NumPlayers; i++) {
        // Add a player
        int charType = 0;
        string name = "";
        charType = charMenu.showMenu();
        if (charType == 1) {
            // Vampire
            playerPtr = new Vampire;
        } else if (charType == 2) {
            // Barbarian
            playerPtr = new Barbarian;
        } else if (charType == 3) {
            // Blue Men
            playerPtr = new BlueMen;
        } else if (charType == 4) {
            // Medusa
            playerPtr = new Medusa;
        } else if (charType == 5) {
            // Harry Potter
            playerPtr = new HarryPotter;
        }
        // Get a name
        name = getString("Enter a name for your fighter:", 0);
        playerPtr->setName(name);
        team2->addBack(playerPtr);
    }
    // Create the loser queue
    losers = new Queue;
    // Start the game
    startGame();
}

/****************************************************
** DESTRUCTORS
****************************************************/

Game::~Game() {
    // Delete the team queues and loser queue
    delete team1;
    delete team2;
    delete losers;
    delete playerPtr;
}

/****************************************************
** Description: starts the game
****************************************************/

void Game::startGame() {
    // Initialize the fight number to 0
    fight = 1;
    do {
        // Run the next fight
        runFight();
        // Increment the fight counter
        fight++;
    } while (!team1->isEmpty() && !team2->isEmpty());
    endGame();
}

/****************************************************
** Description: ends the game
****************************************************/

void Game::endGame() {
    // Print a separator
    cout << "-------------------------------------------" << endl;
    cout << "Tournament over! Scores: " << endl;
    cout << "Team 1: " << team1Score << endl;
    cout << "Team 2: " << team2Score << endl;
    if (team1Score == team2Score) {
        cout << "It's a tie!" << endl;
    } else if (team1Score > team2Score) {
        cout << "Team 1 wins!" << endl;
    } else if (team2Score > team1Score) {
        cout << "Team 2 wins!" << endl;
    }
    // Get the menu ready
    vector<string> endMenuItems = {"Yes", "No"};
    Menu endMenu("Would you like to see the list of losers?", endMenuItems);
    int menuChoice = endMenu.showMenu();
    if (menuChoice == 1) {
        // Print the list of losers
        cout << "Players currently in the loser stack:" << endl;
        losers->printList();
    }
}

/****************************************************
** Description: runs a fight between players from
** both teams.
****************************************************/

void Game::runFight() {
    // Print a separator
    cout << "-------------------------------------------" << endl;

    // Print what fight it is
    cout << "FIGHT " << fight << endl << endl;
    // Reset the round number to 0
    round = 0;
    // Get the players ready
    player1 = team1->getFront();
    player2 = team2->getFront();
    cout << "Team 1 Player: " << player1->getName() << " (" << player1->getType() << ")" << endl;
    cout << "Team 2 Player: " << player2->getName() << " (" << player2->getType() << ")" << endl;
    // Initialize a flag to know if the game should keep going
    bool everyoneAlive = true;
    // Run rounds until someone bites it
    do {
        // Run the round
        everyoneAlive = runRound();
    } while (everyoneAlive);

    // Print a separator
//    cout << "-------------------------------------------" << endl;
//    cout << "Team 1 players:" << endl;
//    team1->printList();
//    cout << "Team 2 players:" << endl;
//    team2->printList();
//    cout << "Players currently in the loser stack:" << endl;
//    losers->printList();
}

/****************************************************
** Description: runs a round. Returns true if the
** game should continue (no one has died).
****************************************************/

bool Game::runRound() {
    bool everyoneAlive = true;
    // Increment the round
    round++;
    // Figure out who starts (Team 1 on even rounds, Team 2 on odd)
    if (fight % 2 == 0) {
        // Team 1 goes first (Player 1)
        int attackTotal = player1->attack(player2);
        player2->defend(attackTotal);
        // Check to see if player2 is still alive
        if (player2->isAlive()) {
            // Then let player 2 attack
            attackTotal = player2->attack(player1);
            player1->defend(attackTotal);
            // Check to see if player 1 died in the attack
            if (!player1->isAlive()) {
                everyoneAlive = false;
            }
        } else {
            everyoneAlive = false;
        }
    } else {
        // Team 2 goes first (Player 2)
        int attackTotal = player2->attack(player1);
        player1->defend(attackTotal);
        // Check to see if player1 is still alive
        if (player1->isAlive()) {
            attackTotal = player1->attack(player2);
            player2->defend(attackTotal);
            // Check to see if player 2 died in the attack
            if (!player2->isAlive()) {
                everyoneAlive = false;
            }
        } else {
            everyoneAlive = false;
        }
    }
    // If someone is dead, take care of it
    if (!everyoneAlive) {
        // Figure out who died
        if (player1->isAlive()) {
            // Team 1 won
            cout << player1->getName() << " won! Team 1 gets a point." << endl;
            // Put player 2 in the loser pile
            losers->addBack(player2);
            // Heal player 1 and put them in the back of the queue
            player1->recover();
            team1->addBack(player1);
            // Increment the team's score
            team1Score++;
        } else if (player2->isAlive()) {
            // Team 2 won
            cout << player2->getName() << " won! Team 2 gets a point." << endl;
            // Put player 1 in the loser pile
            losers->addBack(player1);
            // Heal player 2 and put them in the back of the queue
            player2->recover();
            team2->addBack(player2);
            // Increment the team's score
            team2Score++;
        }
        // Remove the front item from each queue
        team1->removeFront();
        team2->removeFront();
        // Set the players to null
        player1 = nullptr;
        player2 = nullptr;
    }

    return everyoneAlive;
}
