//This module contains code for all operations on Circular Linked-List.

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

//Taversal
void traversal(node* head)
{
    node* temp = head;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }while((temp!=head));
    cout<<endl;
}


//Searching
int search(node* head, int val)
{
    int pos=0;
    node* temp = head;
    do{
        if(temp->data==val)
        {
            return pos;
        }
        pos++;
        temp = temp->next;
    }while(temp != head);
    return -1;
}

//Insertion in a Circular Linked-List
//There are 4 ways we can insert in a circular linked list

//1. Insertion at head
void insertAthead(node* &head, int p)
{
    node* n = new node(p); 
    if(head==NULL)
    {
        n->next=n;
        head = n;
        return;
    }
    node* temp = head;
    
    while(temp->next!=head)
    {
        temp = temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
}

//2. Insertion at the end
void insertionAtEnd(node* &head, int p)
{
    node* temp = head;
    node* n = new node(p);
    if(temp==NULL)
    {
        insertAthead(head, p);
        return;
    }
    while(temp->next!=head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head; 
}

//3. Insertion in between remains the same as Linked-List.
//4. Insertion at specific position in between a circular linkedlist is same as linkedlist.

//Deletion in a linked list
//There are 4 ways of deleting a node in a linkedlist.
//Deletion in between with key or at specific position remains same as linkedlist.

//1. Deleting the first node.
void deleteAthead(node* &head)
{
    if(head==NULL)
    {
        return;
    }
    if(head->next == head)
    {
        head==NULL;
        return;
    }
    node* temp = head;
    while(temp->next!=head)
    {
        temp = temp->next;
    }
    head = head->next;
    temp->next = head;
}

//2. Deletion at the end.
void deleteAtend(node* &head)
{
    if(head==NULL)
    {
        return;
    }
    if(head->next==head)
    {
        head=NULL;
        return;
    }
    node* temp=head;
    node* prev = NULL;
    while(temp->next!=head)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    temp->next=NULL;
}

int main()
{
    node* head=NULL;
    insertAthead(head, 10);
    insertionAtEnd(head, 20);
    insertionAtEnd(head, 30);
    insertionAtEnd(head, 40);
    insertionAtEnd(head, 50);
    insertAthead(head, 100);
    traversal(head);
    deleteAthead(head);
    traversal(head);
    deleteAtend(head);
    traversal(head);
}