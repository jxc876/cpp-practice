#include <iostream>
#include <fstream>
#include <vector>
#include <string>


namespace {
    std::vector<std::string> readNamesFromFile(const std::string& filename);
}

// Note — Path is relative to binary
static const std::string filePath = "../names.txt";

int main() {
    try {
        auto names = readNamesFromFile(filePath);
        for (const auto& name : names) {
            std::cout << name << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error reading file: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

namespace {
    std::vector<std::string> readNamesFromFile(const std::string& filename) {
        std::ifstream file(filename);
        std::vector<std::string> names;

        if (!file.is_open()) {
            throw std::runtime_error("Could not open file: " + filename);
        }

        std::string name;
        while (std::getline(file, name)) {
            names.push_back(name);
        }

        file.close();
        return names;
    }
}