#include<iostream>
#include"../header/SIMS.h"
#include"../header/Welcome.h"
#include"../header/Color.h"
#include<windows.h>


extern SIMS stuInfo;

/**
 * @brief Program starting interface.
 * @return -1 Print all students.
 *         -2 Add astudent.
 *         -3 Delete a student.
 *         -4 Search for a student.
*/
void welcome()
{
    colorprint("This is a student information management system.\n");
    Sleep(1000);
    colorprint("Enter 1 to print all students.\n");
    Sleep(1000);
    colorprint("Enter 2 to add a student.\n");
    Sleep(1000);
    colorprint("Enter 3 to delete a student.\n");
    Sleep(1000);
    colorprint("Enter 4 to search for a student.\n");

    int op;
    std::cin >> op;
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    option(op);
    
}

/**
 * @brief
 * @param op -1 Print all students.
 *           -2 Add astudent.
 *           -3 Delete a student.
 *           -4 Search for a student.
*/
void option(int op)
{
    switch (op) {
    case 1:
    {
        
        std::cout << stuInfo << std::endl;
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
        colorprint("Insert successfully"); std::cout << std::endl;
        break;
    }
    case 3:
    {
        colorprint("Please enter the ID of the student to be deleted.\n"); 
        int theID;
        std::cin >> theID;
        int theIndex = stuInfo.search(theID);
        stuInfo.erase(theIndex);
        colorprint("Completely deleted!");
        std::cout << std::endl;
        std::cin.get();
        break;
    }
    case 4:
    {
        colorprint("Please enter the ID of the student to be found."); 
        std::cout<<std::endl;
        int theID;
        std::cin >> theID;
        int theIndex = stuInfo.search(theID);
        if (theIndex == -1) {
            std::cout << "Failed to find this student." << std::endl;
        } else {
            std::cout << "name: " << stuInfo[theIndex].name << '\t'
                << "id: " << stuInfo[theIndex].id << '\t'
                << "score: " << stuInfo[theIndex].score << std::endl;
        }
        std::cin.get();
        break;
    }
    };
}