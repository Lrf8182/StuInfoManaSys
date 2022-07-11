#include<iostream>
#include"../header/SIMS.h"
#include"../header/Welcome.h"
#include"../header/Color.h"
#include<windows.h>
#include"../header/ConsoleSetting.h"
#include <fstream>

extern SIMS stuInfo;

/**
 * @brief Program starting interface.
 * @return -0 Quit this system.
 *         -1 Print all students.
 *         -2 Add astudent.
 *         -3 Delete a student.
 *         -4 Search for a student.
 *         -5 Print specified students by score ranking.
*/
int welcome()
{
    colorfulOutput("This is a student information management system.\n",2,3);
    //Sleep(1000);
    colorprint("Enter 0 to quit this system.\n");
    //Sleep(1000);
    colorprint("Enter 1 to print all students.\n");
    //Sleep(1000);
    colorprint("Enter 2 to add a student.\n");
    //Sleep(1000);
    colorprint("Enter 3 to delete a student.\n");
    //Sleep(1000);
    colorprint("Enter 4 to search for a student.\n");
    //Sleep(1000);
    colorprint("Enter 5 to print specified students by score ranking.\n");

    int op;
    std::cin >> op;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    if (!op) return 0;
    option(op);
    return 1;
}

/**
 * @brief
 * @param op -0 Quit this system.
 *           -1 Print all students.
 *           -2 Add astudent.
 *           -3 Delete a student.
 *           -4 Search for a student.
 *           -5 Print specified students by score ranking.
*/
void option(int op)
{
    switch (op) {
    case 1:
    {
        std::cout << stuInfo << std::endl;
        colorprint("Press enter to continue.\n");
        std::cin.get();
        break;
    }
    case 2:
    {
        std::string name; int ID; int score;
        colorprint("Name: "); std::cin >> name;
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
        colorprint("ID: "); std::cin >> ID;
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
        colorprint("Score: "); std::cin >> score;
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
        STU student(name, ID, score);
        stuInfo.push_back(student);
        colorprint("Insertion succeed"); std::cout << std::endl;
        colorprint("Press enter to continue.\n");
        std::cin.get();
        break;
    }
    case 3:
    {
        colorprint("Please enter the ID of the student to be deleted.\n");
        int theID;
        std::cin >> theID;
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
        int theIndex = stuInfo.searchID(theID);
        if (theIndex == -1) {
            std::cout << "Failed to find this student." << std::endl;
            colorprint("Press enter to continue.\n");
            std::cin.get();
        } else {
            stuInfo.erase(theIndex);
            colorprint("Completely deleted!");
            colorprint("Press enter to continue.\n");
            std::cin.get();
        }
        break;
    }
    case 4:
    {
        colorprint("Please enter the ID of the student to be found.");
        std::cout << std::endl;
        int theID;
        std::cin >> theID;
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
        int theIndex = stuInfo.searchID(theID);
        if (theIndex == -1) {
            std::cout << "Failed to find this student." << std::endl;
            colorprint("Press enter to continue.\n");
            std::cin.get();
        } else {
            std::cout << "name: " << stuInfo[theIndex].name << '\t'
                << "id: " << stuInfo[theIndex].id << '\t'
                << "score: " << stuInfo[theIndex].score << std::endl;
        }
        colorprint("Press enter to continue.\n");
        std::cin.get();
        break;
    }
    case 5:
    {
        stuInfo.scoreranking();
        break;
    }
    case 6:
    {
        std::string fileName;
        std::ofstream outputFile;
        outputFile << "Please enter output file name.";
        getline(std::cin, fileName);
        outputFile.open(fileName);
        size_t size = stuInfo.size();
        for (size_t i = 0; i < size; i++) {
            outputFile << "name: " << stuInfo[i].name
                << "\t" << "id: " << stuInfo[i].id << "\t"
                << "score: " << stuInfo[i].score << "\n";
        }
        break;
    }
    case 7:
    {
        std::ifstream inputFile;
        inputFile.open("aaa.txt");
        std::string str;
        getline(inputFile, str);
        std::cout << str;
        inputFile.close();
        std::cin.get();
    }
    };
}