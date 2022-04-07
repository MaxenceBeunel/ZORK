#include "game.h"

Game::Game()
{
    srand(time(0));
    CreateRooms();
    CreateInventory();
    CreateShop();
    CreatePrices();
    CreateConditions();
    money = 200;
}

void Game::CreateRooms()
{
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m, *n, *o, *p;

    a = new Room("Dwarf village center");
    a->SetDescription("Dwarf Village Center :\nThis is the main place of the village, all the dwarves are talking to each other.\nA dwarf wants to have 10 pisces, he could help you in exchange.");
    b = new Room("Chief's hut");
    b->SetDescription("Chief's hut :\nThe village chief is asking you to bring him 10 units of wheat.\nHe will surely give you something important in return.");
    c = new Room("Shop");
    c->SetDescription("Shop :\nThis is the shop, many items are exposed there.\nYou can buy or sell everything you want.\nTake care about your money !!!");
    d = new Room("Fields");
    d->SetDescription("Fields :\nYou are in the fields.\nHere, you can collect some wheat, a common resource.");
    e = new Room("Forest");
    e->SetDescription("Forest :\nYou are in the forest.\nHere, you can collect some wood, a common resource.");
    f = new Room("Bridge");
    f->SetDescription("Bridge :\nThis is where you can go to the other side of the river but the bridge is broken.\nYou need to have 20 units of wood to repair it.");
    g = new Room("Ancient dwarf statue");
    g->SetDescription("Ancient dwarf statue :\nThis is the place where you can admire the ancient dwarf statue, all Gods of the dwarfs are represented on it.\nWe can see that something is missing on this beautiful statue...\nMaybe an object can be very useful here.");
    h = new Room("Fishermen's hut");
    h->SetDescription("Fishermen's hut :\nYou are near to the fishermen.\nHere, you can collect some pisces, a common resource.\nA fisherman is sick, bring him 3 magic potions if you want him to give you a hint.");
    i = new Room("Mountain");
    i->SetDescription("Mountain :\nHere is the entrance to the mountain, but it's too dark.\nYou need to use a torch every time you go to a new room.");
    j = new Room("Forge");
    j->SetDescription("Forge :\nYou discover a forge, an anvil and a furnace are at your disposal.\nTry to bring some materials (5 coals, 5 bronzes, 5 silvers, 5 golds) if you want to build something.");
    k = new Room("Coal mine");
    k->SetDescription("Coal mine :\nYou are in the coal mine, there is coal all around you.\nTry to collect it with the pickaxe, this material must be useful.");
    l = new Room("Treasure room");
    l->SetDescription("Treasure room :\nA trunk is located in the center of the cave.\nYou need a key to open it.");
    m = new Room("Bronze vein mine");
    m->SetDescription("Bronze vein mine :\nYou are in the bronze vein mine, there are veins of bronze all around you.\nTry to collect it with the pickaxe, this material must be expensive and useful.");
    n = new Room("Silver vein mine");
    n->SetDescription("Silver vein mine :\nYou are in the silver vein mine, there are veins of silver all around you.\nTry to collect it with the pickaxe, this material must be expensive and useful.");
    o = new Room("Gold vein mine");
    o->SetDescription("Gold vein mine :\nYou are in the gold vein mine, there are veins of gold all around you.\nTry to collect it with the pickaxe, this material must be expensive and useful.");
    p = new Room("Big diamond room");
    p->SetDescription("Big crystal cave :\nThis is the big crystal cave, the crystal embedded in the rock shines with a thousand lights.\nMine it then put it back on the ancient dwarf statue to win.");

    a->SetNeighbors(f, b, c, d);
    b->SetNeighbors(NULL, NULL, NULL, a);
    c->SetNeighbors(a, NULL, NULL, NULL);
    d->SetNeighbors(NULL, a, e, NULL);
    e->SetNeighbors(d, NULL, NULL, NULL);
    f->SetNeighbors(g, NULL, a, NULL);
    g->SetNeighbors(NULL, i, f, h);
    h->SetNeighbors(NULL, g, NULL, NULL);
    i->SetNeighbors(j, k, NULL, g);
    j->SetNeighbors(NULL, NULL, i, NULL);
    k->SetNeighbors(NULL, m, l, i);
    l->SetNeighbors(k, NULL, NULL, NULL);
    m->SetNeighbors(n, NULL, NULL, k);
    n->SetNeighbors(o, NULL, m, NULL);
    o->SetNeighbors(NULL, NULL, n, p);
    p->SetNeighbors(NULL, o, NULL, NULL);

    roomList.push_back(*a);
    roomList.push_back(*b);
    roomList.push_back(*c);
    roomList.push_back(*d);
    roomList.push_back(*e);
    roomList.push_back(*f);
    roomList.push_back(*g);
    roomList.push_back(*h);
    roomList.push_back(*i);
    roomList.push_back(*j);
    roomList.push_back(*k);
    roomList.push_back(*l);
    roomList.push_back(*m);
    roomList.push_back(*n);
    roomList.push_back(*o);
    roomList.push_back(*p);

    currentRoom = a;
}

