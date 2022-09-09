#ifndef SEARCH_DUPLICAT_FILE_H
#define SEARCH_DUPLICAT_FILE_H

#include "FileSystem.h"

namespace fs = std::experimental::filesystem;

bool SearchDuplicat(const FileSystem &dir, const FileSystem &dir_two) {

    bool duplicatFileNotExists = true;

    for (fs::recursive_directory_iterator it(dir), end; it != end; ++it) {
        for (fs::recursive_directory_iterator it_2(dir_two), end; it_2 != end; ++it_2) {
            if (it->path().filename() == it_2->path().filename()) {
                std::cout << "Duplicate file is: " << it->path().filename().string() << std::endl;
                duplicatFileNotExists = false;
            }
        }
    }

    if(duplicatFileNotExists) {
        std::cout << "Duplicate file does not exist !" <<std::endl;
        return false;
    }
    else {
        return true;
    }
}

#endif