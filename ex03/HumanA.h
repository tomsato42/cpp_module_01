#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.h"
#include "string"

class HumanA {
public:
    HumanA();
    ~HumanA();

    HumanA(const HumanA&);
    HumanA(const std::string& name, const Weapon& weapon);
    HumanA& operator=(const HumanA&);

    void attack() const;

private:
    std::string _name;
    const Weapon* _weapon;
    void copyFrom(const HumanA&);
    void cleanUp();
};

#endif // HUMANA_H
