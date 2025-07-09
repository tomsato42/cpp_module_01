#include "Harl.h"

#include <iostream>

Harl::Harl() {
}

Harl::~Harl() {
    cleanUp();
}

Harl::Harl(const Harl &other){
    copyFrom(other);
}

Harl &Harl::operator=(const Harl &other) {
    if (this != &other) {
        cleanUp();
        copyFrom(other);
    }
    return *this;
}

static void OutPut(const char *str) {
    std::cout << str << std::endl;
}

enum levels {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    INVALID
};

levels getLevel(const std::string &level) {
    if (level == "DEBUG") return DEBUG;
    if (level == "INFO") return INFO;
    if (level == "WARNING") return WARNING;
    if (level == "ERROR") return ERROR;
    return INVALID;
}

void Harl::complain(std::string level) {
    int start = getLevel(level);

    if (start == INVALID) {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return;
    }

    void (Harl::*functions[])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    switch (start) {
        case DEBUG:
            std::cout << "[ DEBUG ]" << std::endl;
            (this->*functions[DEBUG])();
            complain(std::string("INFO"));
            break;
        case INFO:
            std::cout << "[ INFO ]" << std::endl;
            (this->*functions[INFO])();
            complain(std::string("WARNING"));
            break;
        case WARNING:
            std::cout << "[ WARNING ]" << std::endl;
            (this->*functions[WARNING])();
            complain(std::string("ERROR"));
            break;
        case ERROR:
            std::cout << "[ ERROR ]" << std::endl;
            (this->*functions[ERROR])();
            break;
        default:
            break;
    }
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
    (void)other;
}

void Harl::cleanUp() {
}
