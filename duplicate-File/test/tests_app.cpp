#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "functions_app.h"

#include <limits>
#include <vector>
#include <ctime>
#include <cstdio>
#include <string>

namespace fs = std::experimental::filesystem;
typedef std::experimental::filesystem::v1::path t_typeFile;

t_typeFile CreateDir(std::string nameDir) {

    t_typeFile res_dir = fs::current_path();

    res_dir = res_dir / nameDir;
    fs::create_directories(res_dir);

    return res_dir;
}

void CreateFiles(fs::path &res_dir, std::string name_file1= "", std::string name_file2 = "", std::string name_file3 = "") {

    std::vector<std::string> res_file = 
    {
        res_dir.string() + "/" + name_file1,
        res_dir.string() + "/" + name_file2,
        res_dir.string() + "/" + name_file3
    };

    // create files 
    for(auto &f: res_file) {
        std::ofstream(f) << "data";
    }
}

TEST(SearchDuplicatTest, Duplicate_Found) {
     // Arrange
    t_typeFile dir = CreateDir("dir");
    t_typeFile dir_two = CreateDir("dir_two");

    // Act
    CreateFiles(dir, "file", "file_two");
    CreateFiles(dir_two, "files", "file_two");

    std::string hasNoDupFiles = "No duplicate files found";
    
    // Assert
    ASSERT_NE(SearchDuplicat(dir, dir_two).front(), hasNoDupFiles);

    fs::remove_all(dir);
    fs::remove_all(dir_two);
}

TEST(SearchDuplicatTest, Duplicate_Not_Found) {
     // Arrange
    t_typeFile dir = CreateDir("dir");
    t_typeFile dir_two = CreateDir("dir_two");

    // Act
    CreateFiles(dir, "file", "file_two");
    CreateFiles(dir_two, "files", "files_two");

    std::string hasNoDupFiles = "No duplicate files found";
    
    // Assert
    ASSERT_EQ(SearchDuplicat(dir, dir_two).front(), hasNoDupFiles);

    fs::remove_all(dir);
    fs::remove_all(dir_two);
}

TEST(CheckForCorrectnessOfInputTest, Entering_Correct_Data) {
     // Arrange
    auto dir = fs::path();
    auto dir_two = fs::path();

    // Act
    char *argv[] = {(char*)"", (char*)"/Users/user/Desktop/projectPIRWork_2/build", (char*)"dir", (char*)"dir_two"};

    // Assert
    ASSERT_TRUE(CheckForCorrectnessOfInput(dir, dir_two, 4, argv));
}

TEST(CheckForCorrectnessOfInputTest, Incorrect_Data_Entry) {
     // Arrange
    auto dir = fs::path();
    auto dir_two = fs::path();

    // Act
    char *argv[] = {(char*)"", (char*)"/Users/user/Desktop/projectPIRWork_2/build", (char*)"dir"};

    // Assert
    ASSERT_FALSE(CheckForCorrectnessOfInput(dir, dir_two, 3, argv));
}


TEST(CheckForCorrectnessOfInputTest, Path_To_Directory_Was_Entered_Incorrectly) {
     // Arrange
    auto dir = fs::path();
    auto dir_two = fs::path();

    // Act
    char *argv[] = {(char*)"", (char*)"/Users/user//Users/user//Users/user/", (char*)"dir"};

    // Assert
    ASSERT_FALSE(CheckForCorrectnessOfInput(dir, dir_two, 4, argv));
}

TEST(CheckingTheDirectoryExistsTest, Directories_Exist) {
    // Arrange
    t_typeFile dir = CreateDir("dir");
    t_typeFile dir_two = CreateDir("dir_two");


    // Assert 
    ASSERT_TRUE(CheckingTheDirectoryExists(dir, dir_two));

    fs::remove_all(dir);
    fs::remove_all(dir_two);
}

TEST(CheckingTheDirectoryExistsTest, Directory_Not_Found) {
    // Arrange
    t_typeFile dir = fs::current_path();
    t_typeFile dir_two = fs::current_path();


    // Assert 
    ASSERT_TRUE(CheckingTheDirectoryExists(dir, dir_two));
}

TEST(CheckingIfFilesExistInTheDedirectoryTest, Files_Exist) {
    // Arrange
    t_typeFile dir = CreateDir("dir");
    t_typeFile dir_two = CreateDir("dir_two");

    // Act
    CreateFiles(dir, "file", "file_two");
    CreateFiles(dir_two, "files", "file_two");

    // Assert 
    ASSERT_TRUE(CheckingIfFilesExistInTheDedirectory(dir, dir_two));

    fs::remove_all(dir);
    fs::remove_all(dir_two);
}

TEST(CheckingIfFilesExistInTheDedirectoryTest, Files_In_Directory_DoNot_Exist) {
    // Arrange
    t_typeFile dir = CreateDir("dir");
    t_typeFile dir_two = CreateDir("dir_two");

    // Act
    CreateFiles(dir, "file", "file_two");

    // Assert 
    ASSERT_FALSE(CheckingIfFilesExistInTheDedirectory(dir, dir_two));

    fs::remove_all(dir);
    fs::remove_all(dir_two);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
