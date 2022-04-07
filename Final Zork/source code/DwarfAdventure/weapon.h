#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"

class Weapon : public Item
{
private:
    int power;
public:
    Weapon();
    Weapon(string name, int price, int power);
};

#endif // WEAPON_H
