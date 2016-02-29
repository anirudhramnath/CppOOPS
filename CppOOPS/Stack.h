/**
 * Project Untitled
 */


#ifndef _STACK_H
#define _STACK_H

#include "AbstractCollection.h"


class Stack: public AbstractCollection {
public: 
    
    /**
     * @param data
     */
    void insert(int data);
    
    void remove();
    
    int get();
    
    int size();
    
    char * toString();
};

#endif //_STACK_H