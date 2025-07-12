#include <iostream>
#include <sstream>
#include <string>
#include "Zombie.h"

static void DeleteZombieHorde(Zombie *horde, const int N) {
    if (horde) {
        for (int i = 0; i < N; i++) {
            horde[i].announce();
        }
        delete[] horde;
    }
}

int main() {
    const int N = 5;

    std::cout << "call zombieHorde" << std::endl;
    Zombie *horde = zombieHorde(N, "Zombie");
    DeleteZombieHorde(horde, N);
    return 0;
}