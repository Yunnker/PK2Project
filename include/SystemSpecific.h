#pragma once

#ifdef LINUX
	#define CONSOLE_CLEAR() system("clear")
#else
	#define CONSOLE_CLEAR() system("cls")
#endif 
