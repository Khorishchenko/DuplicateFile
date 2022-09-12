#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Verifications.h"
#include "SearchDuplicatFile.h"
#include "FileSystem.h"

TypeFile_t CreateDir(std::string nameDir) {

    TypeFile_t resDir = fs::current_path();

    resDir = resDir / nameDir;
    fs::create_directories(resDir);

    return resDir;
}

void CreateFiles(FileSystem &resDir, std::string nameFile = "", std::string nameFileTwo = "", std::string nameFileThree = "") {

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

class FileSustemMock : public FileSystem {

public:

    MOCK_METHOD(TypeFile_t&, getDir, (), (override));
    MOCK_METHOD(IteratorFile_t, ItBegin, (), (override));
    MOCK_METHOD(IteratorFile_t, ItEnd, (), (override));
    MOCK_METHOD(bool, IsDirectory, (), (override));
    MOCK_METHOD(bool, IsEmpty, (), (override));

};

// TODO: GOOGLE TEST

TEST(SearchDuplicatTest, Duplicate_Found) {
     // Arrange
    FileSystem dir(CreateDir("dir"));
    FileSystem dirTwo(CreateDir("dirTwo"));

    // Act
    CreateFiles(dir, "file", "fileTwo");
    CreateFiles(dirTwo, "files", "fileTwo");
  
    // Assert
    ASSERT_TRUE(SearchDuplicat(dir, dirTwo));

    fs::remove_all(dir.getDir());
    fs::remove_all(dirTwo.getDir());
}

TEST(SearchDuplicatTest, Duplicate_Not_Found) {
     // Arrange
    FileSystem dir(CreateDir("dir"));
    FileSystem dirTwo(CreateDir("dirTwo"));

    // Act
    CreateFiles(dir, "file", "fileTwo");
    CreateFiles(dirTwo, "files", "filesTwo");
    
    // Assert
    ASSERT_FALSE(SearchDuplicat(dir, dirTwo));

    fs::remove_all(dir.getDir());
    fs::remove_all(dirTwo.getDir());
}

TEST(IsCorrectnessOfInputTest, Entering_Correct_Data) {
     // Arrange
    FileSystem dir;
    FileSystem dirTwo;
    auto path = fs::current_path().string();
    
    // Act
    char *argv[] = {(char*)"", (char*)path.c_str(), (char*)"dir", (char*)"dirTwo"};

    // Assert
    ASSERT_TRUE(IsCorrectnessOfInput(dir, dirTwo, 4, argv));
}

TEST(IsCorrectnessOfInputTest, Incorrect_Data_Entry) {
     // Arrange
    FileSystem dir;
    FileSystem dirTwo;
    auto path = fs::current_path().string();

    // Act
    char *argv[] = {(char*)"", (char*)path.c_str(), (char*)"dir"};

    // Assert
    ASSERT_FALSE(IsCorrectnessOfInput(dir, dirTwo, 3, argv));
}

TEST(IsCorrectnessOfInputTest, Path_To_Directory_Was_Entered_Incorrectly) {
     // Arrange
    FileSystem dir;
    FileSystem dirTwo;

    // Act
    char *argv[] = {(char*)"", (char*)"/Users/user//Users/user//Users/user/", (char*)"dir"};

    // Assert
    ASSERT_FALSE(IsCorrectnessOfInput(dir, dirTwo, 4, argv));
}

TEST(IsExistsDirectoryTest, Directories_Exist) {
    // Arrange
    FileSystem dir(CreateDir("dir"));
    FileSystem dirTwo(CreateDir("dirTwo"));


    // Assert 
    ASSERT_TRUE(IsExistsDirectory(dir, dirTwo));

    fs::remove_all(dir.getDir());
    fs::remove_all(dirTwo.getDir());
}

TEST(IsExistsDirectoryTest, Directory_Not_Found) {
    // Arrange
    FileSystem dir(fs::current_path());
    FileSystem dirTwo(fs::current_path());


    // Assert 
    ASSERT_TRUE(IsExistsDirectory(dir, dirTwo));
}

TEST(IsExistFilesTest, Files_Exist) {
    // Arrange
    FileSystem dir(CreateDir("dir"));
    FileSystem dirTwo(CreateDir("dirTwo"));

    // Act
    CreateFiles(dir, "file", "fileTwo");
    CreateFiles(dirTwo, "files", "fileTwo");

    // Assert 
    ASSERT_TRUE(IsExistFiles(dir, dirTwo));

    fs::remove_all(dir.getDir());
    fs::remove_all(dirTwo.getDir());
}

TEST(IsExistFilesTest, Files_In_Directory_DoNot_Exist) {
    // Arrange
    FileSystem dir(CreateDir("dir"));
    FileSystem dirTwo(CreateDir("dirTwo"));

    // Act
    CreateFiles(dir, "file", "fileTwo");

    // Assert 
    ASSERT_FALSE(IsExistFiles(dir, dirTwo));

    fs::remove_all(dir.getDir());
    fs::remove_all(dirTwo.getDir());
}

// TODO: MOCK TEST

using ::testing::Return;

TEST(FileSystemTest, getDir) {
     // Arrang
    FileSustemMock dirMock;
    FileSustemMock dirTwoMock;

    // Assert
    EXPECT_CALL(dirMock, getDir())
    .Times(0);

    // Act
    char *argv[] = {(char*)"", (char*)"/Users/user//Users/user//Users/user/", (char*)"dir"};
    
     // Assert
    EXPECT_FALSE(IsExistsDirectory(dirMock, dirTwoMock));
}

TEST(FileSystemTest, ItBegin) {
     // Arrang
    FileSustemMock dirMock;
    FileSustemMock dirTwoMock;

    // Assert
    EXPECT_CALL(dirMock, ItBegin())
    .Times(1);

    // Act
    SearchDuplicat(dirMock, dirTwoMock);
}

TEST(FileSystemTest, ItEnd) {
    // Arrang
    FileSustemMock dirMock;
    FileSustemMock dirTwoMock;

    // Assert
    EXPECT_CALL(dirMock, ItEnd())
    .Times(1);

    // Act
    SearchDuplicat(dirMock, dirTwoMock);
}

TEST(FileSystemTest, IsDirectory) {
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

TEST(FileSystemTest, IsEmpty) {
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

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
