#ifndef GAME_H
#define GAME_H

#include <array>
#include <fstream>
#include "room.h"

using namespace std;

class Game
{
private:
    array<Room*, 16> roomList;
    Room* currentRoom;
public:
    Game();
    void CreateRooms();
    void SetExits();
    array<Room*, 16> GetRoomList();
    Room* GetCurrentRoom();
    void SetCurrentRoom(Room* room);
};

#endif // GAME_H
