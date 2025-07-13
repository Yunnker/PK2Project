#include "Application.h"
#include "Localization.h"

Application::Application()
{
}

Application::Application(int argc, char* argv[])
{
}

void Application::Run()
{
	// ### Initilize localization
	Locale::InitStrings();

	// ### Start of the program
	int ans = 0;
	while (ans < 1 || ans > 3)
	{
		PRINTLN(Locale::STRING_HOW_DO_YOU_WANT_TO_START_THE_PROGRAM);
		PRINTLN(Locale::STRING_1_FRESH_START);
		PRINTLN(Locale::STRING_2_READ_DEFAULT_PASSWORD_FILE);
		PRINTLN(Locale::STRING_3_READ_OTHER_PASSWORD_FILE);

		std::cin >> ans;
		if (ans == 1)
		{
			char x = 0;
			PRINTLN(Locale::STRING_ARE_YOU_SURE);
			std::cin >> x;
			if (x != 'y')
				ans = 0;
		}
	}

	{
		std::string x = "";

		switch (ans)
		{
		case 1:
			m_fileManager.FreshCreate();
			m_fileManager.Init("");
			break;
		case 2:
			m_fileManager.Init("");
			break;
		case 3:
			PRINTLN(Locale::STRING_ENTER_PATH_TO_PASSWORD_FILE);
			std::cin >> x;
			m_fileManager.Init(x);
			break;
		default:
			break;
		}
	}
	
	// ### Opening the password database
	for (;;)
	{
		PRINTLN(Locale::STRING_ENTER_PASSWORD_FOR_DATABASE);
		std::cin >> m_input;
		size_t compare = m_fileManager.m_koder.HashMeThisStrXTimes(m_input,24225132);
		if (compare == m_fileManager.m_koder.GetHash())
		{
			m_fileManager.SetPass(m_input);
			break;
		}
		else if (m_input == "")
			return;
	}

	// Reading and decrypting the database
	m_fileManager.ReadBase();
	system("cls");

	// ### Main menu
	PRINTLN(Locale::STRING_WELCOME_TO_PASSWORD_DATABASE);
	for (;;)
	{
		PRINTLN(Locale::STRING_MENU);
		PRINTLN(Locale::STRING_1_PRINT_ALL_NAMES_AND_CONTENTS);
		PRINTLN(Locale::STRING_2_PRINT_ALL_NAMES);
		PRINTLN(Locale::STRING_3_PRINT_ONLY_FOLDERS);
		PRINTLN(Locale::STRING_4_ENTER_ROOT_FOLDER);
		PRINTLN(Locale::STRING_5_FIND_PASSWORD_BY_NAME);
		PRINTLN(Locale::STRING_0_END_PROGRAM);
		std::cin >> m_input;

		Folder temp;
		std::string h = "";
		switch (m_input[0])
		{
		default:
			break;
		case '1':	// PRINT ALL NAMES AND CONTENTS
			system("cls");
			m_fileManager.m_root.PrintFull();
			std::cout << std::endl;
			break;
		case '2':	// PRINT ALL NAMES
			system("cls");
			m_fileManager.m_root.Print();
			std::cout << std::endl;
			break;
		case '3':	// PRINT ONLY FOLDERS
			system("cls");
			m_fileManager.m_root.PrintFolders();
			std::cout << std::endl;
			break;
		case '4':	// ENTER ROOT FOLDER
			system("cls");
			m_fileManager << m_fileManager.m_root.Select("");
			std::cout << std::endl;
			break;
		case '5':	// FIND PASSWORD BY NAME
			system("cls");
			std::cout << "Podaj nazwe pod ktora znajduje sie haslo" << std::endl;
			std::cin >> m_input;
			h = m_fileManager.m_root.Find(m_input);
			if (h != "")
				m_fileManager << h;
			std::cout << std::endl;
			break;
		case '0':	// END PROGRAM
			system("cls");
			m_End(0);
			break;
		}
	}
	/**/

	/*		## TEST LAB ##
	LinkedList a;
	Standard b;
	LinkedList c;
	a.PushBack(b);
	c.PushBack(b);
	a.PushBackFolder(c);
	LP x(std::string("Yolo12"), std::string("Haslo"));
	a.FromPositionFolder(1)->PushBack(x);
	a.FromPositionFolder(1)->FromPosition<Object>(1)->SetName("Facebook");
	a.Print();

	LinkedList d;
	a.FromPositionFolder(1)->PushBackFolder(d);
	a.PushBackFolder(d);
	a.PrintFolders();
	a.PrintFull();
	a.FromPositionFolder(1)->FromPosition<Object>(1)->Edit("");
	a.PrintFull();
	*/
}

void Application::m_End(int x)
{
	std::cout << "Kod powodu zamkniecia: " << x << std::endl;
	exit(0);
}


