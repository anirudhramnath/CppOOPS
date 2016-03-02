/**
 * Project Untitled
 */


#ifndef _QUEUE_H
#define _QUEUE_H

#include "AbstractCollection.h"
#include <string>


class Queue: public AbstractCollection {
public: 
    
    /**
     * @param data
     */
    void insert(int data);
    
    void remove();
    
    int get();
    
    int size();
    
    std::string toString();
};

#endif //_QUEUE_H