#include "Player_stats.h"

PlayerStats::PlayerStats() {
    health = 100;
    money = 0;
}

void PlayerStats::reset() {
    health = 100;
    money = 0;
}

void PlayerStats::loseHealth(int amount) {
    health -= amount;
    if (health < 0) health = 0;
}

void PlayerStats::addMoney(int amount) {
    money += amount;
}

int PlayerStats::getHealth() const {
    return health;
}

int PlayerStats::getMoney() const {
    return money;
}
