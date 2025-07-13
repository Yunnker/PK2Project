#pragma once
#include <string>

class Koder {
public:
    std::string EncryptLine(const std::string& line);
    std::string DecryptLine(const std::string& line);

    size_t HashMeThisStrXTimes(const std::string& str, uint64_t x);

    size_t GetHash();
    void SetHash(size_t x);

private:
    std::hash<std::string> m_str_hash;
    std::hash<size_t> m_size_t_hash;

    size_t m_hash;
};