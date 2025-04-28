#pragma once

class PlayerStats {
private:
    int health;
    int money;
public:
    PlayerStats(); // constructor

    void reset(); // resets health and money to starting values
    void loseHealth(int amount);
    void addMoney(int amount);
    int getHealth() const;
    int getMoney() const;
};
