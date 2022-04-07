#include "item.h"

Item::Item(string name, int price)
{
    this->name = name;
    this->price = price;
}

bool Item::operator== (Item item)
{
    return this->name == item.name;
}

string Item::GetName()
{
    return name;
}

int Item::GetPrice()
{
    return price;
}
