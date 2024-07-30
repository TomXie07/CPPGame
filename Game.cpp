#include "Game.h"
#include <iostream>
#include <fstream>
#include <sstream>

void Game::printHelp() const {
    std::cout << "\nGame Instructions:\n";
    std::cout << "1. move [direction] - Move in the specified direction.\n";
    std::cout << "2. look - Look around the current room.\n";
    std::cout << "3. take [item] - Take the specified item from the room.\n";
    std::cout << "4. use [item] - Use the specified item from your inventory.\n";
    std::cout << "5. attack - Attack the enemy in the current room.\n";
    std::cout << "6. quit - Quit the game.\n";
    std::cout << "7. help - Show these instructions again.\n\n";
}

Game::Game() {
    loadGameData("game_data.txt");
}

void Game::loadGameData(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error loading game data.\n";
        exit(1);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string roomName, roomDesc;
        std::getline(iss, roomName, ',');
        std::getline(iss, roomDesc, ',');
        rooms.emplace_back(roomName, roomDesc);
    }

    // Adding items and enemies to rooms
    rooms[0].addItem(Item("Health Potion", 20)); // Entrance Hall
    rooms[1].addItem(Item("Sword", 10)); // Great Hall
    rooms[2].addItem(Item("Magic Book", 0)); // Library
    rooms[3].addItem(Item("Poison", -20)); // Dungeon

    Enemy* goblin = new Enemy("Goblin", 20, 5, &rooms[0]);
    rooms[0].setEnemy(goblin);
    enemies.push_back(*goblin);

    Enemy* orc = new Enemy("Orc", 30, 10, &rooms[1]);
    rooms[1].setEnemy(orc);
    enemies.push_back(*orc);

    Enemy* ghost = new Enemy("Ghost", 15, 7, &rooms[2]);
    rooms[2].setEnemy(ghost);
    enemies.push_back(*ghost);

    Enemy* dragon = new Enemy("Dragon", 50, 20, &rooms[3]);
    rooms[3].setEnemy(dragon);
    enemies.push_back(*dragon);
}

void Game::start() {
    std::cout << "Welcome to the Adventure Game!\n";
    printHelp();
    player.setCurrentRoom(&rooms[0]);
    player.enterRoom(&rooms[0]);
    mainLoop();
}

void Game::mainLoop() {

    std::string command;
    while (true) {
        std::cout << "\nYou are in " << player.getCurrentRoom()->getName() << ".\n";
        std::cout << player.getCurrentRoom()->getDescription() << "\n";
        std::cout << "What do you want to do?\n";
        std::getline(std::cin, command);

        if (command == "quit") {
            std::cout << "Thanks for playing!\n";
            break;
        }
        else if (command == "look") {
            std::cout << player.getCurrentRoom()->getDescription() << "\n";
        }
        else if (command == "move") {
            std::cout << "Which direction? (forward,back)";
            std::string direction;
            std::getline(std::cin, direction);
            player.move(direction, rooms);
        }
        else if (command == "take") {
            std::cout << "Which item? ";
            std::string itemName;
            std::getline(std::cin, itemName);
            player.takeItem(itemName);
        }
        else if (command == "use") {
            std::vector<Item> items = player.getInventory();
            if (items.size() == 0) {
                std::cout << "Your Inventory is empty!! ";
            }
            else {
                std::cout << "Your Inventory: ";

                for (auto& item : items) {
                    std::cout << item.getName() << "\n";
                }
                std::cout << "Which item? ";

                std::string itemName;
                std::getline(std::cin, itemName);
                player.useItem(itemName);
            }

        }
        else if (command == "attack") {
            player.attack();
            if (player.getHealth() <= 0) {
                std::cout << "You have been defeated!\n";
                break;
            }
            if (checkWinCondition()) {
                std::cout << "You have defeated all the enemies! You win!\n";
                break;
            }
        }
        else if (command == "help") {
            printHelp();
        }
        else {
            std::cout << "Unknown command.\n";
        }
    }
}

bool Game::checkWinCondition() const {
    for (const auto& enemy : enemies) {
        if (enemy.getHealth() > 0) {
            return false;
        }
    }
    return true;
}
