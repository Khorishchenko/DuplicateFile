#include <iostream>

#include "Verifications.h"
#include "SearchDuplicatFile.h"
#include "Directory.h"

int main(int argc, char *argv[]) {

    Directory dir;
    Directory dirTwo;

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