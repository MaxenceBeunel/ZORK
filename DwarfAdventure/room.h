#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <array>

using namespace std;

class Room
{
private:
    string name;
    string description;
    array<Room*, 4> neighbors;

public:
    Room(string name, string desription);
    void SetNeighbors(Room* north, Room* east, Room* south, Room* west);
    Room* GetNeighbor(char direction);
    void SetDescription(string desription);
    string GetDescription();
    string GetName();
};

#endif // ROOM_H
