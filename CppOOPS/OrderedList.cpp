/**
 * Project Untitled
 */


#include "OrderedList.h"
#include "stdio.h"
#include <string>

/**
 * OrderedList implementation
 */


/**
 * @param data
 * @return void
 */
int OrderedList::getPosition(int data) {
    int i;
    AbstractCollection * current = 0;
    if(AbstractCollection::isEmpty()){
        return 0;
    }else{
        for(i = 0; i<AbstractCollection::size() && data>AbstractCollection::get(i);i++);
        return i;
    }
}

void OrderedList::insert(int data) {
    AbstractCollection::insert(data, getPosition(data));
}
void OrderedList::insert(int data, int index)
{
}

/**
 * @param index
 * @return void
 */
void OrderedList::remove(int index) {
    AbstractCollection::remove(index);
}

/**
 * @param index
 * @return int
 */
int OrderedList::get(int index) {
    return AbstractCollection::get(index);
}

/**
 * @return int
 */
int OrderedList::size() {
    return AbstractCollection::size();
}

/**
 * @return String
 */
std::string OrderedList::toString() {
    return AbstractCollection::toString();
}