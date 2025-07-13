#pragma once

#define PRINTLN(x) std::cout << Locale::GetString(x) << std::endl

namespace Locale {
	enum Localization {
		LOCALIZATION_ENG,
		LOCALIZATION_PL,

		LOCALIZATION_COUNT
	};

	enum StringID
	{
		STRING_WELCOME_TO_PASSWORD_DATABASE,
		STRING_HOW_DO_YOU_WANT_TO_START_THE_PROGRAM,
		STRING_1_FRESH_START,
		STRING_2_READ_DEFAULT_PASSWORD_FILE,
		STRING_3_READ_OTHER_PASSWORD_FILE,
		STRING_ARE_YOU_SURE,
		STRING_ENTER_PATH_TO_PASSWORD_FILE,
		STRING_ENTER_PASSWORD_FOR_DATABASE,
		STRING_MENU,
		STRING_1_PRINT_ALL_NAMES_AND_CONTENTS,
		STRING_2_PRINT_ALL_NAMES,
		STRING_3_PRINT_ONLY_FOLDERS,
		STRING_4_ENTER_ROOT_FOLDER,
		STRING_5_FIND_PASSWORD_BY_NAME,
		STRING_0_END_PROGRAM,

		STRING_COUNT
	};

	const char* Strings[(size_t)STRING_COUNT * (size_t)LOCALIZATION_COUNT];
	static Localization g_localization = LOCALIZATION_ENG;

	void InitStrings() {
		// English
		Strings[(size_t)STRING_WELCOME_TO_PASSWORD_DATABASE + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] = 
			"Welcome to Password Database!";
		Strings[(size_t)STRING_HOW_DO_YOU_WANT_TO_START_THE_PROGRAM + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] = 
			"How do you want to start the program?";
		Strings[(size_t)STRING_1_FRESH_START + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] = 
			"1. Fresh start";
		Strings[(size_t)STRING_2_READ_DEFAULT_PASSWORD_FILE + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] = 
			"2. Read default password file (db.txt)";
		Strings[(size_t)STRING_3_READ_OTHER_PASSWORD_FILE + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] = 
			"3. Read other password file";
		Strings[(size_t)STRING_ARE_YOU_SURE + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] = 
			"Are you sure? y/n (This will overwrite db.txt)";
		Strings[(size_t)STRING_ENTER_PATH_TO_PASSWORD_FILE + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] = 
			"Enter path to other password file:";
		Strings[(size_t)STRING_ENTER_PASSWORD_FOR_DATABASE + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] = 
			"Enter password for database:";
		Strings[(size_t)STRING_MENU + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] = 
			"MENU:";
		Strings[(size_t)STRING_1_PRINT_ALL_NAMES_AND_CONTENTS + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] = 
			"1. Print all names and contents of elements";
		Strings[(size_t)STRING_2_PRINT_ALL_NAMES + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] = 
			"2. Print only names";
		Strings[(size_t)STRING_3_PRINT_ONLY_FOLDERS + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] = 
			"3. Print only folders";
		Strings[(size_t)STRING_4_ENTER_ROOT_FOLDER + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] = 
			"4. Enter root folder";
		Strings[(size_t)STRING_5_FIND_PASSWORD_BY_NAME + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] = 
			"5. Find element by name";
		Strings[(size_t)STRING_0_END_PROGRAM + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] = 
			"0. End program";

		// Polish
		Strings[(size_t)STRING_WELCOME_TO_PASSWORD_DATABASE + (size_t)LOCALIZATION_PL * (size_t)STRING_COUNT] = 
			"Witaj w Bazie Danych Hasel!";
		Strings[(size_t)STRING_HOW_DO_YOU_WANT_TO_START_THE_PROGRAM + (size_t)LOCALIZATION_PL * (size_t)STRING_COUNT] = 
			"Jak chcesz rozpoczac program?";
	}

	const char* GetString(StringID id) {
		if (id < 0 || id >= STRING_COUNT) return "";
		return Strings[(size_t)g_localization * (size_t)STRING_COUNT + (size_t)id];
	}
}