void Game::CreateInventory()
{
    inventory["Wood"] = 0;
    inventory["Pisces"] = 0;
    inventory["Wheat"] = 0;
    inventory["Coal"] = 0;
    inventory["Bronze"] = 0;
    inventory["Silver"] = 0;
    inventory["Gold"] = 0;
    inventory["Crystal"] = 0;
    inventory["Sword"] = 0;
    inventory["Pickaxe"] = 0;
    inventory["Magic potion"] = 0;
    inventory["Torch"] = 0;
    inventory["Runaway powder"] = 0;
    inventory["Key"] = 0;
    inventory["Sacred scroll"] = 0;
}

void Game::CreateShop()
{
    shopList.push_back("Wood");
    shopList.push_back("Pisces");
    shopList.push_back("Wheat");
    shopList.push_back("Coal");
    shopList.push_back("Bronze");
    shopList.push_back("Silver");
    shopList.push_back("Gold");
    shopList.push_back("Sword");
    shopList.push_back("Pickaxe");
    shopList.push_back("Magic potion");
    shopList.push_back("Torch");
    shopList.push_back("Runaway powder");
}

void Game::CreatePrices()
{
    prices["Wood"] = 10;
    prices["Pisces"] = 5;
    prices["Wheat"] = 5;
    prices["Coal"] = 15;
    prices["Bronze"] = 25;
    prices["Silver"] = 50;
    prices["Gold"] = 100;
    prices["Crystal"] = 0;
    prices["Sword"] = 75;
    prices["Pickaxe"] = 50;
    prices["Magic potion"] = 20;
    prices["Torch"] = 10;
    prices["Runaway powder"] = 10;
    prices["Key"] = 0;
    prices["Sacred scroll"] = 0;
}

void Game::CreateConditions()
{
    conditions["Dwarf village center"] = true;
    conditions["Chief's hut"] = true;
    conditions["Shop"] = true;
    conditions["Fields"] = true;
    conditions["Forest"] = true;
    conditions["Bridge"] = true;
    conditions["Ancient dwarf statue"] = false;
    conditions["Fishermen's hut"] = true;
    conditions["Mountain"] = true;
    conditions["Forge"] = false;
    conditions["Coal mine"] = false;
    conditions["Treasure room"] = false;
    conditions["Bronze vein mine"] = false;
    conditions["Silver vein mine"] = false;
    conditions["Gold vein mine"] = false;
    conditions["Big diamond room"] = false;
}

vector<Room> Game::GetRoomList()
{
    return roomList;
}

Room* Game::GetCurrentRoom()
{
    return currentRoom;
}

int Game::GetMoney()
{
    return money;
}

vector<string> Game::GetShopList()
{
    return shopList;
}

void Game::SetCurrentRoom(Room *room)
{
    currentRoom = room;
}

