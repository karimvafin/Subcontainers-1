//
// Created by Карим Вафин on 20.02.2021.
//

#ifndef INHERITANCE_SUBVECTOR_H
#define INHERITANCE_SUBVECTOR_H

#include "subcontainer.h"

class subvector: public subcontainer
{
private:
    int* mas;
    unsigned int top;
    unsigned int capacity;

public:
    subvector();
    ~subvector();
    bool push_back(int d);
    bool pop_back();
    void clear();
    void print();
    unsigned int get_cap();
    unsigned int get_top();
    bool resize (unsigned int new_capacity);
    void shrink_to_fit();

};

#endif //INHERITANCE_SUBVECTOR_H