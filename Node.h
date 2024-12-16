class Node 
{
private:
    int data;
    Node* next;
    Node* prev; // Pointer to the previous node

public:
    Node();
    Node(int);
    void setData(int);
    void setNext(Node*);
    void setPrev(Node*); // Setter for previous node
    int getData();
    Node* getNext();
    Node* getPrev(); // Getter for previous node
};