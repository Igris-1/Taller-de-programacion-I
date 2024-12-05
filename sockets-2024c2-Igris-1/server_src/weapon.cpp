#include "weapon.h"

void Weapon::setName(const std::string& name) { this->name = name; }

void Weapon::load(int ammo) { this->ammo += ammo; }

std::string Weapon::getName() { return this->name; }

int Weapon::getAmunition() { return this->ammo; }
