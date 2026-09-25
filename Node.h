//
// Created by riosd on 9/17/2026.

# pragma once
#include <iostream>
#include <ostream>

template<typename T>
class Node {
public:
    T *value;
    Node<T>* next;

    Node(T *value) {
        this->value = value; //remember this keyword because these are two different 'values'
        next=nullptr; // pointer to next in line is null upon construction

    }
    void printValue() {
        value->print(); // outsource the printing work b/c we dont know whats inside
    } /* we don't print a dereferenced value because we dont want other files accessing
       whats private( in this case its public but still good practice), this is abstaction
       and encapsulation. */

};
