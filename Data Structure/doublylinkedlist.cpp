// This module contains code for operations in Doubly linked list.

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* prev;  // Doubly linked list can traverse both sides. Thus it contains address of both previous and next node.
    node* next;

    node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL; 
    }
};

//Searching
int search(node* head, int val)
{
    int count = 0;
    node* temp = head;
    while(temp!=NULL)
    {
        if(temp->data==val)
        {
            return count;
        }
        count++;
        temp = temp->next;
    }
    return -1;
}


//Traversal

//1. Traversing forward
void traversalForward(node* head)
{
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

}

//2. Traversing backward
void traversalbackward(node* head)
{
    node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    do{
        cout<<temp->data<<" ";
        temp = temp->prev;
    }while(temp!=NULL);
    cout<<endl;
}


//Insertion in doubly linked list.
// There are 4 different cases of insertion

//1. Insertion at head
void insertionAthead(node* &head, int val)
{
    node* n= new node(val);
    if(head==NULL)
    {
        head = n;
        n->next = NULL;
        n->prev = NULL;
        return;
    }
    n->next = head;
    n->prev = NULL;
    head->prev = n;
    head = n;
}

//2. Insertion at the end
void insertionAtend(node* &head, int val)
{
    node* n= new node(val);
    if(head==NULL)
    {
        head = n;
        n->next = NULL;
        n->prev = NULL;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = NULL;
    n->prev = temp;
}

//3. Insertion at a specific postion
void insertionAtpos(node* &head, int val, int pos)
{
    node* n= new node(val);
    if(head==NULL)
    {
        head = n;
        n->next = NULL;
        n->prev = NULL;
        return;
    }
    node* temp = head;
    while(pos!=0)
    {
        temp = temp->next;
        pos--;
    }
    n->prev = temp->prev;
    n->next = temp;
    temp->prev = n;
    n->prev->next = n;
}

//4. Insertion after specific key
void insertionAfter(node* &head, int val, int key)
{
    int ind = search(head,key);
    insertionAtpos(head, val, ind+1);
}


//Deletion in a Doubly Linked list.
//There are 4 cases of deletion in Doubly linked list.

//1. Deleting at head.
void deleteAthead(node* &head)
{
    if(head==NULL)
    {
        cout<<"Underflow"<<endl;
        return;
    }
    head = head->next;
    head->prev = NULL;
}

//2. Deleting from end
void deleteAtend(node* &head)
{
    if(head==NULL)
    {
        cout<<"Underflow"<<endl;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    delete temp; 
}

//3. Delete from specific position
void deleteAtpos(node* &head, int pos)
{
    if(head==NULL)
    {
        cout<<"Underflow"<<endl;
        return;
    }
    node* curr = head;
    node* prev = NULL;
    while(pos!=0)
    {
        prev = curr;
        curr = curr->next;
        pos--;
    }
    curr->next->prev = prev;
    prev->next = curr->next;
    delete curr; 
}

//4. Delete node with specific key
void deleteKey(node* &head, int key)
{
    int ind = search(head, key);
    deleteAtpos(head, ind);
}


int main()
{
    node* head=NULL;
    //Insertion at head
    insertionAthead(head, 10);
    insertionAthead(head, 20);
    insertionAthead(head, 30);
    insertionAthead(head, 40);
    traversalForward(head);  //Traversal forward

    //Insertion at end
    insertionAtend(head, 5);
    insertionAtend(head, 2);

    //Traversal Backward
    traversalbackward(head);

    //Insertion at position 2(index = 2). 
    insertionAtpos(head, 15,2);
    traversalForward(head);

    //Insertion after 20.
    insertionAfter(head, 55, 20);
    traversalForward(head);

    //Deletion from head.
    deleteAthead(head);
    traversalForward(head);

    //Deletion from end;
    deleteAtend(head);
    traversalForward(head);

    //Delete from specific position
    deleteAtpos(head, 3);
    traversalForward(head);

    //Delete node at specific key=10
    deleteKey(head, 10);
    traversalForward(head);
}