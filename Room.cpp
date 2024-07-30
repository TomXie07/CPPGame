#include "Room.h"

Room::Room(const std::string& name, const std::string& description)
    : name(name), description(description), enemy(nullptr) {}

std::string Room::getName() const {
    return name;
}

std::string Room::getDescription() const {
    return description;
}

void Room::addItem(const Item& item) {
    items.push_back(item);
}

Item* Room::getItem(const std::string& itemName) {
    for (auto& item : items) {
        if (item.getName() == itemName) {
            return &item;
        }
    }
    return nullptr;
}
std::vector<Item> Room::getItems() {
    return items;
}
void Room::setEnemy(Enemy* enemy) {
    this->enemy = enemy;
}

Enemy* Room::getEnemy() const {
    return enemy;
}
