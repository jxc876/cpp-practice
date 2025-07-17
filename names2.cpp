#include <fstream>
#include <iostream>
#include <ostream>

/**
 * Version 2 uses a class to read the File.
 * FileReader.readNamesFromFile();
 */
namespace {
    class FileReader {
        const std::string& filename;

    public:
        explicit FileReader(const std::string& filename) : filename(filename) {}

        std::vector<std::string> readNamesFromFile() {
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
    };
}

int main() {
    const std::string filePath = "../names.txt";

    // read names
    auto fileReader = FileReader{filePath};
    const auto names = fileReader.readNamesFromFile();

    // print names
    for (const auto& name : names) {
        std::cout << name << std::endl;
    }
}
