#include "../header/SIMS.h"
#include<string>
#include<iostream>

SIMS::SIMS(int n) :listSize(n)
{
    headNode = new stuNode;
}

SIMS::~SIMS()
{
    for (int i = 0; i < listSize; i++) {
        stuNode* ptr = headNode->next;
        delete headNode;
        headNode = ptr;
    }
}

bool SIMS::empty() const
{
    return !listSize;
}

int SIMS::size()
{
    return listSize;
}

STU& SIMS::get(int theIndex) const
{
    stuNode* ptr = headNode;
    for (int i = 0; i <= theIndex; i++) {
        ptr = ptr->next;
    }
    return ptr->student;
}

STU& SIMS::operator[](int theIndex) const
{
    return get(theIndex);
}

int SIMS::indexOf(const STU& theStudent) const
{
    stuNode* ptr = headNode->next;
    for (int i = 0; i < listSize; i++) {
        if (ptr->student == theStudent) {
            return i;
        }
        ptr = ptr->next;
    }
    return -1;
}
void SIMS::insert(const STU& theStudent)
{
    insert(0, theStudent);
}
void SIMS::insert(int theIndex, const STU& theStudent)
{
    stuNode* ptr = headNode;
    for (int i = 0; i < theIndex; i++) {
        ptr = ptr->next;
    }
    stuNode* thePtr = new stuNode(theStudent, ptr, ptr->next);
    ptr->next = thePtr;
    if (thePtr->next != nullptr) {
        thePtr->next->prev = thePtr;
    }
    listSize++;
}

void SIMS::push_back(const STU& theStudent)
{
    insert(listSize, theStudent);
}

void SIMS::erase(int theIndex)
{
    stuNode* currentNode = headNode;
    //After the loop,'currentNode' points to the student whose index is 'theIndex'.
    for (int i = 0; i <= theIndex; i++) {
        currentNode = currentNode->next;
    }
    //Make previous node points to them next node (or to nullptr).
    currentNode->prev->next = currentNode->next;
    if (currentNode->next != nullptr) {
        currentNode->next->prev = currentNode->prev;
    }
    delete currentNode;
    listSize--;
}

std::ostream& operator<<(std::ostream& out, const SIMS& theSIMS)
{
    std::string str[3] = { "name: ","id: ","score: " };
    stuNode* ptr = theSIMS.headNode->next;
    for (int i = 0; i < theSIMS.listSize; i++) {
        out << str[0] << ptr->student.name << '\t'
            << str[1] << ptr->student.id << '\t'
            << str[2] << ptr->student.score << std::endl;
        ptr = ptr->next;
    }
    return out;
}