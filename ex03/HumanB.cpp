#include "HumanB.h"

#include <iostream>

HumanB::HumanB(): _weapon(NULL) {
}

HumanB::~HumanB() {
    cleanUp();
}

HumanB::HumanB(const HumanB &other) {
    copyFrom(other);
}

HumanB::HumanB(const std::string &name) {
    this->_name = name;
    this->_weapon = NULL;
}

HumanB &HumanB::operator=(const HumanB &other) {
    if (this != &other) {
        cleanUp();
        copyFrom(other);
    }
    return *this;
}

void HumanB::setWeapon(Weapon& weapon) {
    this->_weapon = &weapon;
}

void HumanB::attack() const {
    if (this->_weapon->getType().empty()) {
        std::cout << this->_name << " has no weapon to attack with!" << std::endl;
        return;
    }
    std::cout << this->_name << " attacks with their \"" << this->_weapon->getType() << "\"!" << std::endl;
}

void HumanB::copyFrom(const HumanB &other) {
    this->_name = other._name;
    this->_weapon = other._weapon;
}

void HumanB::cleanUp() {
    this->_name = "";
    this->_weapon = NULL;
}
