/**
 * Project Untitled
 */


#ifndef _ABSTRACTCOLLECTION_H
#define _ABSTRACTCOLLECTION_H

class AbstractCollection {
protected: 
    Node* head;
    Node* tail;
    int size;
    
    int size();
    
    String toString();
    
    /**
     * @param data
     * @param index
     */
    void add(int data, int index);
    
    /**
     * @param data
     */
    void addFirst(int data);
    
    /**
     * @param data
     */
    void addLast(int data);
    
    /**
     * @param index
     */
    int get(int index);
    
    int getFirst();
    
    int getLast();
    
    /**
     * @param index
     */
    void remove(int index);
    
    void removeFirst();
    
    void removeLast();
    
    bool isEmpty();
};

#endif //_ABSTRACTCOLLECTION_H