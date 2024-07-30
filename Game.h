#pragma once

#include <vector>
#include <string>
#include "Room.h"
#include "Player.h"
#include "Enemy.h"

class Game {
public:
    Game();
    void start();
private:
    Player player;
    std::vector<Room> rooms;
    std::vector<Enemy> enemies;
    void loadGameData(const std::string& filename);
    void mainLoop();
    bool checkWinCondition() const;
    void printHelp() const;
};

