#include "HumanA.h"
#include "iostream"
HumanA::~HumanA() {
}
HumanA::HumanA(const std::string &name, Weapon &weapon): _name(name) ,_weapon(weapon) {
}

void HumanA::attack() const {
    if (this->_weapon.getType().empty()) {
        std::cout << this->_name << " attacks with their \"NULL\"!" << std::endl;
        return;
    }
    std::cout << this->_name << " attacks with their \"" << this->_weapon.getType() << "\"!" << std::endl;
}
