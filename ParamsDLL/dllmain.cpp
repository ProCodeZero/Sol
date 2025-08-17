// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <Windows.h>
#include <iostream>

extern "C" __declspec(dllexport) void PrintSystemParameters() {
    BOOL fontSmoothing = FALSE;
    SystemParametersInfo(SPI_GETFONTSMOOTHING, 0, &fontSmoothing, 0);
    std::cout << "Font Smoothing: " << (fontSmoothing ? "Enabled" : "Disabled") << std::endl;

    int mouseParams[3] = {0};
    SystemParametersInfo(SPI_GETMOUSE, 0, mouseParams, 0);
    std::cout << "Mouse Thresholds: " << mouseParams[0] << ", " << mouseParams[1] << ", " << mouseParams[2] << std::endl;
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

