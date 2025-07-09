#include <iostream>
#include <sstream>
#include <string>
#include "Zombie.h"

static void DeleteZombieHorde(Zombie *horde, int N) {
    if (horde) {
        for (int i = 0; i < N; i++) {
            horde[i].announce();
        }
        delete[] horde;
    }
}

int main() {

    std::cout << "call zombieHorde" << std::endl;
    Zombie *horde = zombieHorde(5, "Zombie");
    DeleteZombieHorde(horde, 5);
    return 0;
}