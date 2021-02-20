#include <iostream>
#include "subforwardlist.h"
using namespace std;


//----------------------------------Start of method descriptions-------------------------//

void listt::clear_work(uzzel** sfl)
    {
        if (*sfl == NULL) return;
        clear_work(&((*sfl)->next));
        delete *sfl;
        *sfl = NULL;
        return;
    }

listt::listt ()
    {
        start = NULL;
    }

bool listt:: push_back(int d)
    {
        uzzel** sfl = &(this -> start);
        uzzel* tmp = new uzzel(d);
        while (*sfl != NULL)
        {
            sfl = &((*sfl)->next);
        }
        *sfl = tmp;
        return true;
    }

bool listt:: pop_back()
    {
        if (start == NULL) return false;

        uzzel** sfl = &(this -> start);
        while ((*sfl)->next != NULL)
        {
            sfl = &((*sfl)->next);
        }
        int e = (*sfl)->data;
        delete *sfl;
        *sfl = NULL;
        return true;
    }

bool listt::push_forward(int d)
    {
        uzzel** sfl = &(this -> start);
        uzzel* tmp = new uzzel(d);
        tmp->next = (*sfl);
        tmp->data = d;
        *sfl = tmp;
        return true;
    }

int listt::pop_forward()
    {
        if (start == NULL) return false;

        uzzel** sfl = &(this -> start);
        uzzel* tmp = (*sfl)->next;
        int e = (*sfl)->data;
        delete *sfl;
        *sfl = tmp;
        return e;
    }

bool listt::push_where(unsigned int where, int d)
    {
        uzzel** sfl = &(this -> start);
        uzzel* tmp = new uzzel(d);
        for (int i = 1; i < where; i++)
        {
            if (*sfl == NULL) return false;
            sfl = &((*sfl)->next);
        }
        tmp->next = (*sfl);
        (*sfl) = tmp;
        return true;
    }

bool listt::erase_where(unsigned int where)
    {
        uzzel** sfl = &(this -> start);
        for (int i = 1; i < where; i++)
        {
            if (*sfl == NULL) return false;
            sfl = &((*sfl)->next);
        }
        uzzel* tmp = (*sfl)->next;
        delete (*sfl);
        (*sfl) = tmp;
        return true;
    }

unsigned int listt::size()
    {
        uzzel* sfl = this -> start;
        unsigned int size = 0;
        while (sfl != NULL)
        {
            sfl = (sfl)->next;
            size++;
        }
        return size;
    }

void listt::clear()
    {
        uzzel** sfl = &(this -> start);
        this ->clear_work(sfl);
    }

void listt::print()
    {
        uzzel* tmp = start;
        if (!tmp) cout << "empty list";
        while (tmp != NULL)
        {
            cout << tmp->data << " ";
            tmp = (tmp)->next;
        }
        cout << endl<<endl;
        return;
    }

listt::~listt()
    {
        this -> clear();
    }


void listt::mini_profiler()
{
    cout << "//----------------------Push_back(10 elements)----------------------//"<< endl;
    for (int i = 0; i < 10; this -> push_back(3*i+2),i++) {this -> print();} //� ����� �����������, ������ ������ �� �����,  ������....
this -> print();

    cout << "//----------------------Pop_back(8 elements)----------------------//"<< endl;
    for (int i = 0; i < 8; this -> pop_back(),i++) {this -> print();}
this -> print();

    cout << "//----------------------Push_forward(8 elements)----------------------//"<< endl;
    for (int i = 0; i < 8; this -> push_forward(5*i + 7),i++) {this -> print();}
this -> print();

    cout << "//----------------------Pop_forward(1 elements)----------------------//"<< endl;
    this -> pop_forward();
this -> print();

    cout << "//----------------------Push 112 to 3rd place----------------------//"<< endl;
    this -> push_where(3,112);
this -> print();

    cout << "//----------------------Push 221 to 3rd place/Erase 112 from 4rd place----------------------//"<< endl;
    this -> push_where(3,221);
this -> print();
    this -> erase_where(4);
this -> print();

    cout << "//----------------------Check size----------------------//"<< endl;
    cout << this -> size()<<endl;

    cout << "//----------------------Clear list----------------------//"<< endl;
    this -> clear();
this -> print();

}


