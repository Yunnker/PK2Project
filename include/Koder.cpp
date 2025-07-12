#include "Koder.h"

std::string Koder::EncryptLine(const std::string& line) {
	std::string result = line;
	for (int i = 0; i < result.length(); i++) {
		result[i] += i % 4 + i % 3;
	}
	return result;
}

std::string Koder::DecryptLine(const std::string& line) {
	std::string result = line;
	for (int i = 0; i < result.length(); i++) {
		result[i] -= i % 4 + i % 3;
	}
	return result;
}

size_t Koder::GetHash()
{
	return m_hash;
}

void Koder::SetHash(size_t x)
{
	m_hash = x;
}

size_t Koder::HashMeThisStrXTimes(std::string& str, uint64_t x)
{
	size_t var = m_str_hash(str);
	for (size_t i = 1; i < x; i++)
	{
		var = m_size_t_hash(var);
	}
	return var;
}