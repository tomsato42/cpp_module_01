#include "Harl.h"

#include <iostream>

Harl::Harl() {
}

Harl::~Harl() {
    cleanUp();
}

Harl::Harl(const Harl &other) {
    copyFrom(other);
}

Harl &Harl::operator=(const Harl &other) {
    if (this != &other) {
        cleanUp();
        copyFrom(other);
    }
    return *this;
}

void Harl::complain(std::string level) {
    void (Harl::*functions[])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    for (int i = 0; i < 4; ++i) {
        const std::string levels[] = {
            "DEBUG",
            "INFO",
            "WARNING",
            "ERROR"
        };
        if (levels[i] == level) {
            std::cout << "[ " << levels[i] << " ]" << std::endl;
            (this->*functions[i])();
            return;
        }
    }
}

void OutPut(const std::string &message) {
    std::cout << message << std::endl;
}

void Harl::debug() {
    OutPut("I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!");
}

void Harl::info() {
    OutPut(
        "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!");
}

void Harl::warning() {
    OutPut(
        "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.");
}

void Harl::error() {
    OutPut("This is unacceptable! I want to speak to the manager now.");
}

void Harl::copyFrom(const Harl &other) {
    (void) other;
}

void Harl::cleanUp() {
}
