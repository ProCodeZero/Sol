#include <iostream>
#include <Windows.h>
#include <SysInfoLib.h>

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
