/**
 * Project Untitled
 */


#include "UnorderedList.h"

/**
 * UnorderedList implementation
 */


/**
 * @param data
 * @return void
 */
void UnorderedList::insert(int data) {
    AbstractCollection::insert(data, 0);
}
void UnorderedList::insert(int data, int index) {
}

/**
 * @param index
 * @return void
 */
void UnorderedList::remove(int index) {
    AbstractCollection::remove(index);
}

/**
 * @param index
 * @return int
 */
int UnorderedList::get(int index) {
    AbstractCollection::get(index);
}

/**
 * @return int
 */
int UnorderedList::size() {
    return AbstractCollection::size();
}

/**
 * @return String
 */
char * UnorderedList::toString() {
    return AbstractCollection::toString();
}