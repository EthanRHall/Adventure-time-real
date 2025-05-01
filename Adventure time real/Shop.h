#pragma once
#include "Player_stats.h"

class Shop {
private:
    
    int armor;        // Reduces damage taken
    int damageBoost;  // Increases attack damage

public:
    Shop();

    void open(PlayerStats& player);
    int getArmor() const;
    int getDamageBoost() const;

};