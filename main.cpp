#include <iostream>
#include "singlyLinkedList.tpp"


using namespace std;

int main() {

    int m, n, x;
    string isForwardOrBackward;
    SinglyLinkedList <int> newSinglyLinkedList;

    cout << "How many values will the list contain? ";
    cin >> m;

    cout << "Should the list be built backwards (1) or forwards (2)? ";
    cin >> n;
    cout << endl;

    if (n == 1) {
        isForwardOrBackward = "backward";
    } else {
        isForwardOrBackward = "forward";
    }

    /*
     * cout << "Is the integer value meant to be added to the head or tail of the list?" << endl;
     * cout << "1. Head" << endl;
     * cout << "2. Tail" << endl;
     * cin >> userSelection;
     */

    for (int i = 0; i < m; i++) {
        cout << "Enter a value: ";
        cin >> x;

        if (n == 1) {
            newSinglyLinkedList.insertFirst(x);
        } else {
            newSinglyLinkedList.insertLast(x);
        }

        cout << endl;

        /*
         * SinglyLinkedList<int>::node newNode;
         * newSinglyLinkedList.display();
         */

        // cout << endl << endl;
    }


    newSinglyLinkedList.traverse(newSinglyLinkedList.getHead());

    cout << endl;

    cout << "The linked list displayed " + isForwardOrBackward + " is " << endl << endl;
    newSinglyLinkedList.displayList<int>();

    cout << "This is meant to display the linked list recursively " << endl << endl;
    newSinglyLinkedList.displayRecursively(newSinglyLinkedList.getHead());


    return 0;
}
