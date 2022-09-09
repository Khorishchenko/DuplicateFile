#ifndef CLASS_H
#define CLASS_H

#include <vector>
#include <fstream>
#include <algorithm>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;
typedef std::experimental::filesystem::v1::path t_typeFile;

class ExpeFilesystem {
    
public:
    ExpeFilesystem() : m_Dir(fs::path()) {}

    t_typeFile getDir() {
        return m_Dir;
    }

    t_typeFile Iterator() {
        return fs::recursive_directory_iterator it(m_Dir);
    }

    t_typeFile FileName() {

    }

    bool IsDirectory() {
        return fs::is_directory(m_Dir);
    }

    bool IsEmpty() {
        fs::is_empty(m_Dir);
    }
private:
    t_typeFile m_Dir;
}



#endif