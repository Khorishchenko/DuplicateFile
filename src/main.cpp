#include <iostream>
#include "myfunctions.h"

int main() {

    duplicateSearch dir, dir_two;

    dir.createDir("dublicat_1");
    dir_two.createDir("dublicat_2");

    dir.createFiles("hello.txt", "pong.png", "hello_2.txt");
    dir_two.createFiles("hello_world.txt", "pong.png", "world.txt");

    dir.print();
    dir_two.print();


    auto print_file = [](const std::vector<std::string> &aVector) {
        for (auto &f: aVector)
            std::cout << f << std::endl;
        std::cout << std::endl;
    };
 
    std::vector<std::string> duplicateFile = dir.searchDuplicat(dir_two);

    if (duplicateFile.empty()) {
        std::cout << "Dublicat's is not find " << std::endl;
    }
    else {
        print_file(duplicateFile);
    }

    return 0;
}


