#ifndef VERIFICATIONS_H
#define VERIFICATIONS_H

#include "FileSystem.h"

bool ReadingDirectory(FileSystem &dir, FileSystem &dirTwo, char *argv[]) {
    
        dir.getDir() = dir.getDir() / argv[1];
        dirTwo.getDir() = dir.getDir() / argv[1];

        if(!dir.IsDirectory()) {
            std::cout << "The path to the directory was entered incorrectly \n Please try again" << std::endl;
            return false;
        }
        else {
            dir.getDir() = dir.getDir() / argv[2];
            dirTwo.getDir() = dir.getDir() / argv[3];
            return true;
        }
}

bool IsCorrectnessOfInput(FileSystem &dir, FileSystem &dirTwo, int argc, char *argv[]) {

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
        return ReadingDirectory(dir, dirTwo, argv);
    }
    else {
        std::cout << "Only three arguments no more \n try again " << std::endl;
        return false;
    }
}

bool IsExistsDirectory(FileSystem &dir, FileSystem &dirTwo) {

        if (!dir.IsDirectory() || !dirTwo.IsDirectory()) {
            if(!dir.IsDirectory() && dirTwo.IsDirectory()) {
                std::cout << "A directory with " << dirTwo.getDir().string() <<  " name does not exist in the current directory " << std::endl;
                return false;
            }
            else if (!dirTwo.IsDirectory() && dir.IsDirectory()) {
                std::cout << "A directory with " << dirTwo.getDir().string() <<  " name does not exist in the current directory " << std::endl;
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

bool IsExistFiles(FileSystem &dir, FileSystem &dirTwo) {

    if (dir.IsEmpty() || dirTwo.IsEmpty()) {
        if(dir.IsEmpty()  && !dirTwo.IsEmpty()) {
            std::cout << "There are no files in the directorie " << dirTwo.getDir().string() << std::endl;
            return false;
        }
        else if (dirTwo.IsEmpty() && !dir.IsEmpty() ) {
            std::cout << "There are no files in the directorie " << dirTwo.getDir().string() << std::endl;
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