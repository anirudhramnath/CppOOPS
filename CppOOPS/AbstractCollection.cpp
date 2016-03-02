/**
 * Project Untitled
 */


#include "AbstractCollection.h"
#include <string>
#include "stdlib.h"
#include  <iostream>

 using namespace std;

/**
 * AbstractCollection implementation
 */


/**
 * @return int
 */
AbstractCollection::AbstractCollection(){
    head = 0;
    tail = 0;
}
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
std::string AbstractCollection::toString() {
    int i =0;
    std::string strrep;
    Node * current;
    for(current = head; current; current = current->getNext()){
        strrep += std::to_string(current->getData()) + ", ";
        i++;
    }  
    return strrep; 
}

/**
 * @param data
 * @param index
 * @return void
 */
void AbstractCollection::insert(int data, int index) {
    int i = 0;
    Node * new_node = new Node(data);
    Node * current;

    if(index > size())
        throw IndexOutOfBound();


    if(index == 0){
        if(!head){
            head = new_node;
        }else{
            new_node->setNext(head);
            head = new_node;
        }
    }else if(index<size()){
        for(current = head; current; current = current->getNext()){
            if(i == index-1){
                new_node->setNext(current->getNext());
                current->setNext(new_node);
                break;
            }
            i++;
        }
    }else{
        for(current = head; current; current = current->getNext()){
            if(i == index-1){
                break;
            }
            i++;
        } 
        current->setNext(new_node);   
    }
}

void AbstractCollection::insert(int data) {
    // implementation will be done in child classes
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
    if(index > size()-1 || index < 0)
        throw IndexOutOfBound();

    for(current = head; current; current = current->getNext()){
        if(index == i){
            cout<<"return from get:"<<current->getData()<<endl;
           return current->getData();
        }
        i++;
    }
}

int AbstractCollection::get() {
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
    Node * current, *temp;

    if(index > size()-1)
        throw IndexOutOfBound();


    if(index == 0){
        temp = head;
        head = head->getNext();
        delete temp;
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

void AbstractCollection::remove() {
    // implementation in child class
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
    return !head;
}