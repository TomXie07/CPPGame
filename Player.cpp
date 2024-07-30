#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Player::Player() : currentRoom(nullptr), health(100) {
    std::srand(std::time(NULL));
    currentRoomIndex = 0;
}

Room* Player::getCurrentRoom() const {
    return currentRoom;
}

void Player::setCurrentRoom(Room* room) {
    currentRoom = room;
}

void Player::move(const std::string& direction, std::vector<Room> rooms) {
    // Placeholder for movement logic
    std::cout << "You move " << direction << ".\n";
    if (direction == "forward" && currentRoomIndex < rooms.size() - 1) {
        currentRoomIndex++;
    }
    else if (direction == "back" && currentRoomIndex > 0) {
        currentRoomIndex--;
    }
    enterRoom(&rooms[currentRoomIndex]);
}

void Player::enterRoom(Room* room) {
    setCurrentRoom(room);
    Enemy* enemy = room->getEnemy();
    if (enemy) {
        std::cout << "A " << enemy->getName() << " is here and attacks you!\n";
        health -= enemy->getDamage();
        std::cout << "You have " << health << " health left.\n";
        if (health <= 0) {
            std::cout << "You have been defeated!\n";
        }
    }
    for (auto& item : room->getItems()) {
        std::cout << "A " << item.getName() << " is here and you can take it!\n";
    }
}
void Player::takeItem(const std::string& itemName) {
    Item* item = currentRoom->getItem(itemName);
    if (item) {
        inventory.push_back(*item);
        std::cout << "You take the " << itemName << ".\n";
    }
    else {
        std::cout << "There is no " << itemName << " here.\n";
    }
}
std::vector<Item> Player::getInventory() {
    return inventory;
}
void Player::useItem(const std::string& itemName) {
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->getName() == itemName) {
            std::cout << "You use the " << itemName << ".\n";
            health += it->getEffect();
            if (health > 100) health = 100;
            inventory.erase(it);
            return;
        }
    }
    std::cout << "You don't have a " << itemName << ".\n";
}

void Player::attack() {
    Enemy* enemy = currentRoom->getEnemy();
    if (enemy) {
        int attackChance = std::rand() % 100;
        if (attackChance < 75) { // 75% chance to hit
            std::cout << "You attack the " << enemy->getName() << "!\n";
            enemy->takeDamage(10);
            if (enemy->getHealth() <= 0) {
                std::cout << "You have defeated the " << enemy->getName() << "!\n";
                currentRoom->setEnemy(nullptr);
            }
            else {
                std::cout << "The " << enemy->getName() << " has " << enemy->getHealth() << " health left.\n";
            }
        }
        else {
            std::cout << "Your attack missed!\n";
        }
        if (enemy->getHealth() > 0) {
            health -= enemy->getDamage();
            std::cout << "The " << enemy->getName() << " attacks you back! You have " << health << " health left.\n";
        }
    }
    else {
        std::cout << "There is no enemy here.\n";
    }
}

int Player::getHealth() const {
    return health;
}
