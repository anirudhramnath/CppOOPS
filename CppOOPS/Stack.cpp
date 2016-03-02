
#include "Stack.h"
#include <string>

/**
 * Stack implementation
 */

Stack::Stack()
{
    AbstractCollection::AbstractCollection();
}
/**
 * @param data
 * @return void
 */
void Stack::insert(int data) {
    AbstractCollection::insert(data, 0);
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
std::string Stack::toString() {
    return AbstractCollection::toString();
}