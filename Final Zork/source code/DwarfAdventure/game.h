#ifndef GAME_H
#define GAME_H

#include <vector>
#include <fstream>
#include <iostream>
#include "room.h"

using namespace std;
using std::vector;

class Game
{
private:
    vector<Room> roomList;
    Room* currentRoom;
    int money;
    vector<string> shopList;

public:
    ::map<string, int> inventory;
    ::map<string, int> prices;
    ::map<string, bool> conditions;

    Game();
    void CreateRooms();
    void CreateInventory();
    void CreateShop();
    void CreatePrices();
    void CreateConditions();

    vector<Room> GetRoomList();
    Room* GetCurrentRoom();
    int GetMoney();
    vector<string> GetShopList();

    void SetCurrentRoom(Room* room);
    void GoTo(string direction);
    bool BuyItem(Item item);
    bool SellItem(Item item);
    bool Collect();
    bool Mine();
    bool Teleport();
    bool Trade();
    bool Forge();
    bool OpenChest();
    bool ToWin();
    Item ToItem(string name);
};

#endif // GAME_H
