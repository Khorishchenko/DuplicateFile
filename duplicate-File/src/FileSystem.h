#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <limits>
#include <ctime>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;
typedef std::experimental::filesystem::v1::path TypeFile_t;
typedef std::experimental::filesystem::v1::directory_iterator IteratorFile_t;

class FileSystem {
    
public:
    FileSystem(TypeFile_t Dir = fs::path()) : m_Dir(Dir) {}

    virtual TypeFile_t& getDir() {
        return m_Dir;
    }

    virtual IteratorFile_t ItBegin() {
         fs::directory_iterator it(m_Dir);
         return it;
    }

    virtual IteratorFile_t ItEnd() {
        fs::directory_iterator end;
        return end;
    }

    virtual bool IsDirectory() {
        return fs::is_directory(m_Dir);
    }

    virtual bool IsEmpty() {
        return fs::is_empty(m_Dir);
    }
private:
    TypeFile_t m_Dir;
};

#endif