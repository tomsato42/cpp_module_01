#include <iostream>
#include <sstream>
#include <string>
#include "Zombie.h"

static std::string getZombieName() {
    std::ostringstream oss;
    static int zombieIndex = 0;
    oss << "Zombie" << zombieIndex++;
    return oss.str();
}

int main() {

    std::cout << "call newZombie" << std::endl;
    Zombie *zombie = newZombie(getZombieName());
    zombie->announce();
    std::cout << ">> delete zombie" << std::endl;
    delete zombie;
    std::cout << std::endl;
    std::cout << "call randomChump" << std::endl;
    randomChump(getZombieName());
    return 0;
}