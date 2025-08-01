#include <fstream>
#include <iostream>
#include <sstream>

std::string readFileAll(const std::string &filename) {
    std::ifstream input(filename.c_str());
    std::stringstream buffer;
    buffer << input.rdbuf();
    return buffer.str();
}

int main(const int ac, char **av) {
    if (ac != 4) {
        std::cerr << "Usage: ./SedIsForLosers <input_file> <s1> <s2>" << std::endl;
        return 1;
    }
    const std::string inputFile = av[1];
    const std::string s1 = av[2];
    const std::string s2 = av[3];
    const std::string outputFile = inputFile + ".replace";

    const std::string buffer = readFileAll(inputFile);
    if (buffer.empty()) {
        std::cerr << "Error: Could not read file or file is empty." << std::endl;
        return 1;
    }

    size_t count = 0;
    std::ofstream output(outputFile.c_str());
    std::string::size_type pos = buffer.find(s1);
    if (!s1.empty()) {
        while (pos != std::string::npos) {
            output << buffer.substr(count, pos - count) << s2;
            count = pos + s1.length();
            pos = buffer.find(s1, count);
        }
    }
    output << buffer.substr(count, buffer.length() - count);
    output.close();
    return 0;
}
