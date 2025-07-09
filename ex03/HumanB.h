#ifndef HUMANB_H
#define HUMANB_H
#include "Weapon.h"

class HumanB {
public:
    HumanB();
    ~HumanB();
    HumanB(const HumanB &);
    explicit HumanB(const std::string &name);
    HumanB &operator=(const HumanB &);

    void setWeapon(Weapon& weapon);
    void attack() const;

private:
    std::string _name;
    Weapon* _weapon;

    void copyFrom(const HumanB &);

    void cleanUp();
};

#endif // HUMANB_H
