#pragma once

#include <string>
#include <vector>
#include "Item.h"
#include "Enemy.h"
class Enemy;
class Room {
public:
    Room(const std::string& name, const std::string& description);
    std::string getName() const;
    std::string getDescription() const;
    void addItem(const Item& item);
    Item* getItem(const std::string& itemName);
    std::vector<Item> getItems();
    void setEnemy(Enemy* enemy);
    Enemy* getEnemy() const;
private:
    std::string name;
    std::string description;
    std::vector<Item> items;
    Enemy* enemy;
};
