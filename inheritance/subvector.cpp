#include <iostream>
#include "subvector.h"
using namespace std;

subvector::subvector()
{
    this -> mas = NULL;
    this ->top = 0;
    this ->capacity = 0;
}

unsigned int subvector::get_cap()
{
    return this ->capacity;
}

unsigned int subvector::get_top()
{
    return this ->top;
}

bool subvector::push_back(int d)
{
    if (this ->top + 1 > this ->capacity)
    {
        int* p = new int[this ->capacity + 1];
        for (int i = 0; i < this ->capacity; i++)
        {
            *(p + i) = *(this -> mas + i);
        }
        if (this ->capacity > 0) delete[] this ->mas;
        this ->capacity++;
        this ->mas = p;
        *(this ->mas + this ->top) = d;
        this ->top++;
    }
    else
    {
        *(this ->mas + this ->top) = d;
        this ->top++;
    }
    return true;
}

void subvector::print ()
{
    if (this ->top > 0)
    {
        for (int i = 0; i< this -> top; i++)
            cout << this -> mas [i]<<" ";
        cout<<endl;
    }
    else cout << "empty subvector";
}

bool subvector::pop_back()
{
    if (this ->top > 0)
    {
        this ->top--;
        int e = *(this ->mas + this ->top);
        return e;
    }
    else
    {
        return 0;
    }
}

bool subvector::resize(unsigned int new_capacity)
{
    if (new_capacity > 0) {
        int* p = new int[new_capacity];
        for (int i = 0; i < this ->top; i++)
        {
            *(p + i) = *(this ->mas + i);
        }
        if (this ->capacity > 0) delete[] this ->mas;
        this ->capacity = new_capacity;
        this ->mas = p;
        if (new_capacity < this ->top) this ->top = new_capacity;
        return true;
    }
    else
    {
        if (this ->capacity > 0) delete[] this ->mas;
        this -> mas = NULL;
        this ->top = 0;
        this ->capacity = 0;
        return true;
    }
}

void subvector::shrink_to_fit()
{
    if (this ->capacity > this ->top)
    {
        if (this ->top > 0)
        {
            int* p = new int[this ->top];
            for (int i = 0; i < this ->top; i++)
            {
                *(p + i) = *(this ->mas + i);
            }
            delete[] this ->mas;
            this ->capacity = this ->top;
            this ->mas = p;
        }
        else
        {
            delete[] this ->mas;
            this -> mas = NULL;
            this ->top = 0;
            this ->capacity = 0;
        }
    }
}
void subvector::clear()
{
    this ->top = 0;
}

subvector::~subvector()
{
    delete [] this->mas;
}