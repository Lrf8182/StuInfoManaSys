#include "../header/SIMS.h"
#include<iostream>
#include"../header/Welcome.h"
#include<stdlib.h>
#include<process.h>
#include "../header/ConsoleSetting.h"
#include <string>

SIMS stuInfo;

int main()
{
    while (welcome()) {
        system("cls");
    };
    colorfulOutput("i", 0, 7);
    colorfulOutput(" ", 1, 6);
    colorfulOutput("love", 3, 5);
    colorfulOutput(" ", 1, 6);
    colorfulOutput("lrf\n", 2, 4);

    setOutputColor(4);
    std::cout << "Program ended. Press ENTER to exit...\n";
    std::cin.get();
}