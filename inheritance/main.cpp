#include <iostream>
#include "subvector.h"
#include "subcontainer.h"
#include "subforwardlist.h"
using namespace std;

int main()
{
    subvector s;
    s.push_back(3);
    s.print();
    listt a;
    a.mini_profiler();
    a.push_back(1);
    a.push_back(2);
    a.print();
    return 0;
}