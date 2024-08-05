## Game introduction and description
​### Game background
Adventure Game is a console-based text adventure game where players explore multiple rooms, collect items, fight and ultimately defeat all enemies. The game uses object-oriented programming (OOP) design concepts to generate the game's rooms, items, and enemies by loading external file content and interacting with the player's instructions.
​### Gameplay
The player starts in a room called the Entrance Hall, which may contain enemies and items. Players need to move through different rooms, collect items, and fight enemies. The game ends when the player's health reaches zero. If the player defeats all the enemies, the game wins.
​### Instructions
Players can play with the following commands:
- 'move [direction]' - Moves in the specified direction (for example, 'move forward/back').
- 'look' - View the description of the current room.
- 'take [item]' - Remove a specified item from the room (for example, 'take Health Potion').
- 'use [item]' - Uses a specified item in the player's backpack (for example, 'use Health Potion').
- 'attack' - Attacks enemies in the current room.
- 'quit' - Quit the game.
- 'help' - Displays the description of the game command.
​### Game code structure
The game consists of several classes, each responsible for a different function:
- 'Game' class: Responsible for the initialization and main loop of the game.
- 'Player' class: represents the player and handles the player's actions and states.
- 'Room' class: represents a room and contains a description of the room, items, and enemies.
- 'Item' class: represents an item and contains the item's name and effect.
- 'Enemy' class: Represents the enemy and contains the enemy's name, health, and attack power.

### UML 设计图

```plaintext
+----------------------------------------+      +------------------------------------+      +-----------------------------------+
|    Game                                |      |    Player                          |      |     Room                          |
+----------------------------------------+      +------------------------------------+      +-----------------------------------+
| - rooms: vector<Room>                  |      | - health: int                      |      | - name: string                    |
| - enemies: vector<Enemy>               |      | - inventory: vector<Item>          |      | - description: string             |
| - player: Player                       |      | - currentRoom: Room*               |      | - items: vector<Item>             |
| + loadGameData(filename: string): void |      | + enterRoom(room: Room*): void     |      | - enemy: Enemy*                   |
| + start(): void                        |      | + move(direction: string): void    |      | + addItem(item: Item): void       |
| + mainLoop(): void                     |      | + takeItem(itemName: string): void |      | + getItem(itemName: string): Item*|
| + printHelp(): void                    |      | + useItem(itemName: string): void  |      | + setEnemy(enemy: Enemy*): void   |
| + checkWinCondition(): bool            |      | + attack(): void                   |      | + getEnemy(): Enemy*              |
+----------------------------------------+      +------------------------------------+      +-----------------------------------+
												                    +---------------------+
+---------------------------------+      +-------------------+      |    Item             |
|    Enemy                        |      |   Main (optional) |      +---------------------+
+---------------------------------+      +-------------------+      | - name: string      |
| - name: string                  |      | - main(): int     |      | - effect: int       |
| - health: int                   |      +-------------------+      | + getName(): string |
| - damage: int                   |                               	| + getEffect(): int  |
| - room: Room*                   |                                 +---------------------+
| + takeDamage(amount: int): void |
| + getHealth(): int              |
| + getDamage(): int              |
| + getName(): string             |
+---------------------------------+
```

- ### Run the game
​How to run the game, enter commands, and the main features of the game. Here's how to run the game:
​1. Run the game program.
2. Display the welcome message and game description.
3. Show the player moving through different rooms.
4. Pick up items and use them.
5. Fight the enemy and show the battle process.
6. Display game end condition: player wins or loses.
7. Summarize the game experience and provide the option to quit the game.
​With this structure and design, the game follows the principles of object-oriented programming.
