#include "room.h"

Room::Room(string name, string description)
{
    this->name = name;
    this->description = description;
}

void Room::SetNeighbors(Room* north, Room* east, Room* south, Room* west)
{
    neighbors.at(0) = north;
    neighbors.at(1) = east;
    neighbors.at(2) = south;
    neighbors.at(3) = west;
}

Room* Room::GetNeighbor(char direction)
{
    switch (direction)
    {
        case 'n':
            return neighbors.at(0);
        case 'e':
            return neighbors.at(1);
        case 's':
            return neighbors.at(2);
        case 'w':
            return neighbors.at(3);
        default:
            return NULL;
    }
}

void Room::SetDescription(string description)
{
    this->description = description;
}

string Room::GetDescription()
{
    return description;
}

string Room::GetName()
{
    return name;
}
