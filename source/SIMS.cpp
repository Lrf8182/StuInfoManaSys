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

size_t SIMS::size()
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

//void SIMS::swap(stuNode* nodeA, stuNode* nodeB)
//{
//    // stuNode* nodeA = headNode->next;
//    int t = indexOf(nodeA->student);
//    if (t + 2 < listSize) {
//        insert(t + 2, nodeA->student);
//    } else {
//        insert(listSize, nodeA->student);
//    }
//    erase(t);
//}

void SIMS::swap(stuNode* left, stuNode* right)
{
    stuNode* temp;
    if (right->next == NULL) {
        if (left->next == right) {
            right->next = left;
            right->prev = left->prev;
            left->next = nullptr;
            left->prev->next = right;
            left->prev = right;
        } else {
            right->prev->next = left;
            right->next = left;
            temp = right->prev;
            right->prev = left->prev;
            left->prev->next = right;
            left->next->prev = right;
            left->next = nullptr;
            left->prev = temp;
        }
    } else {
        if (left->next == right) {
            right->next->prev = left;
            right->prev = left->prev;
            temp = right->next;
            right->next = left;
            left->prev = right;
            left->next = temp;
        } else {
            right->next->prev = left;
            right->prev->next = left;
            temp = right->next;
            right->next = left->next;
            left->next = temp;
            temp = right->prev;
            right->prev = left->prev;
            left->prev = temp;
            left->next->prev = right;
            left->prev->next = right;
        }
    }
}

void SIMS::bubble(stuNode* nodeA, int n)
{
    stuNode* nodeC;
    for (int i = 0; i < n - 1; i++) {
        nodeC = nodeA->next->next;
        if (nodeA->student.score > nodeA->next->student.score) {
            swap(nodeA, nodeA->next);
        }
        if (nodeC != nullptr) {
            nodeA = nodeC->prev;
        } else {
            break;
        }
    }
}

//void SIMS::scoreranking()
//{
//    stuNode* theNode = headNode->next;
//    stuNode* nodeC;
//    for (int i = 0; i < listSize - 1; i++) {
//        nodeC = theNode->next->next;
//        bubble(theNode, listSize - i);
//        if (nodeC != nullptr) {
//            theNode = nodeC->prev;
//        } else {
//            break;
//        }
//    }
//}

void SIMS::scoreranking()
{
    int i, j;
    for (i = 0; i < listSize - 1; i++) {
        stuNode* left = get(0);
        for (j = 0; j < listSize - 1- i; j++) {
            if (left->student.score > left->next->student.score) {
                swap(left, left->next);
            }
            
        }
    }
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