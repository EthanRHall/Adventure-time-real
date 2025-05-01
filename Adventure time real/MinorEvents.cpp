#include "MinorEvents.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>

void CoinEvent::trigger(PlayerStats& player) {
    int coins = rand() % 10 + 1;
    player.changeMoney(coins);
    std::cout << "You found " << coins << " coins! Total money: " << player.getMoney() << "\n";
}

void EnemyEvent::trigger(PlayerStats& player) {
    int enemies = rand() % 3 + 1;
    int totalDamage = 0;

    for (int i = 0; i < enemies; ++i) {
        int enemyAttack = rand() % 10 + 5; // 5-14 damage
        totalDamage += enemyAttack;
    }

    std::cout << "You encountered " << enemies << " enemies and took " << totalDamage << " damage.\n";
    player.changeHealth(-totalDamage);
    std::cout << "Current health: " << player.getHealth() << "\n";
}

void PuzzleEvent::loadPuzzles() {
    puzzles = {
        {"What is 5 + 7?", "12"},
        {"What is 8 * 6?", "48"},
        {"What is 15 - 4?", "11"},
        {"What has keys but can't open locks?", "piano"},
        {"What gets wetter the more it dries?", "towel"}
    };
}

void PuzzleEvent::trigger(PlayerStats& player) {
    if (puzzles.empty()) loadPuzzles();
    auto puzzle = puzzles[rand() % puzzles.size()];
    std::cout << "Puzzle: " << puzzle.first << "\n";

    std::string answer;
    int attempts = 3;
    while (attempts--) {
        std::getline(std::cin, answer);
        std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
        if (answer == puzzle.second) {
            std::cout << "Correct!\n";
            return;
        }
        else {
            std::cout << "Incorrect. Attempts left: " << attempts << "\n";
        }
    }

    std::cout << "You failed the puzzle. The answer was: " << puzzle.second << "\n";
    std::cout << "The riddler shoots you. You lose 25 HP.\n";
    player.changeHealth(-25);
    std::cout << "Current health: " << player.getHealth() << "\n";
}

void TriviaEvent::loadTrivia() {
    trivia = {
        {"What is the name of the first artificial satellite?", "sputnik"},
        {"What planet is known as the red planet?", "mars"},
        {"What force keeps satellites in orbit?", "gravity"},
        {"What’s the name of the telescope launched in 1990?", "hubble"},
        {"Who was the first person in space?", "yuri gagarin"}
    };
}

void TriviaEvent::trigger(PlayerStats& player) {
    if (trivia.empty()) loadTrivia();
    auto q = trivia[rand() % trivia.size()];
    std::cout << "Trivia: " << q.first << "\n";

    std::string answer;
    std::getline(std::cin, answer);
    std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

    if (answer == q.second) {
        std::cout << "Correct!\n";
    }
    else {
        std::cout << "Wrong! Correct answer was: " << q.second << "\n";
    }
}
