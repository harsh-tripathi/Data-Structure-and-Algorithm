// This module contains code for operations on queue with linked list.

#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class queue{
    node* front;
    node* rear;

    public:
    queue()
    {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int val)
    {
        node* n = new node(val);
        if(rear==NULL)
        {
            front=n;
            rear = n; 
            return;
        }
        rear->next = n;
        rear = n;
    }

    void dequeue()
    {
        if(front==NULL)
        {
            cout<<"Underflow"<<endl;
            return;
        }
        front = front->next; 
    }

    bool isEmpty()
    {
        if(front==NULL)
        {
            return true;
        }
        return false;
    }

    int peek(int pos)
    {
        if(front==NULL)
        {
            return -1;
        }
        node* temp = front;
        while(pos>0)
        {
            if(temp==NULL)
            {
                return -1;
            }
            temp = temp->next;
            pos--;
        }
        return temp->data;
    }

    void display()
    {
        node* temp = front;
        if(temp==NULL)
        {
            cout<<"Empty"<<endl;
            return;
        }
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main()
{
    queue q;

    //Inserting nodes in queue
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    //Traversing the queue
    q.display();

    q.enqueue(50);
    q.enqueue(60);


    //Deleting nodes
    q.dequeue();
    q.dequeue();
    q.display();

    //Peek at position=2
    cout<<q.peek(2)<<endl;

    return 0;
}