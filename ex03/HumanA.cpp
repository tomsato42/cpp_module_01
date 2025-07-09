#include "HumanA.h"
#include "iostream"

HumanA::HumanA() {
    _name = "";
    _weapon = NULL;
}

HumanA::~HumanA() {
    cleanUp();
}

HumanA::HumanA(const HumanA& other) {
    copyFrom(other);
}

HumanA::HumanA(const std::string &name, const Weapon &weapon) {
    this->_name = name;
    this->_weapon = &weapon;
}

HumanA& HumanA::operator=(const HumanA& other) {
    if (this != &other) {
        cleanUp();
        copyFrom(other);
    }
    return *this;
}

void HumanA::attack() const {
    if (this->_weapon == NULL || this->_weapon->getType().empty()) {
        std::cout << this->_name << " attacks with their \"NULL\"!" << std::endl;
        return;
    }
    std::cout << this->_name << " attacks with their \"" << this->_weapon->getType() << "\"!" << std::endl;
}

void HumanA::copyFrom(const HumanA& other) {
    this->_name = other._name;
    this->_weapon = other._weapon;
}

void HumanA::cleanUp() {
    this->_name = "";
    this->_weapon = NULL;
}
