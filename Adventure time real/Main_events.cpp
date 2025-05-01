#include "Main_events.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>
#include "Shop.h"

//#include <SFML/Audio.hpp>  // Assuming you have SFML for sound
using namespace std;

Shop shop;

int armor = shop.getArmor();
int damage = shop.getDamageBoost();

void MainEvent1::start(PlayerStats& player) {
    srand(static_cast<unsigned int>(time(0))); // Seed random
    int puzzleNumber = rand() % 5; // Random number between 0 and 4
    int attempts = 0;
    const int maxAttempts = 3;
    string playerAnswer;
    bool solved = false;

    while (attempts < maxAttempts && !solved) {
        switch (puzzleNumber) {
        case 0:
            cout << "What is the integral of (e^x^2)dx?" << endl;
            cout << "Your answer: ";
            cin.ignore();
            getline(cin, playerAnswer);

            transform(playerAnswer.begin(), playerAnswer.end(), playerAnswer.begin(), ::tolower);

            if (playerAnswer == "n/a") {
                solved = true;
            }
            break;
        case 1:
            cout << "What is the principal the governs airflow off the trailing edge of an airfoil?" << endl;
            cout << "Your answer: ";
            cin.ignore();
            getline(cin, playerAnswer);

            // Lowercase the input
            transform(playerAnswer.begin(), playerAnswer.end(), playerAnswer.begin(), ::tolower);

            if (playerAnswer == "the kutta condition") {
                solved = true;
            }
            break;
        case 2:
            cout << "What do we call the angle that governs how far an object in orbit is from perigee?" << endl;
            cout << "Your answer: ";
            cin.ignore();
            getline(cin, playerAnswer);

            // Lowercase the input
            transform(playerAnswer.begin(), playerAnswer.end(), playerAnswer.begin(), ::tolower);

            if (playerAnswer == "true anomaly") {
                solved = true;
            }
            break;
        case 3:
            cout << "What do we call rocket fuels that ignite on contact with each other?" << endl;
            cout << "Your answer: ";
            cin.ignore();
            getline(cin, playerAnswer);

            // Lowercase the input
            transform(playerAnswer.begin(), playerAnswer.end(), playerAnswer.begin(), ::tolower);

            if (playerAnswer == "hypergolic") {
                solved = true;
            }
            break;
            break;
        case 4:
            cout << "True or false: there is more than one accepted way to describe lift." << endl;
            cout << "Your answer: ";
            cin.ignore();
            getline(cin, playerAnswer);

            // Lowercase the input
            transform(playerAnswer.begin(), playerAnswer.end(), playerAnswer.begin(), ::tolower);

            if (playerAnswer == "true") {
                solved = true;
            }
            break;

        default:
            cout << "Error loading puzzle." << endl;
            return;
        }

        if (!solved) {
            attempts++;
            if (attempts < maxAttempts) {
                cout << "Incorrect! Try again. (" << (maxAttempts - attempts) << " attempts left)" << endl;
            }
        }
    }

    if (solved) {
        cout << "Correct! You may pass." << endl;
        player.changeMoney(50); 
    }
    else {
        cout << "You failed the puzzle too many times. You and Jim have died." << endl;
        player.changeHealth(-100); 
    }
}

// beginning of main event 2____________________________________________________________

void MainEvent2::start(PlayerStats& player) {
    srand(static_cast<unsigned int>(time(0)));

    // SFML sound playback (beginning of encounter)
    //sf::SoundBuffer buffer;
    //if (!buffer.loadFromFile("encounter_start.wav")) {
   //     cerr << "Failed to load encounter_start.wav\n";
   // }
   // sf::Sound sound;
   // sound.setBuffer(buffer);
   // sound.play();

    const int enemyCount = 4;
    const int enemyHealth = 25 - armor;
    int enemiesRemaining = enemyCount;
    int currentEnemyHealth = enemyHealth;

    while (player.getHealth() > 0 && enemiesRemaining > 0) {
        cout << "\nEnemy " << (enemyCount - enemiesRemaining + 1) << " - Health: " << currentEnemyHealth << endl;
        cout << "Your Health: " << player.getHealth() << "\n";
        cout << "Choose action (attack/block): ";
        string action;
        cin >> action;

        transform(action.begin(), action.end(), action.begin(), ::tolower);

        // Player's Turn
        bool playerHit = (rand() % 100) < 75;
        int playerDamage = 10 + (rand() % 6) + damage; // 10 to 15

        if (action == "attack") {
            if (playerHit) {
                cout << "You hit the enemy for " << playerDamage << " damage!\n";
                currentEnemyHealth -= playerDamage; // Correct subtraction of damage
            }
            else {
                cout << "You missed!\n";
            }
        }
        else if (action == "block") {
            cout << "You brace for impact.\n";
        }
        else {
            cout << "Invalid action. You lose your turn!\n";
        }

        // Check if enemy is defeated after player's attack
        if (currentEnemyHealth <= 0) {
            cout << "Enemy defeated!\n";
            enemiesRemaining--;
            currentEnemyHealth = enemyHealth; // Reset enemy health for the next enemy
            continue; // Move to the next enemy
        }

        // Enemy's Turn
        bool enemyBlocks = (rand() % 100) < 25;
        int enemyDamage = 7 + (rand() % 4); // 7 to 10 damage

        if (enemyBlocks) {
            cout << "Enemy blocks your attack!\n";
        }
        else {
            cout << "Enemy attacks!\n";
            if (action == "block") {
                enemyDamage /= 2; // Block reduces damage
                cout << "You blocked part of the damage.\n";
            }
            cout << "You take " << enemyDamage << " damage.\n";
            player.changeHealth(-enemyDamage); // Subtract enemy damage from player health
        }
    }

    if (player.getHealth() <= 0) {
        cout << "You and Jim have fallen in battle...\n";
    }
    else {
        cout << "You defeated all enemies!\n";

        // SFML sound playback (end of encounter)
       // sf::SoundBuffer winBuffer;
       // if (!winBuffer.loadFromFile("victory_sound.wav")) {
       //     cerr << "Failed to load victory_sound.wav\n";
       // }
      //  sf::Sound winSound;
      //  winSound.setBuffer(winBuffer);
       // winSound.play();
    }
}


