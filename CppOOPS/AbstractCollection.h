/**
 * Project Untitled
 */
#include "Node.h"

#ifndef _ABSTRACTCOLLECTION_H
#define _ABSTRACTCOLLECTION_H

class AbstractCollection {
    Node* head ;
    Node* tail ;
    
    
    
    
    public:
    AbstractCollection();
    /**
     * @param data
     * @param index
     */

    int size();

    virtual char * toString();
    
    virtual void insert(int data, int index);
    
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
    virtual int get(int index);
    
    int getFirst();
    
    int getLast();
    
    /**
     * @param index
     */
    virtual void remove(int index);
    
    void removeFirst();
    
    void removeLast();
    
    virtual bool isEmpty();
};
class IndexOutOfBound {
};

#endif //_ABSTRACTCOLLECTION_H