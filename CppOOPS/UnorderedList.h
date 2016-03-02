

#ifndef _UNORDEREDLIST_H
#define _UNORDEREDLIST_H

#include "AbstractCollection.h"
#include <string>


class UnorderedList: public AbstractCollection {
public:

    /**
     * @param data
     */
    void insert(int data);
    /**
     * @param index
     */
    void remove(int index);

    /**
     * @param index
     */
    int get(int index);

    int size();

    std::string toString();
};

#endif //_UNORDEREDLIST_H