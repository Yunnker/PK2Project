#include "Application.h"

Application::Application()
{
}

Application::Application(int argc, char* argv[])
{
}

void Application::Start()
{

	// ### Otwarcie programu
	int ans = 0;
	while (ans < 1 || ans > 3)
	{
		std::cout << "W jaki sposob chcesz rozpoczac program?" << std::endl;
		std::cout << "1. Swiezy start" << std::endl;
		std::cout << "2. Odczyt domyslnego pliku hasel (db.txt)" << std::endl;
		std::cout << "3. Odczyt innego pliku hasel" << std::endl;

		std::cin >> ans;
		if (ans == 1)
		{
			char x = 0;
			std::cout << "Na pewno? y/n (nadpisze to plik db.txt - jesli takowy istnieje)" << std::endl;
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
			std::cout << "Podaj nazwe pliku (wlacznie z rozszerzeniem)" << std::endl;
			std::cin >> x;
			m_fileManager.Init(x);
			break;
		default:
			break;
		}
	}
	
	// ### Wejscie do bazy hasel
	for (;;)
	{
		std::cout << "Podaj haslo do bazy:" << std::endl;
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

	// Odczyt i dekrypcja bazy
	m_fileManager.ReadBase();
	system("cls");

	// ### Glowne MENU
	std::cout << "Witaj w bazie!" << std::endl;
	for (;;)
	{
		std::cout << "MENU:" << std::endl;
		std::cout << "1. Wypisz wszystkie nazwy, loginy i hasla." << std::endl;
		std::cout << "2. Wypisz wszystkie obiekty." << std::endl;
		std::cout << "3. Wypisz tylko foldery." << std::endl;
		std::cout << "4. Wybierz folder." << std::endl;
		std::cout << "5. Znajdz haslo po nazwie." << std::endl;
		std::cout << "0. Zakoncz program." << std::endl;
		std::cin >> m_input;

		LinkedList temp;
		std::string h = "";
		switch (m_input[0])
		{
		default:
			break;
		case '1':	// Wypisz wszystkie nazwy, loginy i hasla
			system("cls");
			m_fileManager.m_root.PrintFull();
			std::cout << std::endl;
			break;
		case '2':	// Wypisz wszystkie obiekty
			system("cls");
			m_fileManager.m_root.Print();
			std::cout << std::endl;
			break;
		case '3':	// Wypisz tylko foldery
			system("cls");
			m_fileManager.m_root.PrintFolders();
			std::cout << std::endl;
			break;
		case '4':	// Wybierz folder
			system("cls");
			m_fileManager << m_fileManager.m_root.Select("");
			std::cout << std::endl;
			break;
		case '5':	// Znajdz haslo
			system("cls");
			std::cout << "Podaj nazwe pod ktora znajduje sie haslo" << std::endl;
			std::cin >> m_input;
			h = m_fileManager.m_root.Find(m_input);
			if (h != "")
				m_fileManager << h;
			std::cout << std::endl;
			break;
		case '0':	// Zakoncz program
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


