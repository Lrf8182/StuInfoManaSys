#pragma once
#include <string>
typedef std::string stdstr;

struct STU
{
    stdstr name;
    int id;
    int score;
    //Constructor
    STU(stdstr n = "\0", int i = 0, int s = 0) : name(n), id(i), score(s) {}
    //Copy constructor
    STU(const STU& theStudent) :name(theStudent.name), id(theStudent.id), score(theStudent.score) {}
    bool operator==(const STU& theStudent)
    {
        return ((name == theStudent.name) && (id = theStudent.id) && (score == theStudent.score));
    }

};

#ifndef DEFAULTSTUDENT
#define DEFAULTSTUDENT
const STU defaultStudent;
#endif // !DEFAULTSTUDENT


struct stuNode
{
    STU student;
    stuNode* next;
    stuNode* prev;
    
    /**
     * @brief Constructor.
     * @param s Student.
     * @param p Previous node.
     * @param n Next node.
    */
    stuNode(STU s=defaultStudent, stuNode* p= nullptr, stuNode* n = nullptr) :student(s), next(n), prev(p) {}
   
};
