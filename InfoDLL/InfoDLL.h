#pragma once

#ifdef _USRDLL
#define INFODLL_API __declspec(dllexport)
#else
#define INFODLL_API __declspec(dllimport)
#endif

extern "C" INFODLL_API void PrintSystemPaths();
extern "C" INFODLL_API void PrintOSVersion();
extern "C" INFODLL_API void PrintDateTime();