// This module contains code for operations on Stack with linkedlist.

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val)
    {
        data = val; 
        next = NULL;
    }
};

class stack{
    node* head;

    public:
    stack()
    {
        head=NULL;
    }

    void push(int val)
    {
        node* n = new node(val);
        if(head==NULL)
        {
            head = n;
            return;
        }
        n->next = head;
        head = n;
    }

    void pop()
    {
        if(head==NULL)
        {
            cout<<"Underflow"<<endl;
            return;
        }
        head = head->next;
    }

    void display()
    {
        node* temp = head;
        if(temp==NULL)
        {
            return;
        }
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    bool isEmpty()
    {
        if(head==NULL)
        {
            return true;
        }
        return false;
    }

    int peek(int pos)
    {
        if(head == NULL)
        {
            return -1;
        }
        node* temp = head;
        while(pos>0)
        {
            if(temp==NULL)
            {
                cout<<"Position not in the list"<<endl;
                return -1;
            }
            temp = temp->next;
            pos--;
        }
        if(temp!=NULL)
        {
            return temp->data;
        }
        return -1;
    }

};

int main()
{
    stack s;

    //Inserting nodes in the stack
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    //Displaying the stack.
    s.display();

    //Deleting node from the stack.
    s.pop();
    s.pop();
    s.display();

    //Peek at pos=2
    cout<<s.peek(3)<<endl;
}