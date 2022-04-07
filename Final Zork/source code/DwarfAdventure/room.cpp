#include "room.h"

Room::Room(string name)
{
    this->name = name;
}

void Room::SetNeighbors(Room* north, Room* east, Room* south, Room* west)
{
    if (north != NULL)
        neighbors["north"] = north;
    if (east != NULL)
        neighbors["east"] = east;
    if (south != NULL)
        neighbors["south"] = south;
    if (west != NULL)
        neighbors["west"] = west;
}

Room* Room::GetNeighbor(string direction)
{
    return neighbors[direction];
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

bool Room::operator== (string room)
{
    return this->name == room;
}
