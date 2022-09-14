#ifndef CREATE_FILE_DIR_H
#define CREATE_FILE_DIR_H

#include "Verifications.h"
#include "SearchDuplicatFile.h"
#include "Directory.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>


TypeFile_t CreateDir(std::string nameDir) {

    TypeFile_t resDir = fs::current_path();

    resDir = resDir / nameDir;
    fs::create_directories(resDir);

    return resDir;
}

void CreateFiles(Directory &resDir, std::string nameFile = "", std::string nameFileTwo = "", std::string nameFileThree = "") {

    std::vector<std::string> resFile = 
    {
        resDir.getDir().string() + "/" + nameFile,
        resDir.getDir().string() + "/" + nameFileTwo,
        resDir.getDir().string() + "/" + nameFileThree
    };

    // create files 
    for(auto &file: resFile) {
        std::ofstream(file) << "data";
    }
}

#endif