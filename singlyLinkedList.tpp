//
// Created by Enkang Yuan on 11/2/23.
//

#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

template<class T>
class SinglyLinkedList {
private:
    template<class Type>
    struct node {
        T data;
        node<T> *next;
    };

    node<T> *headPtr;

public:
    SinglyLinkedList<T>() {
        headPtr = nullptr;
    }

    node<T> * getHead() {
        return headPtr;
    }

    /*
     * Function purpose:    sets the pointer of current head node to next value in linked-list 
     *                      and points new value to the previous head
     * Parameters:          integer value of new head node
     */
    void insertFirst(T value) {
        auto *temp = (node<T> *) malloc(sizeof(node<T>));
        temp -> data = value;
        temp -> next = headPtr;
        headPtr = temp;
    }

    void insertLast(T value) {
        auto *temp = (node<T> *) malloc(sizeof(node<T>));
        temp -> data = value;
        temp -> next = nullptr;

        if (headPtr == nullptr) {
            // If the list is empty, make the new node the head.
            headPtr = temp;
        } else {
            // Traverse the list to find the last node.
            node<T> *current = headPtr;
            while (current -> next != nullptr) {
                current = current -> next;
            }

            // Append the new node to the end of the list.
            current -> next = temp;
        }
    }


    /*
     * Function purpose:    traverses through linked-list and prints data values of nodes
     * Parameters:          pointer of current node
     */
    void traverse(node<T> *temp) {
        if (headPtr == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        temp = headPtr;
        int dataIndex = 0;

        while (temp != nullptr) {
            dataIndex++;
            cout << "Data value of node " << dataIndex << " is: " << temp -> data << endl;
            temp = temp -> next;
        }
    }

    /*
     * Function purpose:    prints data values of nodes
     * Parameters:          none
     */
    template<class Type> void displayList() {
        node<T> *currentPtr = headPtr;
        while (currentPtr != nullptr) {
            cout << currentPtr -> data << endl;
            currentPtr = currentPtr -> next;
        }

        cout << endl;
    }

    /*
     * Function purpose:    prints data values recursively
     * Parameters:          node
     */
    void displayRecursively(node<T> *temp) {
        if (temp == nullptr) return;    // exit condition
        cout << temp -> data << endl;
        displayRecursively(temp -> next);
    }
};
