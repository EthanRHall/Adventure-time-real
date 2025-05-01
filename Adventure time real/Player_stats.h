
#ifndef PLAYERSTATS_H
#define PLAYERSTATS_H

class PlayerStats {
private:
    int health;
    int money;

public:
    PlayerStats();

    int getHealth() const;
    void changeHealth(int amount);
    void resetHealth();

    int getMoney() const;
    void changeMoney(int amount);

    int attack(); // returns damage dealt if attack hits
    bool block(); // returns true if block is active
};

#endif
