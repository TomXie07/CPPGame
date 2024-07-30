#pragma once

#include <string>

class Item {
public:
    Item(const std::string& name, int effect);
    std::string getName() const;
    int getEffect() const;
private:
    std::string name;
    int effect; // Positive for health potion, negative for poison
};
