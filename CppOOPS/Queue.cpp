/**
 * Project Untitled
 */


#include "Queue.h"

/**
 * Queue implementation
 */


/**
 * @param data
 * @return void
 */
void Queue::insert(int data) {
    AbstractCollection::insert(data, size());
}

/**
 * @return void
 */
void Queue::remove() {
    AbstractCollection::remove(0);
}

/**
 * @return int
 */
int Queue::get() {
    return AbstractCollection::get(0);
}

/**
 * @return int
 */
int Queue::size() {
    return AbstractCollection::size();
}

/**
 * @return String
 */
char * Queue::toString() {
    return AbstractCollection::toString();
}