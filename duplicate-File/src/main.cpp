#include <iostream>
#include "Verifications.h"
#include "SearchDuplicatFile.h"

namespace fs = std::experimental::filesystem;

int main(int argc, char *argv[]) {

    auto dir = fs::path();
    auto dirTwo = fs::path();

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