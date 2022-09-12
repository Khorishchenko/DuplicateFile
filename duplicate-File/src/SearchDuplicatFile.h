#ifndef SEARCH_DUPLICAT_FILE_H
#define SEARCH_DUPLICAT_FILE_H

#include "FileSystem.h"

bool SearchDuplicat(FileSystem &dir, FileSystem &dirTwo) {

    bool duplicatFileNotExists = true;

    for (auto it = dir.ItBegin(), end = dir.ItEnd(); it != end; ++it) {
        for (auto it_2 = dirTwo.ItBegin(), end = dirTwo.ItEnd(); it_2 != end; ++it_2) {
            if (it->path().filename() == it_2->path().filename()) {
                std::cout << "Duplicate file is: " << it->path().filename().string() << std::endl;
                duplicatFileNotExists = false;
            }
        }
    }

    if(duplicatFileNotExists) {
        std::cout << "Duplicate file does not exist !" << std::endl;
        return false;
    }
    else {
        return true;
    }
}

#endif