#pragma once

#ifdef TITAN_WINDOWS 
	#ifdef TITAN_BUILD_DLL
		#define TITAN_API __declspec(dllexport)
	#else
		#define TITAN_API __declspec(dllimport)
	#endif
#elif TITAN_LINUX
	#ifdef TITAN_BUILD_DLL
		#define TITAN_API __declspec(dllexport)
	#else
		#define TITAN_API __declspec(dllimport)
	#endif
#else 
	#error Titan only supports Windows and Linux!
#endif