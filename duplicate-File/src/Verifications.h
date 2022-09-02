#ifndef VERIFICATIONS_H
#define VERIFICATIONS_H

#include <iostream>
#include <experimental/filesystem>
#include <fstream>
#include <algorithm>

namespace fs = std::experimental::filesystem;


bool IsCorrectnessOfInput(fs::path &dir, fs::path &dirTwo, int argc, char *argv[]) {

     if (argc == 1) {
        std::cout << "You have not entered a directory name and The path to the directory \n";
        std::cout << "Please enter path name how first arguments and name's directory as the second and third arguments."  << std::endl;
        return false;
    }
    else if(argc == 2) {
        std::cout << "You have not entered a directory name \n";
        std::cout << "Please enter name's directory as the second and third arguments."  << std::endl;
    }
    else if(argc == 3) {
        std::cout << "Please enter name second Dir how third argument" << std::endl;
        return false;
    }
    else if (argc == 4) {
        dir = dir / argv[1];
        dirTwo = dir / argv[1];

        if(!fs::is_directory(dir)) {
            std::cout << "The path to the directory was entered incorrectly \n Please try again" << std::endl;
            return false;
        }
        else {
            dir = dir / argv[2];
            dirTwo = dirTwo / argv[3];
            return true;
        }
    }
    else {
        std::cout << "Only two arguments no more \n try again " << std::endl;
        return false;
    }
}

bool IsExistsDirectory(fs::path &dir, fs::path &dirTwo) {

        if (!fs::is_directory(dir) || !fs::is_directory(dirTwo)) {
            if(!fs::is_directory(dir) && fs::is_directory(dirTwo)) {
                std::cout << "A directory with " << dir.string() <<  " name does not exist in the current directory " << std::endl;
                return false;
            }
            else if (!fs::is_directory(dirTwo) && fs::is_directory(dir)) {
                std::cout << "A directory with " << dirTwo.string() <<  " name does not exist in the current directory " << std::endl;
                return false;
            }
            else {
                std::cout << "no such directory exists" << std::endl;
                return false;
            }
        }
        else {
            return true;
        }
}

bool IsExistFiles(fs::path &dir, fs::path &dirTwo) {

    if (fs::is_empty(dir) || fs::is_empty(dirTwo)) {
        if(fs::is_empty(dir)  && !fs::is_empty(dirTwo)) {
            std::cout << "There are no files in the directorie " << dirTwo.string() << std::endl;
            return false;
        }
        else if (fs::is_empty(dirTwo) && !fs::is_empty(dir) ) {
            std::cout << "There are no files in the directorie " << dirTwo.string() << std::endl;
            return false;
        }
        else {
            std::cout << "There are no files in the directories" << std::endl;
            return false;
        }
    }
    else {
        return true;
    }
}

#endif