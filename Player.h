#pragma once

#include <vector>
#include <string>
#include "Room.h"
#include "Item.h"

class Player {
public:
    Player();
    Room* getCurrentRoom() const;
    void setCurrentRoom(Room* room);
    void move(const std::string& direction, std::vector<Room> rooms);
    void takeItem(const std::string& itemName);
    void useItem(const std::string& itemName);
    std::vector<Item> getInventory();
    void attack();
    int getHealth() const;
    void enterRoom(Room* room);
private:
    Room* currentRoom;
    std::vector<Item> inventory;
    int health;
    int currentRoomIndex;
};
