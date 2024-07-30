#include "Enemy.h"

Enemy::Enemy(const std::string& name, int health, int damage, Room* room)
    : name(name), health(health), damage(damage), room(room) {}

std::string Enemy::getName() const {
    return name;
}

int Enemy::getHealth() const {
    return health;
}

void Enemy::takeDamage(int amount) {
    health -= amount;
}

int Enemy::getDamage() const {
    return damage;
}
