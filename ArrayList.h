//
// Created by riosd on 9/15/2026.
//

#pragma once

#include <iostream>
using namespace std; 

template <typename T>
class ArrayList {
public:
    ArrayList():size(0) { // constructor

    }
    void add(T item) {
        if (size >= CAPACITY) {
            cout << "Array is full" << endl;
            return; // early return
        }
        for (int i = size; i > 0; i--) { // moves stuff over
            data[i] = data[i - 1];
        }
        data[0]=item; // actually adds to front
        size++;
    }
    void addBack(T item) {
        if (size >= CAPACITY) {
            cout << "Array is full" << endl;
            return;
        }
        data[size] = item;
        size++;
    }
    void deleteBack() {
        if (size == 0) {
            cout << "Array is empty" << endl;
            return;
        }
        size--;

    }
    void deleteFront() {
        if (size == 0) {
            cout << "Array is empty" << endl;
            return;
        }
        for (int i = 0; i < size-1; i++) { //less than dat-1 because we are moving over to left
            data[i]=data[i+1]; //note this doesnt actually delete data, just overwrites, and thats FINE
        } // also, there are methods to actually delete the thing, but that may cost space complexity
        size--;
    }
    bool search(T item) {
        if (size == 0) {
            cout << "Array is empty" << endl;
            return false;
        }
        for (int i = 0; i < size; i++) {
            if (data[i] == item)
                return true;
        }
        return false;
    }
    void printArray() {
        for (int i = 0; i < size; i++) {
            cout << data[i] << ",";
        }
        cout << endl;
    }
private:
    static const int CAPACITY = 20;
    T data[CAPACITY];
    int size;

};