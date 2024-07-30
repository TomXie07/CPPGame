#pragma once

#include <string>
#include "Room.h"
class Room;
class Enemy {
public:
    Enemy(const std::string& name, int health, int damage, Room* room);
    std::string getName() const;
    int getHealth() const;
    void takeDamage(int amount);
    int getDamage() const;
private:
    std::string name;
    int health;
    int damage;
    Room* room;
};
