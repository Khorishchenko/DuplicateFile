#ifndef SEARCH_DUPLICAT_FILE_TEST_H
#define SEARCH_DUPLICAT_FILE_TEST_H

#include "CreateFileDir.h"

// TODO: GOOGLE TEST

TEST(SearchDuplicatTest, Duplicate_Found_True) {
     // Arrange
    Directory dir(CreateDir("dir"));
    Directory dirTwo(CreateDir("dirTwo"));

    // Act
    CreateFiles(dir, "file", "fileTwo");
    CreateFiles(dirTwo, "files", "fileTwo");
  
    // Assert
    ASSERT_TRUE(SearchDuplicat(dir, dirTwo));

    fs::remove_all(dir.getDir());
    fs::remove_all(dirTwo.getDir());
}

TEST(SearchDuplicatTest, Duplicate_Not_Found_True) {
     // Arrange
    Directory dir(CreateDir("dir"));
    Directory dirTwo(CreateDir("dirTwo"));

    // Act
    CreateFiles(dir, "file", "fileTwo");
    CreateFiles(dirTwo, "files", "filesTwo");
    
    // Assert
    ASSERT_TRUE(!SearchDuplicat(dir, dirTwo));

    fs::remove_all(dir.getDir());
    fs::remove_all(dirTwo.getDir());
}

#endif