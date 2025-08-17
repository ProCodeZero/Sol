// SysInfoLib.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include <Windows.h>
#include <iostream>
#include <string>

int Sum(int a, int b)
{
	return a + b;
}

void PrintComputerName()
{
    char buffer[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = sizeof(buffer);
    if (GetComputerNameA(buffer, &size))
    {
        std::cout << "Computer Name: " << buffer << std::endl;
    }
}

void PrintDomainName()
{
    char buffer[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = sizeof(buffer);
    if (GetComputerNameExA(ComputerNameDnsDomain, buffer, &size))
    {
        std::cout << "Domain Name: " << buffer << std::endl;
    }
}

void PrintUserName()
{
    char buffer[UNLEN + 1];
    DWORD size = sizeof(buffer);
    if (GetUserNameA(buffer, &size))
    {
        std::cout << "User Name: " << buffer << std::endl;
    }
}

void PrintFullUserName()
{
    char buffer[UNLEN + 1];
    DWORD size = sizeof(buffer);
    if (GetUserNameA(buffer, &size))
    {
        std::cout << "Full User Name: " << buffer << std::endl;
    }
}