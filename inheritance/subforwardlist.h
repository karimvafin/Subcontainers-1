//
// Created by Карим Вафин on 20.02.2021.
//

#ifndef INHERITANCE_SUBFORWARDLIST_H
#define INHERITANCE_SUBFORWARDLIST_H

#include <iostream>
#include "subcontainer.h"
using namespace std;

class listt: public subcontainer
{
private:
    struct uzzel
    {
        int data; uzzel* next;
        uzzel(int d)
        {
            data = d;
            next = NULL;
        }
    };

    uzzel* start;

    void clear_work(uzzel** sfl);


public:
    listt ();

    bool push_back(int d); //add element (d) to the end of the list

    bool pop_back(); //erase element from the end of the list + return it's data

    bool push_forward(int d); //add element (d) to the beginning of the list

    int pop_forward(); //erase element from the beginning of the list + return it's data

    bool push_where(unsigned int where, int d); //add element (d) to (where)th position of the list

    bool erase_where(unsigned int where); //erase element from (where)th position of the list

    unsigned int size(); //check size of list

    void clear(); //delete all elements (interface function, work function is private)

    void print();

    ~listt();

    void mini_profiler();// mini-test to check working
};

#endif //INHERITANCE_SUBFORWARDLIST_H
