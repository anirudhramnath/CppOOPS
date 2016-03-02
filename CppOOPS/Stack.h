
#ifndef _STACK_H
#define _STACK_H

#include "AbstractCollection.h"
#include <string>


class Stack: public AbstractCollection {
public:

    /**
     * @param data
     */
    Stack();

    void insert(int data);

    void remove();

    int get();

    int size();

    std::string toString();
};

#endif //_STACK_H