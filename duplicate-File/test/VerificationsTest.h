#ifndef VERIFICATIONS_TEST_H
#define VERIFICATIONS_TEST_H

#include "CreateFileDir.h"

class FileSustemMock : public Directory {

public:

    MOCK_METHOD(TypeFile_t&, getDir, (), (override));
    MOCK_METHOD(IteratorFile_t, ItBegin, (), (override));
    MOCK_METHOD(IteratorFile_t, ItEnd, (), (override));
    MOCK_METHOD(bool, IsDirectory, (), (override));
    MOCK_METHOD(bool, IsEmpty, (), (override));

};

// TODO: GOOGLE TEST

TEST(IsCorrectnessOfInputTest, Entering_Correct_Data_True) {
     // Arrange
    Directory dir;
    Directory dirTwo;
    auto path = fs::current_path().string();
    
    // Act
    char *argv[] = {(char*)"", (char*)path.c_str(), (char*)"dir", (char*)"dirTwo"};

    // Assert
    ASSERT_TRUE(IsCorrectnessOfInput(dir, dirTwo, 4, argv));
}

TEST(IsCorrectnessOfInputTest, Incorrect_Data_Entry_False) {
     // Arrange
    Directory dir;
    Directory dirTwo;
    auto path = fs::current_path().string();

    // Act
    char *argv[] = {(char*)"", (char*)path.c_str(), (char*)"dir"};

    // Assert
    ASSERT_FALSE(IsCorrectnessOfInput(dir, dirTwo, 3, argv));
}

TEST(IsCorrectnessOfInputTest, Path_To_Directory_Was_Entered_Incorrectly_False) {
     // Arrange
    Directory dir;
    Directory dirTwo;

    // Act
    char *argv[] = {(char*)"", (char*)"/Users/user//Users/user//Users/user/", (char*)"dir"};

    // Assert
    ASSERT_FALSE(IsCorrectnessOfInput(dir, dirTwo, 4, argv));
}

TEST(IsExistsDirectoryTest, Directories_Exist_True) {
    // Arrange
    Directory dir(CreateDir("dir"));
    Directory dirTwo(CreateDir("dirTwo"));


    // Assert 
    ASSERT_TRUE(IsExistsDirectory(dir, dirTwo));

    fs::remove_all(dir.getDir());
    fs::remove_all(dirTwo.getDir());
}

TEST(IsExistsDirectoryTest, Directory_Not_Found_False) {
    // Arrange
    Directory dir(fs::current_path());
    Directory dirTwo;


    // Assert 
    ASSERT_FALSE(IsExistsDirectory(dir, dirTwo));
}

TEST(IsExistFilesTest, Files_Exist_True) {
    // Arrange
    Directory dir(CreateDir("dir"));
    Directory dirTwo(CreateDir("dirTwo"));

    // Act
    CreateFiles(dir, "file", "fileTwo");
    CreateFiles(dirTwo, "files", "fileTwo");

    // Assert 
    ASSERT_TRUE(IsExistFiles(dir, dirTwo));

    fs::remove_all(dir.getDir());
    fs::remove_all(dirTwo.getDir());
}

TEST(IsExistFilesTest, Files_In_Directory_DoNot_Exist_False) {
    // Arrange
    Directory dir(CreateDir("dir"));
    Directory dirTwo(CreateDir("dirTwo"));

    // Act
    CreateFiles(dir, "file", "fileTwo");

    // Assert 
    ASSERT_FALSE(IsExistFiles(dir, dirTwo));

    fs::remove_all(dir.getDir());
    fs::remove_all(dirTwo.getDir());
}

// TODO: MOCK TEST

using ::testing::Return;

TEST(IsExistsDirectoryTest, Call_getDir_Never) {
     // Arrang
    FileSustemMock dirMock;
    FileSustemMock dirTwoMock;

    // Assert
    EXPECT_CALL(dirMock, getDir())
    .Times(0);
    
     // Assert
    EXPECT_FALSE(IsExistsDirectory(dirMock, dirTwoMock));
}

TEST(SearchDuplicatTest, Call_ItBegin_Once) {
     // Arrang
    FileSustemMock dirMock;
    FileSustemMock dirTwoMock;

    // Assert
    EXPECT_CALL(dirMock, ItBegin())
    .Times(1);

    // Act
    SearchDuplicat(dirMock, dirTwoMock);
}

TEST(SearchDuplicatTest, Call_ItEnd_Once) {
    // Arrang
    FileSustemMock dirMock;
    FileSustemMock dirTwoMock;

    // Assert
    EXPECT_CALL(dirMock, ItEnd())
    .Times(1);

    // Act
    SearchDuplicat(dirMock, dirTwoMock);
}

TEST(IsExistsDirectoryTest, Call_IsDirectory_Once) {
     // Arrang
    FileSustemMock dirMock;
    FileSustemMock dirTwoMock;

    // Assert
    EXPECT_CALL(dirMock, IsDirectory())
    .Times(3)
    .WillRepeatedly(Return(false));

    // Act
    IsExistsDirectory(dirMock, dirTwoMock);
}

TEST(IsExistFilesTest, Call_IsEmpty_Once) {
     // Arrang
    FileSustemMock dirMock;
    FileSustemMock dirTwoMock;

    // Assert
    EXPECT_CALL(dirMock, IsEmpty())
    .Times(1)
    .WillRepeatedly(Return(false));

    // Act
    IsExistFiles(dirMock, dirTwoMock);
}

#endif