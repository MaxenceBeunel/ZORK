#include "game.h"

Game::Game()
{
    CreateRooms();
    SetExits();
    /*this->currentRoom = roomList[0];*/
}

void Game::CreateRooms()
{
    ifstream file("room_name");
    string line;
    unsigned long i = 0;
    while (getline(file, line) && i < roomList.size())
    {
        roomList.at(i) = new Room(line, "");
        i++;
    }
}

void Game::SetExits()
{
    roomList.at(0)->SetNeighbors(nullptr, nullptr, nullptr, nullptr);
    /*roomList[1]->SetNeighbors(NULL, NULL, NULL, roomList[0]);
    roomList[2]->SetNeighbors(roomList[0], NULL, NULL, NULL);
    roomList[3]->SetNeighbors(NULL, roomList[0], roomList[4], NULL);
    roomList[4]->SetNeighbors(roomList[3], NULL, NULL, NULL);
    roomList[5]->SetNeighbors(roomList[6], NULL, roomList[0], NULL);
    roomList[6]->SetNeighbors(NULL, roomList[8], roomList[5], roomList[7]);
    roomList[7]->SetNeighbors(NULL, roomList[6], NULL, NULL);
    roomList[8]->SetNeighbors(roomList[9], roomList[10], NULL, roomList[6]);
    roomList[9]->SetNeighbors(NULL, NULL, roomList[8], NULL);
    roomList[10]->SetNeighbors(NULL, roomList[12], roomList[11], roomList[8]);
    roomList[11]->SetNeighbors(roomList[10], NULL, NULL, NULL);
    roomList[12]->SetNeighbors(roomList[13], NULL, NULL, roomList[10]);
    roomList[13]->SetNeighbors(roomList[14], NULL, roomList[12], NULL);
    roomList[14]->SetNeighbors(NULL, NULL, roomList[13], roomList[15]);
    roomList[15]->SetNeighbors(NULL, roomList[14], NULL, NULL);*/
}

array<Room*, 16> Game::GetRoomList()
{
    return roomList;
}

Room* Game::GetCurrentRoom()
{
    return currentRoom;
}

void Game::SetCurrentRoom(Room *room)
{
    currentRoom = room;
}
