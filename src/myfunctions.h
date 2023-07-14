#ifndef _ADD_H
#define _ADD_H

#include <iostream>
#include <experimental/filesystem>
#include <fstream>
#include <algorithm>
#include <vector>


namespace fs = std::experimental::filesystem;
typedef std::experimental::filesystem::v1::path t_typeFile;


class duplicateSearch {
    t_typeFile res_dir = fs::current_path();

public:
    duplicateSearch() {

        // std::cout << "current_path is: " << res_dir << "\n" <<  std::endl;
    }

    void createDir(std::string nameDir) {
        res_dir = res_dir / nameDir;
        fs::create_directories(res_dir);
    }

    void createFiles(std::string name_file1= "", std::string name_file2 = "", std::string name_file3 = "") {

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

    void print() {
        std::cout << "files in directory " << res_dir.string() << "\n" << std::endl;
         for (fs::recursive_directory_iterator it(res_dir), end; it != end; ++it) {
            std::cout << it->path().filename() << std::endl;
        }
        std::cout << std::endl;
    }

    std::vector<std::string> searchDuplicat(const duplicateSearch &dir) {
        std::vector<std::string> duplicatFiles;
         for (fs::recursive_directory_iterator it(res_dir), end; it != end; ++it) {
            for (fs::recursive_directory_iterator it_2(dir.res_dir), end; it_2 != end; ++it_2) {
                if (it->path().filename() == it_2->path().filename()) {
                    std::cout << "dublicat is :" << it->path().filename() << std::endl;
                    duplicatFiles.push_back(it->path().filename().string());
                }
            }
         }
         return duplicatFiles;
    }

    t_typeFile getDir() {
        return res_dir;
    }
};

#endif