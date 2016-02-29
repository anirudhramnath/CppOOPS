/**
 * Project Untitled
 */


#include "Stack.h"

/**
 * Stack implementation
 */


/**
 * @param data
 * @return void
 */
void Stack::insert(int data) {
    AbstractCollection::add(data, 0);
}

/**
 * @return void
 */
void Stack::remove() {
    AbstractCollection::remove(0);
}

/**
 * @return int
 */
int Stack::get() {
    return AbstractCollection::get(0);
}

/**
 * @return int
 */
int Stack::size() {
    return AbstractCollection::size();
}

/**
 * @return String
 */
char * Stack::toString() {
    return AbstractCollection::toString();
}