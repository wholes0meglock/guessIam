#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};
class Stack
{
    Node* top;
    public:
    Stack()
    {
        top = nullptr;
    }
    void push(int value)
    {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }
    void pop()
    {
        if(top = NULL)
        {
            cout<<"Empty stack, whats wrong with you twin! " << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }
};
class Queue
{
    Node *front,*rear;
    public:
    Queue()
    {
        front = rear = NULL;
    }
    void enqueue(int val)
    {
        Node* newNode = new Node();
        newNode->data = val;
        if( front == rear == NULL)
        {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }
    void dequeue()
    {
        if(front == rear == NULL)
        {
            cout << "twin queue is empty! " << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
    }
};
#define size 5
class CircularQueue
{
    int items[size],front,rear;
    public:
    CircularQueue()
    {
        front = rear = -1;
    }
    bool isFull() {
    return (front == 0 && rear == size - 1) || (front == rear + 1);
}
bool isEmpty() {
return front == -1;
}
    void increase(int element)
    {
        if(isFull())
        {
            cout << "Queue is full\n";
return;
        }
        if(front == -1)
        {
            front = 0;
        }
            rear = (rear + 1)%size;
            items[rear] = element;
        
    }
    void decrease()
    {
        if(isEmpty())
        {
            cout << "empty" << endl;
            return;
        }
        cout << "removed: " << items[front] << endl;
        if(front == rear)
        {
            front = rear = -1;
        }
        else{
            front = (front + 1)%size;
        }
    }
    void display() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Queue: ";
    int i = front;
    while (true) {
        cout << items[i] << " ";
        if (i == rear) {
            break;  // stop once we've printed the rear
        }
        i = (i + 1) % size;  // move forward circularly
    }
    cout << endl;
}


};
class CircularUsingLL
{
    Node* front;
    Node* rear;
    public:
    CircularUsingLL()
    {
        front = rear = nullptr;
    }
    void enqueue(int val)
    {
        Node* newNode = new Node();
        newNode->data = val;
        if(!front)
        {
            front = rear = newNode;
            rear->next = front;
        }
        else{
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }
    }
    void dequeue()
    {
        if(!front)
        {
            cout << "empty" << endl;
        }
        if(front == rear)
        {
            cout << "removed : " << front->data << endl;
            delete front;
            front = rear = nullptr;
        }
        else
        {
            Node* temp = front;
            cout << "removed: " << front->data << endl;
            front = front->next;
            rear->next = front;
            delete temp;
        }
    }
    void details()
    {
        if(!front)
        {cout << "emtpy" << endl;
        return;}
        Node* temp = front;
        while(temp != rear)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
        cout << rear->data << endl;
        cout << "(back to front) " << rear->next->data  << endl;

    }
};