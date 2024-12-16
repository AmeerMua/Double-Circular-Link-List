#include "Linklist.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    Node* ans = NULL;
    Linklist list1;

    list1.insertAtTail(10);
    list1.insertAtTail(15);
    list1.insertAtHead(5);
    list1.insertAtTail(7);
    list1.insertAtTail(19);
    list1.insertAtTail(20);
    list1.insertAtTail(25);
    list1.insertAtTail(30);
    list1.insertAtTail(16);

    cout << "Displaying Forward:" << endl;
    list1.displayForward();

    cout << "Displaying Backward:" << endl;
    list1.displayBackward();

    list1.insertAtTarget(19, 50);
    cout << "After inserting 50 after 19:" << endl;
    list1.displayForward();

    list1.removeNode(7);
    cout << "After removing 7:" << endl;
    list1.displayForward();

    getch();
    return 0;
}
