#include "Weapon.h"

Weapon::Weapon() {}

Weapon::Weapon(const char *str) {
    this->type = str;
}

Weapon::~Weapon() {
    cleanUp();
}

Weapon::Weapon(const Weapon& other) : type(other.type) {
    copyFrom(other);
}

Weapon& Weapon::operator=(const Weapon& other) {
    if (this != &other) {
        cleanUp();
        copyFrom(other);
    }
    return *this;
}

const std::string & Weapon::getType() const {
    return type;
}

void Weapon::setType(const std::string &newType) {
    this->type = newType;
}

void Weapon::copyFrom(const Weapon& other) {
    this->type = other.type;
}

void Weapon::cleanUp() {
    this->type = "";
}
