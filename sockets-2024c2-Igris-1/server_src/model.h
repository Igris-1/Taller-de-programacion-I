#ifndef MODEL_H
#define MODEL_H

#include <string>

#include "weapon.h"
#include "weapons.h"

class Model {
private:
    // Available weapons
    Weapons weapons;

    // Equipped weapons
    Weapon primary_weapon;
    Weapon secondary_weapon;
    bool knife_equipped;

public:
    Model():
            weapons(Weapons()),
            primary_weapon(Weapon()),
            secondary_weapon(Weapon()),
            knife_equipped(false) {}

    // ejecuta los comandos recibidos
    void command(std::string commands);

    // devuelve el nombre del arma primaria
    std::string getNamePrimaryWeapon();

    // devuelve la municion del arma primaria
    int getAmmoPrimaryWeapon();

    // devuelve el nombre del arma secundaria
    std::string getNameSecondaryWeapon();

    // devuelve la municion del arma secundaria
    int getAmmoSecondaryWeapon();

    // devuelve si el cuchillo esta equipado
    int getKnifeEquipped();
};

#endif
