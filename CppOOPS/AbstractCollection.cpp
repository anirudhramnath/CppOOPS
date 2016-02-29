/**
 * Project Untitled
 */


#include "AbstractCollection.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

/**
 * AbstractCollection implementation
 */


/**
 * @return int
 */
int AbstractCollection::size() {
    int i = 0; 
    Node * current;
    for(current = head; current; current = current->getNext()){
        i++;
    }
    return i;
}

/**
 * @return String
 */
char * AbstractCollection::toString() {
    int i =0;
    char * strrep = (char *)malloc(100); 
    Node * current;
    for(current = head; current; current = current->getNext()){
        char temp[3] = "";
        sprintf(temp, "%d", i);
        strcat(strrep, temp);
        strcat(strrep, ", ");
        i++;
    }  
    return strrep; 
}

/**
 * @param data
 * @param index
 * @return void
 */
void AbstractCollection::add(int data, int index) {
    int i = 0;
    Node new_node = Node(data);
    Node * current;

    if(index > size())
        throw IndexOutOfBound();


    if(index == 0){
        if(current == NULL){
            head = &new_node;
        }else{
            new_node.setNext(head);
            head = &new_node;
        }
    }else{
        for(current = head; current; current = current->getNext()){
            if(index == i){
                new_node.setNext(current->getNext());
                current->setNext(&new_node);
                break;
            }
            i++;
        }
    }
}

/**
 * @param data
 * @return void
 */
void AbstractCollection::addFirst(int data) {
    return;
}

/**
 * @param data
 * @return void
 */
void AbstractCollection::addLast(int data) {
    return;
}

/**
 * @param index
 * @return int
 */
int AbstractCollection::get(int index) {
    int i = 0;
    Node * current;
    if(index > size()-1)
        throw IndexOutOfBound();

    for(current = head; current; current = current->getNext()){
        if(index == i){
           return current->getData();
        }
        i++;
    }
    
}

/**
 * @return int
 */
int AbstractCollection::getFirst() {
    return 0;
}

/**
 * @return int
 */
int AbstractCollection::getLast() {
    return 0;
}

/**
 * @param index
 * @return void
 */
void AbstractCollection::remove(int index) {
    int i = 0;
    Node * current;

    if(index > size()-1)
        throw IndexOutOfBound();


    if(index == 0){
        head = head->getNext();
    }else{
        for(current = head; current; current = current->getNext()){
            if(i == index-1){
                current->setNext(current->getNext()->getNext());
                break;
            }
            i++;
        }
    }

}

/**
 * @return void
 */
void AbstractCollection::removeFirst() {
    return;
}

/**
 * @return void
 */
void AbstractCollection::removeLast() {
    return;
}

/**
 * @return bool
 */
bool AbstractCollection::isEmpty() {
    return head == NULL;
}