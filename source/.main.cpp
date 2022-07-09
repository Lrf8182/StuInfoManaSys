#include "../header/SIMS.h"
#include<iostream>
#include"../header/Welcome.h"
#include<stdlib.h>
#include<process.h>
#include "../header/ConsoleSetting.h"
#include <string>
#include <fstream>

SIMS stuInfo;

int main()
{
    std::ofstream myoutput;
    myoutput.open("aaa.txt");

    while (welcome()) {
        system("cls");
    };
    colorfulOutput("i", 0, 7);
    colorfulOutput(" ", 1, 6);
    colorfulOutput("love", 3, 5);
    colorfulOutput(" ", 1, 6);
    colorfulOutput("lrf\n", 2, 4);

    myoutput << "lrf love me.\n" << std::endl << "!!!";

    setOutputColor(4);
    std::cout << "Program ended. Press ENTER to exit...\n";
    std::cin.get();

    myoutput.close();

    std::ifstream myinput;
    myinput.open("aaa.txt");

    while (!myinput.eof()) {
        std::string str;
        getline(myinput, str);
        std::cout << str;
    }

    while (!myinput.eof()) {
        char ch;
        ch = myinput.get();
        std::cout << ch;
    }

    myinput.close();

    std::cin.get();
}