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
		STRING_ENTER_NAME_OF_ELEMENT_YOU_WANT_TO_FIND,
		STRING_ELEMENT_CREATION_MENU,
		STRING_1_NEW_FOLDER,
		STRING_2_NEW_LP,
		STRING_0_GO_BACK,
		STRING_WRONG_INPUT,
		STRING_ELEMENT_CREATION_SUCCESS,
		STRING_POSITION_OUT_OF_RANGE,
		STRING_4_SELECT_ELEMENT,
		STRING_5_ADD_ELEMENT,
		STRING_6_DELETE_ELEMENT,
		STRING_ENTER_ELEMENTS_INDEX,
		STRING_INCORRECT_INDEX,
		STRING_INCORRECT_ELEMENT_TYPE,
		STRING_ENTER_ELEMENTS_NAME,
		STRING_ENTER_ELEMENTS_LOGIN,
		STRING_ENTER_ELEMENTS_PASSWORD,
		STRING_ENTER_ELEMENTS_NEW_NAME,
		STRING_ENTER_ELEMENTS_NEW_LOGIN,
		STRING_ENTER_ELEMENTS_NEW_PASSWORD,
		STRING_SYNTAX_ERROR_WHILE_TRYING_TO_EDIT_LP,
		STRING_SUCCESSFULLY_EDITED_LP,
		STRING_1_PRINT_CONENTS,
		STRING_2_EDIT,
		STRING_DATABASE_READ_ERROR,
		STRING_ENTER_NEW_PASSWORD_FOR_DATABASE,

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
		Strings[(size_t)STRING_ENTER_NAME_OF_ELEMENT_YOU_WANT_TO_FIND + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] =
			"Enter name of element you want to find:";
		Strings[(size_t)STRING_ELEMENT_CREATION_MENU + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] =
			"ELEMENT CREATION MENU:";
		Strings[(size_t)STRING_1_NEW_FOLDER + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] =
			"1. New folder";
		Strings[(size_t)STRING_2_NEW_LP + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] =
			"2. New LP (Login and Password)";
		Strings[(size_t)STRING_0_GO_BACK + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] =
			"0. Go back";
		Strings[(size_t)STRING_WRONG_INPUT + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] =
			"Wrong input!";
		Strings[(size_t)STRING_ELEMENT_CREATION_SUCCESS + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] =
			"Element creation success!";
		Strings[(size_t)STRING_POSITION_OUT_OF_RANGE + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] =
			"Position out of range!";
		Strings[(size_t)STRING_4_SELECT_ELEMENT + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] =
			"4. Select element";
		Strings[(size_t)STRING_5_ADD_ELEMENT + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] =
			"5. Add new element";
		Strings[(size_t)STRING_6_DELETE_ELEMENT + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] =
			"6. Delete element";
		Strings[(size_t)STRING_ENTER_ELEMENTS_INDEX + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] =
			"Enter element's index:";
		Strings[(size_t)STRING_INCORRECT_INDEX + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] =
			"Incorrect index!";
		Strings[(size_t)STRING_INCORRECT_ELEMENT_TYPE + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] =
			"Incorrect element type!";
		Strings[(size_t)STRING_ENTER_ELEMENTS_NAME + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] =
			"Enter element's name:";
		Strings[(size_t)STRING_ENTER_ELEMENTS_LOGIN + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] =
			"Enter elements's login:";
		Strings[(size_t)STRING_ENTER_ELEMENTS_PASSWORD + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] =
			"Enter elements's password:";
		Strings[(size_t)STRING_ENTER_ELEMENTS_NEW_NAME + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] =
			"Enter element's new name (type '/' to skip):";
		Strings[(size_t)STRING_ENTER_ELEMENTS_NEW_LOGIN + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] =
			"Enter elements's new login (type '/' to skip):";
		Strings[(size_t)STRING_ENTER_ELEMENTS_NEW_PASSWORD + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] =
			"Enter elements's new password (type '/' to skip):";
		Strings[(size_t)STRING_SYNTAX_ERROR_WHILE_TRYING_TO_EDIT_LP + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] =
			"Syntax error while trying to edit LP!";
		Strings[(size_t)STRING_SUCCESSFULLY_EDITED_LP + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] =
			"Successfully edited LP!";
		Strings[(size_t)STRING_1_PRINT_CONENTS + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] =
			"1. Print contents";
		Strings[(size_t)STRING_2_EDIT + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] =
			"2. Edit";
		Strings[(size_t)STRING_DATABASE_READ_ERROR + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] =
			"Database file read error";
		Strings[(size_t)STRING_ENTER_NEW_PASSWORD_FOR_DATABASE + (size_t)LOCALIZATION_ENG * (size_t)STRING_COUNT] =
			"Enter new password for your database file:";



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
