// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "InfoDLL.h"
#include <Windows.h>
#include <ShlObj.h>
#include <iostream>
#include <iomanip>
#include <ctime>

// Function to get system folder path
std::string GetSystemFolderPath(int csidl) {
    char path[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPathA(NULL, csidl, NULL, 0, path))) {
        return path;
    }
    return "Path not found";
}

extern "C" __declspec(dllexport) void PrintSystemPaths() {
    std::cout << "System Directory Paths:\n";
    std::cout << "CSIDL_APPDATA: " << GetSystemFolderPath(CSIDL_APPDATA) << "\n";
    std::cout << "CSIDL_COMMON_APPDATA: " << GetSystemFolderPath(CSIDL_COMMON_APPDATA) << "\n";
    std::cout << "CSIDL_COMMON_DOCUMENTS: " << GetSystemFolderPath(CSIDL_COMMON_DOCUMENTS) << "\n";
    std::cout << "CSIDL_HISTORY: " << GetSystemFolderPath(CSIDL_HISTORY) << "\n";
    std::cout << "CSIDL_INTERNET_CACHE: " << GetSystemFolderPath(CSIDL_INTERNET_CACHE) << "\n";
    std::cout << "CSIDL_LOCAL_APPDATA: " << GetSystemFolderPath(CSIDL_LOCAL_APPDATA) << "\n";
    std::cout << "CSIDL_PERSONAL: " << GetSystemFolderPath(CSIDL_PERSONAL) << "\n";
    std::cout << "CSIDL_PROGRAM_FILES: " << GetSystemFolderPath(CSIDL_PROGRAM_FILES) << "\n";
    std::cout << "CSIDL_PROGRAM_FILES_COMMON: " << GetSystemFolderPath(CSIDL_PROGRAM_FILES_COMMON) << "\n";
    std::cout << "CSIDL_SYSTEM: " << GetSystemFolderPath(CSIDL_SYSTEM) << "\n";
    std::cout << "CSIDL_WINDOWS: " << GetSystemFolderPath(CSIDL_WINDOWS) << "\n";
}

extern "C" __declspec(dllexport) void PrintOSVersion() {
    OSVERSIONINFOA osvi;
    ZeroMemory(&osvi, sizeof(OSVERSIONINFOA));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOA);

#pragma warning(disable: 4996) // Disable deprecation warning
    GetVersionExA(&osvi);

    std::cout << "Operating System Version:\n";
    std::cout << "Version: " << osvi.dwMajorVersion << "." << osvi.dwMinorVersion << "\n";
    std::cout << "Build: " << osvi.dwBuildNumber << "\n";
}

extern "C" __declspec(dllexport) void PrintDateTime() {
    time_t now = time(0);
    tm local_tm;
    localtime_s(&local_tm, &now);

    char date[11];
    strftime(date, sizeof(date), "%d.%m.%Y", &local_tm);
    
    char time[9];
    strftime(time, sizeof(time), "%I:%M %p", &local_tm);

    std::cout << "Current Date and Time:\n";
    std::cout << "Date: " << date << "\n";
    std::cout << "Time: " << time << "\n";
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved)
{
    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

