#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.h"
#include "string"

class HumanA {
public:
    ~HumanA();
    HumanA(const std::string& name, Weapon &weapon);

    void attack() const;

private:
    std::string _name;
    Weapon& _weapon;
};

#endif // HUMANA_H