void Game::GoTo(string direction)
{
    Room* room = currentRoom->GetNeighbor(direction);
    if (room != NULL)
    {
        if (conditions[room->GetName()])
            currentRoom = room;
        else if (room->GetName() == "Ancient dwarf statue" && inventory["Wood"] >= 20)
        {
            inventory["Wood"] -= 20;
            conditions["Ancient dwarf statue"] = true;
            currentRoom = room;
        }
        else if (room->GetName() != "Big diamond room" && inventory["Torch"] > 0)
        {
            inventory["Torch"]--;
            conditions[room->GetName()] = true;
            currentRoom = room;
        }
    }
}

bool Game::BuyItem(Item item)
{
    if (currentRoom->GetName() == "Shop" && item.GetPrice() > 0)
    {
        if (money >= item.GetPrice())
        {
            money -= item.GetPrice();
            inventory[item.GetName()]++;
            return true;
        }
    }
    return false;
}

bool Game::SellItem(Item item)
{
    if (currentRoom->GetName() == "Shop")
    {
        if (inventory[item.GetName()] > 0)
        {
            inventory[item.GetName()]--;
            money += item.GetPrice();
            return true;
        }
    }
    return false;
}

bool Game::Collect()
{
    int count = (rand() % 4) + 1;
    if (*currentRoom == "Forest")
    {
        inventory["Wood"] += count;
        return true;
    }
    if (*currentRoom == "Fishermen's hut")
    {
        inventory["Pisces"] += count;
        return true;
    }
    if (*currentRoom == "Fields")
    {
        inventory["Wheat"] += count;
        return true;
    }
    return false;
}

bool Game::Mine()
{
    int count = (rand() % 4) + 1;
    if (*currentRoom == "Coal mine")
    {
        inventory["Coal"] += count;
        return true;
    }
    if (*currentRoom == "Bronze vein mine")
    {
        inventory["Bronze"] += count;
        return true;
    }
    if (*currentRoom == "Silver vein mine")
    {
        inventory["Silver"] += count;
        return true;
    }
    if (*currentRoom == "Gold vein mine")
    {
        inventory["Gold"] += count;
        return true;
    }
    if (*currentRoom == "Big diamond room")
    {
        inventory["Crystal"]++;
        return true;
    }
    return false;
}

bool Game::Teleport()
{
    if (inventory["Runaway powder"] > 0)
    {
        inventory["Runaway powder"]--;
        currentRoom = &roomList[0];
        return true;
    }
    return false;
}

bool Game::Trade()
{
    if (currentRoom->GetName() == "Chief's hut")
    {
        if (inventory["Wheat"] >= 10)
        {
            inventory["Wheat"] -= 10;
            return true;
        }
    }
    if (currentRoom->GetName() == "Dwarf village center")
    {
        if (inventory["Pisces"] >= 10)
        {
            inventory["Pisces"] -= 10;
            return true;
        }
    }
    if (currentRoom->GetName() == "Fishermen's hut")
    {
        if (inventory["Magic potion"] >= 3)
        {
            inventory["Magic potion"] -= 3;
            return true;
        }
    }
    return false;
}

bool Game::Forge()
{
    if (inventory["Coal"] >= 5 && inventory["Bronze"] >= 5 && inventory["Silver"] >= 5 && inventory["Gold"] >= 5)
    {
        inventory["Coal"] -= 5;
        inventory["Bronze"] -= 5;
        inventory["Silver"] -= 5;
        inventory["Gold"] -= 5;
        inventory["Key"]++;
        return true;
    }
    return false;
}

bool Game::OpenChest()
{
    if (inventory["Key"] > 0)
    {
        inventory["Key"]--;
        inventory["Sacred scroll"]++;
        return true;
    }
    return false;
}

bool Game::ToWin()
{
    if (inventory["Crystal"] > 0 && inventory["Sacred scroll"] > 0 && inventory["Sword"] > 0)
    {
        inventory["Crystal"]--;
        inventory["Sacred scroll"]--;
        inventory["Sword"]--;
        return true;
    }
    return false;
}

Item Game::ToItem(string name)
{
    Item* item = new Item(name, prices[name]);
    return *item;
}
