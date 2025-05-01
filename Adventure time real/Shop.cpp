#include "Shop.h"
#include <iostream>

Shop::Shop() : armor(0), damageBoost(0) {}

int Shop::getArmor() const {
    return armor;
}

int Shop::getDamageBoost() const {
    return damageBoost;
}

void Shop::open(PlayerStats& player) {
    int choice;

    while (true) {
        std::cout << "\n--- Shop Menu ---\n";
        std::cout << "Your Money: " << player.getMoney() << "\n";
        std::cout << "1. +15 Health (Cost: 10 coins)\n";
        std::cout << "2. +1 Armor (reduces damage by 1, Cost: 15 coins)\n";
        std::cout << "3. +1 Damage Boost (adds +1 to attack, Cost: 20 coins)\n";
        std::cout << "4. Leave Shop\n";
        std::cout << "Choose an option: ";

        std::cin >> choice;

        if (choice == 1) {
            if (player.getMoney() >= 10) {
                player.changeMoney(-10);
                player.changeHealth(15);
                std::cout << "You gained 15 health!\n";
            }
            else {
                std::cout << "Not enough coins!\n";
            }
        }
        else if (choice == 2) {
            if (player.getMoney() >= 15) {
                player.changeMoney(-15);
                armor += 3;
                std::cout << "Armor increased! You now have " << armor << " armor.\n";
            }
            else {
                std::cout << "Not enough coins!\n";
            }
        }
        else if (choice == 3) {
            if (player.getMoney() >= 20) {
                player.changeMoney(-20);
                damageBoost += 3;
                std::cout << "Damage boost increased! You now deal +" << damageBoost << " extra damage.\n";
            }
            else {
                std::cout << "Not enough coins!\n";
            }
        }
        else if (choice == 4) {
            std::cout << "Leaving shop...\n";
            break;
        }
        else {
            std::cout << "Invalid choice.\n";
        }
    }
}