/**
 * Project Untitled
 */
#include "Node.h"
#include <string>

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

    virtual std::string toString();
    
    void insert(int data, int index);
    virtual void insert(int data);
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
    virtual int get();
    
    int getFirst();
    
    int getLast();
    
    /**
     * @param index
     */
    virtual void remove(int index);
    virtual void remove();
    
    void removeFirst();
    
    void removeLast();
    
    virtual bool isEmpty();
};
class IndexOutOfBound {
};

#endif //_ABSTRACTCOLLECTION_H