#include <iostream>
#include <SysInfoLib.h>

int main()
{
    std::cout << "System Information:\n";
    std::cout << "-----------------\n";
    
    PrintComputerName();
    PrintDomainName();
    PrintUserName();
    PrintFullUserName();
    
    return 0;
}
