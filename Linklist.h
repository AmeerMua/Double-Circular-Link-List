#include "Node.h"

class Linklist 
{
private:
    Node* head;
    Node* tail;

public:
    Linklist(); // Default constructor
    bool isEmpty();
    void insertAtHead(int);
    void insertAtTail(int);
    void displayForward();
    void displayBackward();
    void insertBetween(Node*, int, int);
    void insertAtTarget(int, int);
    Node* searchTarget(int);
    void removeNode(int);
};