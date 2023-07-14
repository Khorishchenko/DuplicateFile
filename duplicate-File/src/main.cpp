#include <iostream>
#include "functions_app.h"

namespace fs = std::experimental::filesystem;

int main(int argc, char *argv[]) {

    auto dir = fs::path();
    auto dir_two = fs::path();

    auto print_file = [](const std::vector<std::string> &aVector) {

        std::cout << "Duplicate file(s) is: " << std::endl; 
        for (auto &f: aVector)
            std::cout << f << std::endl;
        std::cout << std::endl;
    };
   
    if(CheckForCorrectnessOfInput(dir, dir_two, argc, argv) 
        && CheckingTheDirectoryExists(dir, dir_two) 
        && CheckingIfFilesExistInTheDedirectory(dir, dir_two)) {

        print_file(SearchDuplicat(dir, dir_two));
    }
    else {
        return 0;
    }

    return 0;
}


