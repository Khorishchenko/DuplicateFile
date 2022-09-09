#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <vector>
#include <fstream>
#include <algorithm>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;
typedef std::experimental::filesystem::v1::path t_TypeFile;

class FileSystem {
    
public:
    FileSystem() : m_Dir(fs::path()) {}

    t_TypeFile getDir() {
        return m_Dir;
    }

    std::experimental::filesystem::v1::__cxx11::recursive_directory_iterator Iterator() {
        fs::recursive_directory_iterator it(m_Dir);
        return it;
    }

    t_TypeFile FileName() {

    }

    bool IsDirectory() {
        return fs::is_directory(m_Dir);
    }

    bool IsEmpty() {
        fs::is_empty(m_Dir);
    }
private:
    t_TypeFile m_Dir;
}

#endif