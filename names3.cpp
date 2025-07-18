#include <fstream>
#include <iostream>
#include <ostream>

/**
 * Version 3 adds an interface.
 * IFileReader *fileReader = new FileReader(filePath);
 */
namespace {
    class IFileReader {
    public:
        virtual std::vector<std::string> readNamesFromFile() = 0;
        virtual ~IFileReader() = default;
    };

    class FileReader final : public IFileReader {
        const std::string& filename;

    public:
        explicit FileReader(const std::string& filename) : filename(filename) {}
        ~FileReader() {
            printf("FileReader destructor xxx\n");
        }

        std::vector<std::string> readNamesFromFile() override {
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

    // read names, use polymorphism
    IFileReader *fileReader = new FileReader(filePath);
    const auto names = fileReader->readNamesFromFile();

    // An alternate approach would be a smart pointer
    //auto fileReader = std::make_unique<FileReader>(filePath);

    // print names
    for (const auto& name : names) {
        std::cout << name << std::endl;
    }

    free(fileReader);
}
