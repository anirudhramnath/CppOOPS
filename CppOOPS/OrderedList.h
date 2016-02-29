/**
 * Project Untitled
 */


#ifndef _ORDEREDLIST_H
#define _ORDEREDLIST_H

#include "UnorderedList.h"


class OrderedList: public UnorderedList {
public: 
    
    /**
     * @param data
     */
    void insert(int data);
};

#endif //_ORDEREDLIST_H