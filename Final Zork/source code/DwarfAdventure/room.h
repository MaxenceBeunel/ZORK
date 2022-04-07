#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <map>
#include "item.h"
#include "weapon.h"

using namespace std;

class Room
{
private:
    string name;
    string description;
    map<string, Room*> neighbors;

public:
    Room(string name);
    void SetNeighbors(Room* north, Room* east, Room* south, Room* west);
    Room* GetNeighbor(string direction);
    void SetDescription(string desription);
    string GetDescription();
    string GetName();
    bool operator== (string room);
};

#endif // ROOM_H
