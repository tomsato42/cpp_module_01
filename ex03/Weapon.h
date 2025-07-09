#ifndef WEAPON_H
#define WEAPON_H
#include <string>

class Weapon {
public:
    Weapon();

    explicit Weapon(const char * str);

    ~Weapon();

    Weapon(const Weapon&);
    Weapon& operator=(const Weapon&);
    const std::string& getType() const;
    void setType(const std::string& newType);

private:
    std::string type;
    void copyFrom(const Weapon&);
    void cleanUp();
};

#endif // WEAPON_H
