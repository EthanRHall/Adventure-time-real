#include "Player_stats.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

PlayerStats::PlayerStats() : health(100), money(0) {
    std::srand(static_cast<unsigned>(std::time(0)));
}

int PlayerStats::getHealth() const {
    return health;
}

void PlayerStats::changeHealth(int amount) {
    health += amount;

    if (health <= 0) {
        health = 0; // prevent negative health display
        cout << "Frank has died. Game Over.\n";
        exit(0); // Exit the program immediately
    }
}


void PlayerStats::resetHealth() {
    health = 100;
}

int PlayerStats::getMoney() const {
    return money;
}

void PlayerStats::changeMoney(int amount) {
    money += amount;
}

int PlayerStats::attack() {
    int hitChance = rand() % 100;
    if (hitChance < 75) {
        return 10 + rand() % 6; // 10-15 damage
    }
    return 0; // miss
}

bool PlayerStats::block() {
    return true; // For now, just mark block as active
}