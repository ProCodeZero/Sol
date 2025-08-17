#include <iostream>
#include <Windows.h>
#include <SysInfoLib.h>

// Function types for DLL imports
typedef void (*PRINTSYSTEMMETRICS)();
typedef void (*PRINTSYSTEMPARAMETERS)();
typedef void (*PRINTSYSTEMPATHS)();
typedef void (*PRINTOSVERSION)();
typedef void (*PRINTDATETIME)();

int main()
{
    std::cout << "System Information:\n";
    std::cout << "-----------------\n";
    
    // Static library calls
    PrintComputerName();
    PrintDomainName();
    PrintUserName();
    PrintFullUserName();

    // Load InfoDLL explicitly
    HMODULE hInfo = LoadLibraryA("InfoDLL.dll");
    if (hInfo) {
        std::cout << "\nSystem Paths:\n";
        std::cout << "-----------------\n";
        auto printPaths = (PRINTSYSTEMPATHS)GetProcAddress(hInfo, "PrintSystemPaths");
        if (printPaths) {
            printPaths();
        }

        std::cout << "\nOperating System Information:\n";
        std::cout << "-----------------\n";
        auto printOSVersion = (PRINTOSVERSION)GetProcAddress(hInfo, "PrintOSVersion");
        if (printOSVersion) {
            printOSVersion();
        }

        std::cout << "\nDate and Time Information:\n";
        std::cout << "-----------------\n";
        auto printDateTime = (PRINTDATETIME)GetProcAddress(hInfo, "PrintDateTime");
        if (printDateTime) {
            printDateTime();
        }

        FreeLibrary(hInfo);
    }

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
