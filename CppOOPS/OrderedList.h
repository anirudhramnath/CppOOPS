/**
 * Project Untitled
 */


#ifndef _ORDEREDLIST_H
#define _ORDEREDLIST_H

#include "UnorderedList.h"


class OrderedList: public AbstractCollection {
private:
    int getPosition(int data);
public: 
    
    /**
     * @param data
     */
    void insert(int data);
    void insert(int data, int index);
    void remove(int index);
    
    /**
     * @param index
     */
    int get(int index);
    
    int size();
    
    char * toString();

};

#endif //_ORDEREDLIST_H