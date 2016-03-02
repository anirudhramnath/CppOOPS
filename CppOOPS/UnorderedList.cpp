
#include "UnorderedList.h"
#include <string>

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
    return AbstractCollection::get(index);
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
std::string UnorderedList::toString() {
    return AbstractCollection::toString();
}