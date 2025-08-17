// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <Windows.h>
#include <iostream>

extern "C" __declspec(dllexport) void PrintSystemMetrics() {
    std::cout << "SM_CXDRAG: " << GetSystemMetrics(SM_CXDRAG) << std::endl;
    std::cout << "SM_CYDRAG: " << GetSystemMetrics(SM_CYDRAG) << std::endl;
    std::cout << "SM_CXMINIMIZED: " << GetSystemMetrics(SM_CXMINIMIZED) << std::endl;
    std::cout << "SM_CYMINIMIZED: " << GetSystemMetrics(SM_CYMINIMIZED) << std::endl;
    std::cout << "SM_REMOTESESSION: " << GetSystemMetrics(SM_REMOTESESSION) << std::endl;
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

