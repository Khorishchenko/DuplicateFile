#include <iostream>

#include "Verifications.h"
#include "SearchDuplicatFile.h"
#include "FileSystem.h"

int main(int argc, char *argv[]) {

    FileSystem dir;
    FileSystem dirTwo;

    if(IsCorrectnessOfInput(dir, dirTwo, argc, argv) 
        && IsExistsDirectory(dir, dirTwo) 
        && IsExistFiles(dir, dirTwo)) {

        SearchDuplicat(dir, dirTwo);
    }
    else {
        return 0;
    }

    return 0;
}