//
// Created by riosd on 9/17/2026.
//

# pragma once
#include "Node.h"

template <typename T>
class LinkedList {
    public:
    Node<T> *head;
    Node<T> *tail;
    int size;

    LinkedList(T *value) { // got to have at least one value to throw upon construction
        Node<T> *temp = new Node<T>(value); // creates temporary pointer
        head = temp; // we are forcing the list to have at least one time upon creation.
        tail=temp;
        size = 1;
    }
    LinkedList() { //overloading ... this is a empty constructor
        head=nullptr;
        size=0;
    }

    void print() { // assuming we have nodes, the last node always points to null
        Node<T> *temp1 = head; // avoids moving head, NEVER move head pointer
        while (temp1!=nullptr) { // until we reach the last node ...
            temp1->print();
            temp1 = temp1->next;
        }
    }

    void append(T *value) { //adds to end of list
        Node<T> *newnode = new Node<T>(value);
        if (head==nullptr) {
            head = newnode;
            size++;     // dont forget this
            return;
        }
        //cut here for tail method
        Node<T> *temp = head;
        while (temp->next != nullptr) { /* we use-> next to stop one before
            Dont stop at a nullptr because then we get lost and have to restart
            loop finishes iterating and temp points to last node in list*/
            temp = temp->next;
        }
        // or just tail->next = newnode;
        //          tail=tail->next; or tail=newnode
        temp->next = newnode;
    }
};
