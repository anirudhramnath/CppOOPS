/**
 * Project Untitled
 */


#include "Node.h"

/**
 * Node implementation
 */


/**
 * @param data
 */
Node::Node(int data) {
    this->data = data;
    this->next = 0;
}

/**
 * @param data
 * @param next
 */
Node::Node(int data, Node* next) {
    this->data = data;
    this->next = next;
}

/**
 * @return int
 */
int Node::getData() {
    return this->data;
}

/**
 * @return Node*
 */
Node* Node::getNext() {
    return this->next;
}

/**
 * @param next
 * @return void
 */
void Node::setNext(Node* next) {
    this->next = next;
}