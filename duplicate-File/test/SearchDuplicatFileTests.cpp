#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Verifications.h"
#include "SearchDuplicatFile.h"

#include <limits>
#include <vector>
#include <ctime>
#include <cstdio>
#include <string>

namespace fs = std::experimental::filesystem;
typedef std::experimental::filesystem::v1::path t_typeFile;

t_typeFile CreateDir(std::string nameDir) {

    t_typeFile resDir = fs::current_path();

    resDir = resDir / nameDir;
    fs::create_directories(resDir);

    return resDir;
}

void CreateFiles(fs::path &resDir, std::string name_file1= "", std::string name_file2 = "", std::string name_file3 = "") {

    std::vector<std::string> res_file = 
    {
        resDir.string() + "/" + name_file1,
        resDir.string() + "/" + name_file2,
        resDir.string() + "/" + name_file3
    };

    // create files 
    for(auto &f: res_file) {
        std::ofstream(f) << "data";
    }
}

TEST(SearchDuplicatTest, Duplicate_Found) {
     // Arrange
    t_typeFile dir = CreateDir("dir");
    t_typeFile dirTwo = CreateDir("dirTwo");

    // Act
    CreateFiles(dir, "file", "fileTwo");
    CreateFiles(dirTwo, "files", "fileTwo");
  
    // Assert
    ASSERT_TRUE(SearchDuplicat(dir, dirTwo));

    fs::remove_all(dir);
    fs::remove_all(dirTwo);
}

TEST(SearchDuplicatTest, Duplicate_Not_Found) {
     // Arrange
    t_typeFile dir = CreateDir("dir");
    t_typeFile dirTwo = CreateDir("dirTwo");

    // Act
    CreateFiles(dir, "file", "fileTwo");
    CreateFiles(dirTwo, "files", "filesTwo");
    
    // Assert
    ASSERT_FALSE(SearchDuplicat(dir, dirTwo));

    fs::remove_all(dir);
    fs::remove_all(dirTwo);
}

TEST(IsCorrectnessOfInputTest, Entering_Correct_Data) {
     // Arrange
    auto dir = fs::path();
    auto dirTwo = fs::path();
    auto path = fs::current_path().string();
    
    // Act
    char *argv[] = {(char*)"", (char*)path.c_str(), (char*)"dir", (char*)"dirTwo"};

    // Assert
    ASSERT_TRUE(IsCorrectnessOfInput(dir, dirTwo, 4, argv));
}

TEST(IsCorrectnessOfInputTest, Incorrect_Data_Entry) {
     // Arrange
    auto dir = fs::path();
    auto dirTwo = fs::path();

    // Act
    char *argv[] = {(char*)"", (char*)"/Users/user/Desktop/projectPIRWork_2/build", (char*)"dir"};

    // Assert
    ASSERT_FALSE(IsCorrectnessOfInput(dir, dirTwo, 3, argv));
}


TEST(IsCorrectnessOfInputTest, Path_To_Directory_Was_Entered_Incorrectly) {
     // Arrange
    auto dir = fs::path();
    auto dirTwo = fs::path();

    // Act
    char *argv[] = {(char*)"", (char*)"/Users/user//Users/user//Users/user/", (char*)"dir"};

    // Assert
    ASSERT_FALSE(IsCorrectnessOfInput(dir, dirTwo, 4, argv));
}

TEST(IsExistsDirectoryTest, Directories_Exist) {
    // Arrange
    t_typeFile dir = CreateDir("dir");
    t_typeFile dirTwo = CreateDir("dirTwo");


    // Assert 
    ASSERT_TRUE(IsExistsDirectory(dir, dirTwo));

    fs::remove_all(dir);
    fs::remove_all(dirTwo);
}

TEST(IsExistsDirectoryTest, Directory_Not_Found) {
    // Arrange
    t_typeFile dir = fs::current_path();
    t_typeFile dirTwo = fs::current_path();


    // Assert 
    ASSERT_TRUE(IsExistsDirectory(dir, dirTwo));
}

TEST(IsExistFilesTest, Files_Exist) {
    // Arrange
    t_typeFile dir = CreateDir("dir");
    t_typeFile dirTwo = CreateDir("dirTwo");

    // Act
    CreateFiles(dir, "file", "fileTwo");
    CreateFiles(dirTwo, "files", "fileTwo");

    // Assert 
    ASSERT_TRUE(IsExistFiles(dir, dirTwo));

    fs::remove_all(dir);
    fs::remove_all(dirTwo);
}

TEST(IsExistFilesTest, Files_In_Directory_DoNot_Exist) {
    // Arrange
    t_typeFile dir = CreateDir("dir");
    t_typeFile dirTwo = CreateDir("dirTwo");

    // Act
    CreateFiles(dir, "file", "fileTwo");

    // Assert 
    ASSERT_FALSE(IsExistFiles(dir, dirTwo));

    fs::remove_all(dir);
    fs::remove_all(dirTwo);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
