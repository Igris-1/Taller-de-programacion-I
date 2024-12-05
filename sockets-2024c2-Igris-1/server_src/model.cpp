#include "model.h"

#include <iostream>

#include "../common_src/constants.h"

void Model::command(std::string commands) {
    for (int i = INIT_POS; commands[i] != '\0'; ++i) {
        int c = std::stoi(std::string(1, commands[i]));

        if (c >= SECONDARY_START && c <= SECONDARY_END) {
            secondary_weapon = Weapon(weapons.getWeapon(c));
            std::cout << secondary_weapon.getName() << std::endl;

        } else if (c >= PRIMARY_START && c <= PRIMARY_END) {
            primary_weapon = Weapon(weapons.getWeapon(c));
            std::cout << primary_weapon.getName() << std::endl;

        } else if (c == SECONDARY_LOAD) {
            if (secondary_weapon.getName() != "Not Equipped") {
                secondary_weapon.load(LOAD_SECONDARY);
            }
            std::cout << "Secondary Ammo: " << secondary_weapon.getAmunition() << std::endl;

        } else if (c == PRIMARY_LOAD) {
            if (primary_weapon.getName() != "Not Equipped") {
                primary_weapon.load(LOAD_PRIMARY);
            }
            std::cout << "Primary Ammo: " << primary_weapon.getAmunition() << std::endl;

        } else if (c == KNIFE) {
            knife_equipped = !knife_equipped;
            std::cout << (knife_equipped ? "Equipped knife" : "Knife not equipped") << std::endl;
        }
    }
}

std::string Model::getNamePrimaryWeapon() { return primary_weapon.getName(); }

int Model::getAmmoPrimaryWeapon() { return primary_weapon.getAmunition(); }

std::string Model::getNameSecondaryWeapon() { return secondary_weapon.getName(); }

int Model::getAmmoSecondaryWeapon() { return secondary_weapon.getAmunition(); }

int Model::getKnifeEquipped() { return knife_equipped ? EQUIPPED : NOT_EQUIPPED; }
