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


int SIMS::size()
{
    return listSize;
}



bool SIMS::empty() const
{
    return !listSize;
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
    stuNode* ptr = headNode;
    for (int i = 0; i < listSize; i++) {
        if ((theStudent.id < ptr->next->student.id)) {
            break;
        }
        ptr = ptr->next;
    }
    stuNode* thePtr = new stuNode(theStudent, ptr, ptr->next);
    ptr->next = thePtr;
    if (thePtr->next != nullptr) {
        thePtr->next->prev = thePtr;
    }
    listSize++;
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

int SIMS::searchID(int ID)
{
    stuNode* currentNode = headNode->next;
    for (int theIndex = 0; theIndex < listSize; theIndex++) {
        if (currentNode->student.id == ID) {
            return theIndex;
        }
        currentNode = currentNode->next;
    }
    return -1;
}

void SIMS::scoreranking()
{
    stuNode* ptr = headNode->next;
    for (int i = 0; i < listSize -1; i++) {
        stuNode* thePtr = ptr;
        if (thePtr->student.score > thePtr->next->student.score) {
            int t = indexOf(thePtr->student);
            insert(t+2,thePtr->student);          
            erase(t);
        } 
    }
    ptr = ptr->next;
}

int SIMS::searchScore(int Score)
{
    stuNode* currentNode = headNode->next;
    for (int theIndex = 0; theIndex < listSize; theIndex++) {
        if (currentNode->student.id == Score) {
            return theIndex;
        }
        currentNode = currentNode->next;
    }
    return -1;
}

void SIMS::show(int scoreMin, int scoreMax)
{
    for (int i = 0; i < listSize; i++) {
        if (scoreMin <= get(i).score <= scoreMax) {
            std::cout << "name: " << get(i).name << '\t'
                << "id: " << get(i).id << '\t'
                << "score: " << get(i).score << std::endl;
            std::cin.get();
        }
    }
    std::cin.get();
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