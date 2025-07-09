#include <iostream>
#include <string>

int main() {
    std::string stringVar = "HI THIS IS BRAIN";
    std::string* stringPTR = &stringVar;
    std::string& stringREF = stringVar;

    std::cout << "stringVar : " << &stringVar << std::endl;
    std::cout << "stringPTR : " << stringPTR << std::endl;
    std::cout << "stringREF : " << &stringREF << std::endl;

    std::cout << "stringVar : " << stringVar << std::endl;
    std::cout << "stringPTR : " << *stringPTR << std::endl;
    std::cout << "stringREF : " << stringREF << std::endl;
    return 0;
}