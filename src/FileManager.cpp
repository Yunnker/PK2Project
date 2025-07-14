#include "FileManager.h"
#include <sstream>
#include "Localization.h"

void FileManager::Init(std::string s) {
	m_root.SetName("root");
	if (s.empty()) s = "db.txt";
	m_fname = s;

	m_file = new std::fstream(s, std::ios::in | std::ios::out);
	if (!m_file->is_open()) {
		PRINTLN(Locale::STRING_DATABASE_READ_ERROR);
		return;
	}

	std::string line;
	std::getline(*m_file, line);
	std::stringstream sstream(line);
	size_t temp = 0;
	sstream >> temp;
	m_koder.SetHash(temp);
}

void FileManager::ReadBase() {
	if (!m_file->good()) return;

	std::string line;
	m_file->clear();
	m_file->seekg(0);
	std::getline(*m_file, line); // Pomijamy hash

	while (std::getline(*m_file, line)) {
		std::string decrypted = m_koder.DecryptLine(line);
		m_root.Select(decrypted);
	}
}

void FileManager::FreshCreate()
{
	PRINTLN(Locale::STRING_ENTER_NEW_PASSWORD_FOR_DATABASE);
	std::string haslo = "";
	std::cin >> haslo;
	m_file = new std::fstream("db.txt", std::fstream::trunc | std::fstream::out | std::fstream::in);
	*m_file << m_koder.HashMeThisStrXTimes(haslo, 24225132) << std::endl;
}

void FileManager::Save(std::string s) {
	std::string encrypted = m_koder.EncryptLine(s);
	std::fstream file = std::fstream(m_fname, std::fstream::out | std::fstream::in | std::fstream::ate);
	file << encrypted << std::endl;
}

void FileManager::SetPass(std::string s)
{
	m_pass = s;
}
