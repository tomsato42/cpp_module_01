#include "Zombie.h"

void randomChump(std::string name) {
    const Zombie z(name);
    z.announce();
}