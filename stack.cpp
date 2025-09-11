#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class Stack
{
    Node *top;
    public:
    Stack()
    {
        top = NULL;
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
            cout << "stack is empty" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }
};
class Queue
{
    Node* front;
    Node* rear;
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    void enqueue(int value)
    {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        if(rear == nullptr)
        {
            front = rear = newNode;
            return;
        }
       rear->next = newNode;  
       rear = newNode;        
    }
    void dequeue()
    {
        if(front == nullptr)
        {
            cout << "Queue underflow" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;
        if(front == nullptr)
        {
            rear = nullptr;
        }
        delete temp;
    }
};
#define SIZE 5
class CircularQueue
{
    int items[SIZE], front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }
    void enqueue(int element)
    {
        if(isFull())
        {
            cout << "Queue is full" << endl; return; 
        }
        if(front == -1)
        {
            front == 0;
        }
        rear = (rear + 1) % SIZE;
        items[rear] = element;
    }
    void dequeue()
    {
        if(isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        cout << "Removed:" << items[front] << endl;
        if(front == rear)
        {
            front = rear = -1;
        }
        else{
            front = (front + 1)%SIZE;
        }
    }
};
class CircularQueue2
{
    int data;
    Node* front, *rear;
    public:
    CircularQueue2()
    {
        front = rear = NULL;
    }
    void enqueue(int val)
    {
        Node* temp = new Node();
        temp->data = val;
        if(!front)
        {
            front = rear = temp;
            rear->next = front;
        }
        else{
            rear->next = temp;
            rear = temp;
            rear->next = front;
            // rear->next = temp;
            // temp->next = front;
            // rear = temp;

        }
    }
    void dequeue()
    {
        Node* temp = front;
        front = front->next;
        rear->next = front;
        delete temp;
    }
};