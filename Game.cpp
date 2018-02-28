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
    // Create Team 1
    team1 = new Queue;
    team1Score = 0;
    cout << "Team 1:" << endl;
    int team1NumPlayers = getIntegerWithMin("How many fighters should Team 1 have? (Min. 1)", 1);
    for (int i = 0; i < team1NumPlayers; i++) {
        // Add a player
        int charType = 0;
        string name = "";
        Character* player = nullptr;
        charType = charMenu.showMenu();
        if (charType == 1) {
            // Vampire
            player = new Vampire;
        } else if (charType == 2) {
            // Barbarian
            player = new Barbarian;
        } else if (charType == 3) {
            // Blue Men
            player = new BlueMen;
        } else if (charType == 4) {
            // Medusa
            player = new Medusa;
        } else if (charType == 5) {
            // Harry Potter
            player = new HarryPotter;
        }
        // Get a name
        name = getString("Enter a name for your fighter:", 0);
        player->setName(name);
        team1->addBack(player);
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
        Character* player = nullptr;
        charType = charMenu.showMenu();
        if (charType == 1) {
            // Vampire
            player = new Vampire;
        } else if (charType == 2) {
            // Barbarian
            player = new Barbarian;
        } else if (charType == 3) {
            // Blue Men
            player = new BlueMen;
        } else if (charType == 4) {
            // Medusa
            player = new Medusa;
        } else if (charType == 5) {
            // Harry Potter
            player = new HarryPotter;
        }
        // Get a name
        name = getString("Enter a name for your fighter:", 0);
        player->setName(name);
        team2->addBack(player);
    }
    // Create the loser queue
    losers = new Queue;
    // Start the game
    startGame();
}

//Game::Game() {
//    // Default constructor prompts user to select characters
//    int p1Choice = 0, p2Choice = 0;
//    vector<string> charMenuItems = {"Vampire", "Barbarian", "Blue Men", "Medusa", "Harry Potter"};
//    Menu charMenu(charMenuItems);
//    // Prompt for player 1
//    charMenu.setPromptText("Select a character for player 1");
//    p1Choice = charMenu.showMenu();
//    // Create player1
//    Character* p1 = nullptr;
//    if (p1Choice == 1) {
//        // Vampire
//        p1 = new Vampire;
//    } else if (p1Choice == 2) {
//        // Barbarian
//        p1 = new Barbarian;
//    } else if (p1Choice == 3) {
//        // Blue Men
//        p1 = new BlueMen;
//    } else if (p1Choice == 4) {
//        // Medusa
//        p1 = new Medusa;
//    } else if (p1Choice == 5) {
//        // Harry Potter
//        p1 = new HarryPotter;
//    }
//    setPlayer1(p1);
//    // Prompt for player 2
//    charMenu.setPromptText("Select a character for player 2");
//    p2Choice = charMenu.showMenu();
//    // Create player2
//    Character* p2 = nullptr;
//    if (p2Choice == 1) {
//        // Vampire
//        p2 = new Vampire;
//    } else if (p2Choice == 2) {
//        // Barbarian
//        p2 = new Barbarian;
//    } else if (p2Choice == 3) {
//        // Blue Men
//        p2 = new BlueMen;
//    } else if (p2Choice == 4) {
//        // Medusa
//        p2 = new Medusa;
//    } else if (p2Choice == 5) {
//        // Harry Potter
//        p2 = new HarryPotter;
//    }
//    setPlayer2(p2);
//    // Start the game
//    startGame();
//}

/****************************************************
** DESTRUCTORS
****************************************************/

Game::~Game() {
    // Delete the team queues and loser queue
    delete team1;
    delete team2;
    delete losers;
}

/****************************************************
** GETTERS / SETTERS
****************************************************/


/****************************************************
** Description: starts the game
****************************************************/

void Game::startGame() {
    // Initialize the fight number to 0
    fight = 0;
    // Clear cin
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.clear();
    do {
        if (fight > 0) {
            // Pause between fights
            string tmp;
            cout << "Press enter to run a new fight" << endl;
            getline(cin, tmp);
        }
        // Run the next fight
        runFight();
        // Increment the fight counter
        fight++;
    } while (!team1->isEmpty() && !team2->isEmpty());
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
    // Initialize a flag to know if the game should keep going.
    bool everyoneAlive = true;
    // Clear cin
//    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//    cin.clear();
    do {
//        if (round > 0) {
//            // Pause between rounds
//            string tmp;
//            cout << "Press enter to run a new round" << endl;
//            getline(cin, tmp);
//        }
        // Run the round
        everyoneAlive = runRound();
    } while (everyoneAlive);
}

/****************************************************
** Description: runs a round. Returns true if the
** game should continue (no one has died).
****************************************************/

bool Game::runRound() {
    bool everyoneAlive = true;

    // Increment the round
    round++;

    // Print a separator
    cout << "-------------------------------------------" << endl;

    // Print what round it is
    cout << "Round " << round << endl << endl;

    // Figure out who starts
    if (fight % 2 == 0) {
        // Team 1 goes first (Player 1)
        cout << "Player 1 attacks! " << endl;

        int attackTotal = player1->attack(player2);
        player2->defend(attackTotal);

        // Check to see if player2 is still alive
        if (player2->isAlive()) {
            // Then let player 2 attack
            cout << "Player 2 attacks!" << endl;

            attackTotal = player2->attack(player1);
            player1->defend(attackTotal);
            // Check to see if player 1 died in the attack
            if (!player1->isAlive()) {
                everyoneAlive = false;
                cout << "Player 1 has died." << endl;
            }
        } else {
            everyoneAlive = false;
            cout << "Player 2 has died." << endl;
        }
    } else {
        // Team 2 goes first (Player 2)
        cout << "Player 2 attacks! " << endl;

        int attackTotal = player2->attack(player1);
        player1->defend(attackTotal);

        // Check to see if player1 is still alive
        if (player1->isAlive()) {
            // Then let player 1 attack
            cout << "Player 1 attacks!" << endl;

            attackTotal = player1->attack(player2);
            player2->defend(attackTotal);
            // Check to see if player 2 died in the attack
            if (!player2->isAlive()) {
                everyoneAlive = false;
                cout << "Player 2 has died." << endl;
            }
        } else {
            everyoneAlive = false;
            cout << "Player 1 has died." << endl;
        }
    }

    // If someone is dead, take care of it
//    if (!everyoneAlive) {
//        // Figure out who died
//        if (player1->getStrength() <= 0) {
//            // Put player 1 in the loser pile
//            losers->addBack(team1->getFront());
//            // Heal player 2 and put them in the back of the queue
//            team2->addBack(team2->getFront());
//        } else if (player2->getStrength() <= 0) {
//            // Put player 2 in the loser pile
//            losers->addBack(team2->getFront());
//            // Heal player 1 and put them in the back of the queue
//            team1->addBack(team1->getFront());
//        }
//        // Remove the front item from each queue
//        team1->removeFront();
//        team2->removeFront();
//    }

    // Print a separator
    cout << "-------------------------------------------" << endl << endl;

    return everyoneAlive;
}