#include "SearchDuplicatFileTests.cpp"

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