#pragma once
#include "StuNode.h"

class SIMS
{
    
public:
    friend std::ostream& operator<<(std::ostream& out, const SIMS& theSIMS);
    //Constructor
    //@
   
    SIMS(int n = 0);
    //@
    //Copy constructor
    SIMS(const SIMS& theSIMS) : headNode(theSIMS.headNode), listSize(theSIMS.listSize) {}
    //Distructor
    ~SIMS();
public:
    int size();
    bool empty() const;
    STU& get(int theIndex) const;
    STU& operator[](int theIndex) const;
    int indexOf(const STU& theStudent) const;
    void insert(const STU& theStudent);
    void insert(int theIndex, const STU& theStudent);
    void push_back(const STU& theStudent);
    void erase();
    void erase(const int theIndex);
    int search(int ID);
    
private:
    stuNode* headNode;
    int listSize;
};

