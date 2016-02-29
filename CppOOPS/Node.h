/**
 * Project Untitled
 */


#ifndef _NODE_H
#define _NODE_H

class Node {
public: 
    
    /**
     * @param data
     */
    Node(int data);
    
    /**
     * @param data
     * @param next
     */
    Node(int data, Node* next);
    
    int getData();
    
    Node* getNext();
    
    /**
     * @param next
     */
    void setNext(Node* next);
private: 
    int data;
    Node* next;
};

#endif //_NODE_H