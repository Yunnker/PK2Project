#pragma once
#include <fstream>
#include <string>
#include "Elements.h"
#include "Koder.h"



class FileManager{
public:
    void Init(std::string s);
    void FreshCreate();
    void ReadBase();
    void Save(std::string s);

    LinkedList m_root;
    Koder m_koder;

    template <typename T>
    FileManager& operator<<(const T& data) {
        Save(data);
        return *this;
    }

    void SetPass(std::string s);

private:
    std::fstream* m_file;
    std::string m_fname;
    std::string m_pass;
};

