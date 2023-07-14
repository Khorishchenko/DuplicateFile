#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "myfunctions.h"

#include <limits>
#include <vector>
#include <ctime>
#include <cstdio>
#include <string>

namespace fs = std::experimental::filesystem;
typedef std::experimental::filesystem::v1::path t_typeFile;

TEST(duplicateSearchTest, method_createDir_IsCreate) {
     // Arrange
    duplicateSearch dir;

    // Act
    std::string nameDir = dir.getDir().string();
    dir.createDir("MyDirTest");

    // Assert
    ASSERT_EQ(dir.getDir().string(), nameDir += "/MyDirTest");

    fs::remove_all(dir.getDir());
}

TEST(duplicateSearchTest, method_createFile_fileIsCreate) {
     // Arrange
    duplicateSearch dir;

    // Act
    dir.createDir("TestDir");
    dir.createFiles("file_1", "file_2");

    // Assert
    ASSERT_FALSE(dir.getDir().empty());

    fs::remove_all(dir.getDir());
}

TEST(duplicateSearchTest, method_searchDuplicat_DontFindDuplicate) {
    // Arrange
    duplicateSearch dir, dir_two;

    // Act
    dir.createDir("Duplicate_1");
    dir_two.createDir("Duplicate_2");

    dir.createFiles("hello.txt", "pong.png", "hello_2.txt");

    // Assert 
    ASSERT_TRUE(dir.searchDuplicat(dir_two).empty());

    // Act_2
    dir_two.createFiles("file_1", "file_2");

    // Assert_2
    ASSERT_TRUE(dir.searchDuplicat(dir_two).empty());

    fs::remove_all(dir.getDir());
    fs::remove_all(dir_two.getDir());
}

TEST(duplicateSearchTest, method_searchDuplicat_FindDuplicate) {
    // Arrange
    duplicateSearch dir, dir_two;

    // Act
    dir.createDir("Duplicate_1");
    dir_two.createDir("Duplicate_2");

    dir.createFiles("file", "file_1");
    dir_two.createFiles("file_1", "file_2");

    // Assert 
    ASSERT_FALSE(dir.searchDuplicat(dir_two).empty());
    ASSERT_EQ(dir.searchDuplicat(dir_two).front(), "file_1");

    fs::remove_all(dir.getDir());
    fs::remove_all(dir_two.getDir());
}

using ::testing::AtLeast; 
using ::testing::Exactly; 

class MockDuplicateSearch : duplicateSearch {

public:
    MOCK_METHOD(void, createDir, (std::string nameDir), ());
    MOCK_METHOD(void, createFiles, (std::string name_file1, std::string name_file2, std::string name_file3), ());
    MOCK_METHOD(std::vector<std::string>, searchDuplicat, (const duplicateSearch &dir), ());
    MOCK_METHOD(t_typeFile, getDir, (), ());
};

TEST(duplicateSearchTest, method_searchDuplicat_findDuplicate) {
    // Arrange
      MockDuplicateSearch dir;   
     

    // Act

                             
    EXPECT_CALL(dir, getDir)
        .Times(Exactly(1));
        // .Times(1)               
        // .WillOnce(Return(fs::path));


    // Assert 
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
