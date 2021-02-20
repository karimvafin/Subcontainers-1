//
// Created by Карим Вафин on 20.02.2021.
//

#ifndef INHERITANCE_SUBCONTAINER_H
#define INHERITANCE_SUBCONTAINER_H

class subcontainer
{
public:
    virtual ~subcontainer() = default;
    virtual bool push_back(int d) = 0;
    virtual bool pop_back() = 0;
    virtual void clear() = 0;
    virtual void print() = 0;
};


#endif //INHERITANCE_SUBCONTAINER_H
