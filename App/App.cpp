#include <iostream>
#include <Windows.h>
#include <SysInfoLib.h>
#include "../InfoDLL/InfoDLL.h"
#pragma comment(lib, "InfoDLL.lib")

// Function types for DLL imports
typedef void (*PRINTSYSTEMMETRICS)();
typedef void (*PRINTSYSTEMPARAMETERS)();

int main()
{
    std::cout << "System Information:\n";
    std::cout << "-----------------\n";
    
    // Static library calls
    PrintComputerName();
    PrintDomainName();
    PrintUserName();
    PrintFullUserName();

    // InfoDLL implicit linking
    std::cout << "\nSystem Paths:\n";
    std::cout << "-----------------\n";
    PrintSystemPaths();

    std::cout << "\nOperating System Information:\n";
    std::cout << "-----------------\n";
    PrintOSVersion();

    std::cout << "\nDate and Time Information:\n";
    std::cout << "-----------------\n";
    PrintDateTime();

    std::cout << "\nSystem Metrics (Explicit):\n";
    std::cout << "-----------------\n";
    
    // Load metrics DLL explicitly
    HMODULE hMetrics = LoadLibraryA("MetricsDLL.dll");
    if (hMetrics) {
        auto printMetrics = (PRINTSYSTEMMETRICS)GetProcAddress(hMetrics, "PrintSystemMetrics");
        if (printMetrics) {
            printMetrics();
        }
        FreeLibrary(hMetrics);
    }

    std::cout << "\nSystem Parameters (Delayed):\n";
    std::cout << "-----------------\n";

    // Load parameters DLL with delayed loading
    HMODULE hParams = LoadLibraryA("ParamsDLL.dll");
    if (hParams) {
        auto printParams = (PRINTSYSTEMPARAMETERS)GetProcAddress(hParams, "PrintSystemParameters");
        if (printParams) {
            printParams();
        }
        FreeLibrary(hParams);
    }

    return 0;
}
