#include "weapon.h"

Weapon::Weapon(string name, int price, int power) : Item(name, price)
{
    this->power = power;
}
