#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item
{
protected:
    string name;
    string description;
    int price;
public:
    Item();
    Item(string name, int price);
    bool operator== (Item item);
    string GetName();
    int GetPrice();
};

#endif // ITEM_H
