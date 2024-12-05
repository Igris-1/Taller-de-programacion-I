#ifndef WEAPON_H
#define WEAPON_H

#include <string>

#include "../common_src/constants.h"

class Weapon {
private:
    // Weapon name
    std::string name;

    // Weapon ammo
    int ammo;

public:
    explicit Weapon(const std::string& name): name(name), ammo(INI) {}

    Weapon(): name("Not Equipped"), ammo(INI) {}

    // Carga el arma con la cantidad de municiones pasada por parametro
    void load(int ammo);

    // Setea el nombre del arma
    void setName(const std::string& name);

    // Devuelve el nombre del arma
    std::string getName();

    // Devuelve la cantidad de municiones del arma
    int getAmunition();
};
#endif
