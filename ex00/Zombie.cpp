#include "Zombie.h"
#include "iostream"

Zombie::Zombie() : data_(__null) {}

Zombie::Zombie(const std::string &name) : data_(__null), name(name) {
    std::cout << "Zombie is Created : " << name << std::endl;
}

Zombie::~Zombie() {
    std::cout << "Zombie is Dead : " << name << std::endl;
    cleanUp();
}

Zombie::Zombie(const Zombie& other) : data_(__null) {
    copyFrom(other);
}

Zombie& Zombie::operator=(const Zombie& other) {
    if (this != &other) {
        cleanUp();
        copyFrom(other);
    }
    return *this;
}

void Zombie::copyFrom(const Zombie& other) {
    if (other.data_) {
        data_ = new int(*other.data_);
    }
}

void Zombie::announce(void) const {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::cleanUp() {
    delete data_;
    data_ = __null;
}
