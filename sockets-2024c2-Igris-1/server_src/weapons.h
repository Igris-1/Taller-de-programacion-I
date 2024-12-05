#ifndef ARMORY_H
#define ARMORY_H


#include <iostream>
#include <map>
#include <string>


class Weapons {
private:
    std::map<int, std::string> dictionary;

public:
    Weapons():
            dictionary({{1, "Banana"},
                        {2, "Magnum"},
                        {3, "Old Pistol"},
                        {4, "Pew Pew Laser"},
                        {5, "Phaser"},
                        {6, "Chaindart"},
                        {7, "Secondary Ammo"},
                        {8, "Primary Ammo"},
                        {9, "Knife"}}) {}

    std::string getWeapon(int id);
};

#endif
