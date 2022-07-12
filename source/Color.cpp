#include <windows.h>
#include <iostream>
#include<ctime>
#include<string>



void COLOR_PRINT(const char* s, int front_color, int back_color)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY | back_color * 16 | FOREGROUND_INTENSITY | front_color);
    std::cout << s;
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);

}

void COLOR_PRINT(std::string str, int front_color, int back_color)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY | back_color * 16 | FOREGROUND_INTENSITY | front_color);
    std::cout << str;
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);

}




