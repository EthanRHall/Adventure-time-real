#include "Main_events.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <chrono>
#include <thread>
#include <algorithm>
#include "Shop.h"
#include <SFML/Audio.hpp>  // Assuming you have SFML for sound
using namespace std;
using namespace sf;

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

    sf::SoundBuffer soldierbuffer;
    soldierbuffer.loadFromFile("Main_event_2_soldiers.wav");
    sf::Sound soldiers(soldierbuffer);
    soldiers.play();
    std::this_thread::sleep_for(std::chrono::seconds(4));

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
            player.changeHealth(-enemyDamage); 
        }
    }

    if (player.getHealth() <= 0) {
        cout << "You and Jim have fallen in battle...\n";
    }
    else {
        cout << "You defeated all enemies!\n";

        sf::SoundBuffer buffer;
        buffer.loadFromFile("you win.wav");
        sf::Sound sound(buffer);
        sound.play();
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
}


// start of main event 3_________________________________________________________________


void MainEvent3::start(PlayerStats& player) {
    srand(static_cast<unsigned int>(time(0)));
    int soundNumber = rand() % 5;
    int attempts = 0;
    const int maxAttempts = 3;
    std::string playerAnswer;
    bool correct = false;
    std::string correctAnswer;

    // Play sound and wait
    switch (soundNumber) {
    case 0: {
        sf::SoundBuffer buffer;
        buffer.loadFromFile("Biden.wav");
        sf::Sound sound(buffer);
        sound.play();
        std::this_thread::sleep_for(std::chrono::seconds(8));
        correctAnswer = "joe biden";
        break;
    }
    case 1: {
        sf::SoundBuffer buffer;
        buffer.loadFromFile("Trump.wav");
        sf::Sound sound(buffer);
        sound.play();
        std::this_thread::sleep_for(std::chrono::seconds(10));
        correctAnswer = "donald trump";
        break;
    }
    case 2: {
        sf::SoundBuffer buffer;
        buffer.loadFromFile("Lois.wav");
        sf::Sound sound(buffer);
        sound.play();
        std::this_thread::sleep_for(std::chrono::seconds(10));
        correctAnswer = "lois griffin";
        break;
    }
    case 3: {
        sf::SoundBuffer buffer;
        buffer.loadFromFile("Stallone.wav");
        sf::Sound sound(buffer);
        sound.play();
        std::this_thread::sleep_for(std::chrono::seconds(10));
        correctAnswer = "sylvester stallone";
        break;
    }
    case 4: {
        sf::SoundBuffer buffer;
        buffer.loadFromFile("Jennifer Coolidge.wav");
        sf::Sound sound(buffer);
        sound.play();
        std::this_thread::sleep_for(std::chrono::seconds(10));
        correctAnswer = "jennifer coolidge";
        break;
    }
    }

    // Guessing loop
    while (attempts < maxAttempts && !correct) {
        std::cout << "Whose voice was I impersonating?? ";
        if (attempts == 0) std::cin.ignore();
        std::getline(std::cin, playerAnswer);

        std::transform(playerAnswer.begin(), playerAnswer.end(), playerAnswer.begin(), ::tolower);
        std::transform(correctAnswer.begin(), correctAnswer.end(), correctAnswer.begin(), ::tolower);

        if (playerAnswer == correctAnswer) {
            correct = true;
        }
        else {
            attempts++;
            if (attempts < maxAttempts) {
                std::cout << "Incorrect. Try again (" << (maxAttempts - attempts) << " attempts left)." << std::endl;
            }
        }
    }

    if (correct) {
        std::cout << "Correct! You won and we won't kill you! Sorry, but I didn't tell you so it was more exciting for the viewers!" << std::endl;
        player.changeMoney(50);
    }
    else {
        std::cout << "You lose! Bye buddy :) *The podium blows up and you and Jim die instantly*" << std::endl;
        player.changeHealth(-100);
    }
}


void MainEvent4::start(PlayerStats& player) {
    srand(static_cast<unsigned int>(time(0)));

    int enemyHealth = 100;

    while (enemyHealth > 0 && player.getHealth() > 0) {
        std::cout << "\Old man's Health: " << enemyHealth << "\n";
        std::cout << "Your Health: " << player.getHealth() << "\n";

        int enemyChoice = rand() % 4;

        if (enemyChoice < 1.1) {
            // Enemy attacks
            bool enemyHits = (rand() % 2) == 0;
            if (enemyHits) {
                int damage = 8 + rand() % 3;
                std::cout << "the old man stabbed you for " << damage << " damage!\n";
                player.changeHealth(-damage);
            }
            else {
                std::cout << "The old man missed!\n";
            }
        }
        else {
            // old man sings
            int soundNumber = rand() % 3;
            std::string correctAnswer;

            std::cout << "Alright Frank...guess the song and i'll let you get a free hit...\n";
            std::this_thread::sleep_for(std::chrono::seconds(5));

            switch (soundNumber) {
            case 0: {
                sf::SoundBuffer buffer;
                buffer.loadFromFile("american kids.wav");
                sf::Sound sound(buffer);
                sound.play();
                std::this_thread::sleep_for(std::chrono::seconds(10));
                correctAnswer = "american kids";
                break;
            }
            case 1: {
                sf::SoundBuffer buffer;
                buffer.loadFromFile("ms jackson.wav");
                sf::Sound sound(buffer);
                sound.play();
                std::this_thread::sleep_for(std::chrono::seconds(10));
                correctAnswer = "ms jackson";
                break;
            }
            case 2: {
                sf::SoundBuffer buffer;
                buffer.loadFromFile("renegade.wav");
                sf::Sound sound(buffer);
                sound.play();
                std::this_thread::sleep_for(std::chrono::seconds(10));
                correctAnswer = "renegade";
                break;
            }
            }

            std::string playerAnswer;
            std::cin.ignore();
            std::getline(std::cin, playerAnswer);

            std::transform(playerAnswer.begin(), playerAnswer.end(), playerAnswer.begin(), ::tolower);
            std::transform(correctAnswer.begin(), correctAnswer.end(), correctAnswer.begin(), ::tolower);

            if (playerAnswer == correctAnswer) {
                std::cout << "Not too bad... How did you even learn that?\n";
            }
            else {
                std::cout << "Wrong! HAHA, idiot! " << correctAnswer << ". In your shock the old man hit you for 10 damage.\n";
                player.changeHealth(-10);
            }
        }

        // Frank attacks
        std::cout << "\nYour turn! Type 'attack' to strike the enemy: ";
        std::string action;
        std::cin >> action;
        std::transform(action.begin(), action.end(), action.begin(), ::tolower);

        if (action == "attack") {
            int playerDamage = 12 + rand() % 4;
            std::cout << "You hit the old man for " << playerDamage << " damage!\n";
            enemyHealth -= playerDamage;
        }
        else {
            std::cout << "cmon... I explained the rules at the start!\n";
        }
    }

    if (player.getHealth() <= 0) {
        std::cout << "\nSomehow you lost to an old man...\n";
    }
    else {
        std::cout << "\nYou killed the old geezer! Nice job! Hopefully you didn't get tripped up on the old songs.\n";
        player.changeMoney(75);
    }
}