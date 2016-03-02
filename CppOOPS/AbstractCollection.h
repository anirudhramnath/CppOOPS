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
    virtual int get(int index);
    virtual int get();
    virtual void remove(int index);
    virtual void remove();
    bool isEmpty();
};
class IndexOutOfBound {
};

#endif //_ABSTRACTCOLLECTION_H