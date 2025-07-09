#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <string>

class Zombie {
public:
    Zombie();
    Zombie(const std::string&);
    ~Zombie();

    Zombie(const Zombie&);
    Zombie& operator=(const Zombie&);

    // Additional methods can be declared here if needed
    void announce(void) const;
private:
    int* data_;
    std::string name;
    void copyFrom(const Zombie&);
    void cleanUp();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif // ZOMBIE_H
