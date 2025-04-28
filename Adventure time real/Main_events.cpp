#include "Main_events.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>
using namespace std;

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
        player.addMoney(50); 
    }
    else {
        cout << "You failed the puzzle too many times. You and Jim have died." << endl;
        player.loseHealth(100); 
    }
}
