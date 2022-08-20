#ifndef _ADD_H
#define _ADD_H

#include <iostream>
#include <experimental/filesystem>
#include <fstream>
#include <algorithm>
#include <vector>

namespace fs = std::experimental::filesystem;

std::vector<std::string> SearchDuplicat(const fs::path &dir, const fs::path &dir_two) {

    std::vector<std::string> duplicatFiles;

    for (fs::recursive_directory_iterator it(dir), end; it != end; ++it) {
        for (fs::recursive_directory_iterator it_2(dir_two), end; it_2 != end; ++it_2) {
            if (it->path().filename() == it_2->path().filename()) {
                duplicatFiles.push_back(it->path().filename().string());
            }
        }
    }

    if(duplicatFiles.empty()) {
        duplicatFiles.push_back("No duplicate files found");
        return duplicatFiles;
    }
    else {
        return duplicatFiles;
    }
}

bool CheckForCorrectnessOfInput(fs::path &dir, fs::path &dir_two, int argc, char *argv[]) {

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
        dir_two = dir / argv[1];

        if(!fs::is_directory(dir)) {
            std::cout << "The path to the directory was entered incorrectly \n Please try again" << std::endl;
            return false;
        }
        else {
            dir = dir / argv[2];
            dir_two = dir_two / argv[3];
            return true;
        }
    }
    else {
        std::cout << "Only two arguments no more \n try again " << std::endl;
        return false;
    }
}

bool CheckingTheDirectoryExists(fs::path &dir, fs::path &dir_two) {

        if (!fs::is_directory(dir) || !fs::is_directory(dir_two)) {
            if(!fs::is_directory(dir) && fs::is_directory(dir_two)) {
                std::cout << "A directory with " << dir.string() <<  " name does not exist in the current directory " << std::endl;
                return false;
            }
            else if (!fs::is_directory(dir_two) && fs::is_directory(dir)) {
                std::cout << "A directory with " << dir_two.string() <<  " name does not exist in the current directory " << std::endl;
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

bool CheckingIfFilesExistInTheDedirectory(fs::path &dir, fs::path &dir_two) {

    if (fs::is_empty(dir) || fs::is_empty(dir_two)) {
        if(fs::is_empty(dir)  && !fs::is_empty(dir_two)) {
            std::cout << "There are no files in the directorie " << dir_two.string() << std::endl;
            return false;
        }
        else if (fs::is_empty(dir_two) && !fs::is_empty(dir) ) {
            std::cout << "There are no files in the directorie " << dir_two.string() << std::endl;
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