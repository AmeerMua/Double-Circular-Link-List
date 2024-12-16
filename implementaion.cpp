
#include "Linklist.h"
#include <iostream>

using namespace std;

//////////////////////////////////////////// Node Class ////////////////////////////////////////////

Node::Node() 
{
    data = -1;
    next = NULL;
    prev = NULL;
}

Node::Node(int data) 
{
    this->data = data;
    next = NULL;
    prev = NULL;
}

void Node::setData(int data) 
{
    this->data = data;
}

void Node::setNext(Node* next) 
{
    this->next = next;
}

void Node::setPrev(Node* prev) 
{
    this->prev = prev;
}

int Node::getData() 
{
    return data;
}

Node* Node::getNext() 
{
    return next;
}

Node* Node::getPrev() 
{
    return prev;
}

//////////////////////////////////////////// Linklist Class ////////////////////////////////////////////

Linklist::Linklist() 
{
    head = NULL;
    tail = NULL;
}

bool Linklist::isEmpty() 
{
    return head == NULL;
}

void Linklist::insertAtTail(int data) 
{
    Node* newNode = new Node(data);

    if (isEmpty()) 
    {
    head = newNode;
    tail = newNode;
    tail->setNext(tail); 
    tail->setPrev(tail); 
    }
    else
    { 
    Node* temp = new Node(data); 
	tail->setNext(temp);
    temp->setPrev(tail);
    tail = temp;
    tail->setNext(head); 
    head->setPrev(tail); 
    }
}

void Linklist::insertAtHead(int data) 
{
    if (isEmpty())
     {
        insertAtTail(data);
    } 
    else
    {
    Node* temp = new Node(data);
    temp->setNext(head);
    head->setPrev(temp);
    head = temp;
    tail->setNext(head);
    head->setPrev(tail);
    }
}

void Linklist::displayForward()
 {
    if (isEmpty()) 
    {
        cout << "The linked list is empty." << endl;
        return;
    }

    Node* temp = head;

    do 
    {
        cout << temp->getData() << "\t";
        temp = temp->getNext();
    } while (temp != head);

    cout << endl;
}

void Linklist::displayBackward() 
{
    if (isEmpty()) 
    {
        cout << "The linked list is empty." << endl;
        return;
    }

    Node* temp = tail;

    do 
    {
        cout << temp->getData() << "\t";
        temp = temp->getPrev();
    } while (temp != tail);

    cout << endl;
}

Node* Linklist::searchTarget(int toFind) 
{
    if (isEmpty())
     {
        return NULL;
    }

    Node* temp = head;

    do {
        if (temp->getData() == toFind) 
        {
            return temp;
        }
        temp = temp->getNext();
    } while (temp != head);

    return NULL;
}

void Linklist::insertAtTarget(int target, int value) 
{
    if (isEmpty()) 
    {
        cout << "List is empty" << endl;
        return;
    }

    Node* targetNode = searchTarget(target);
    if (targetNode == NULL) 
    {
        cout << "Not found" << endl;
        return;
    }

    if (targetNode == tail) 
    {
        insertAtTail(value);
    }
    else 
    {    
        Node* temp = new Node(value);

        temp->setNext(targetNode->getNext());

        temp->setPrev(targetNode);

        targetNode->getNext()->setPrev(temp);

        targetNode->setNext(temp);
    }
}


void Linklist::removeNode (int toRemove)
{
    Node* targetNode = head;
    Node* prev = NULL;

    while(targetNode != NULL)   
    {
        if (targetNode->getData() == toRemove)
        {
            break;
        }
    else
        {
            prev= targetNode;
            targetNode = targetNode->getNext();

        }
    }
    if (targetNode== NULL)
    {
        cout<<"NOT found"<<endl;
        return;
    }
    else
    {
    if (targetNode == head)
    {
        head = head ->getNext();
        targetNode ->setNext (NULL); // yeh wali line delink kare giy
        tail->setNext(head);
        delete targetNode;
    }
    else if (targetNode == tail)
    {
        tail = prev;
        tail->setNext(head);
        delete targetNode;
    
    }
    else
    {
        prev ->setNext(targetNode->getNext());
        targetNode->setNext(NULL);
        delete targetNode;
        
    }
}

}
