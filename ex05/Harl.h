#ifndef HARL_H
#define HARL_H
#include <string>

class Harl {
public:
    Harl();

    ~Harl();

    Harl(const Harl &);

    Harl &operator=(const Harl &);

    void complain(std::string level);

private:
    void debug();

    void info();

    void warning();

    void error();

    void copyFrom(const Harl &);

    void cleanUp();
};

#endif // HARL_H
