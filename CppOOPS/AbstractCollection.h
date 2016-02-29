/**
 * Project Untitled
 */
#include "Node.h"

#ifndef _ABSTRACTCOLLECTION_H
#define _ABSTRACTCOLLECTION_H

class AbstractCollection {
    Node* head;
    Node* tail;
    
    
    
    
    public:
    /**
     * @param data
     * @param index
     */

    int size();

    char * toString();
    
    void add(int data, int index);
    
    /**
     * @param data
     */
    void addFirst(int data);
    
    /**
     * @param data
     */
    void addLast(int data);
    
    /**
     * @param index
     */
    int get(int index);
    
    int getFirst();
    
    int getLast();
    
    /**
     * @param index
     */
    void remove(int index);
    
    void removeFirst();
    
    void removeLast();
    
    bool isEmpty();
};
class IndexOutOfBound {
};

#endif //_ABSTRACTCOLLECTION_H