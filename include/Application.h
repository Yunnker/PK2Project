#pragma once
#include "FileManager.h"

#include <iostream>
#include <string>

class Application
{
public:

	Application();
	Application(int argc, char* argv[]);
	void Run();
	void m_End(int x);

private:
	FileManager m_fileManager;
	std::string m_input;

	enum EndCode
	{
		WrongPass = 1,
	};

};