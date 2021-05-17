//This module contains code for different operations on Linked-List.

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int p)
    {
        data = p;
        next=NULL;
    }
};

//Searching in a linked list.
int search(node* head, int val)
{
    int pos=0;
    node* temp = head;
    while(temp != NULL)
    {
        if(temp->data==val)
        {
            return pos;
        }
        pos++;
        temp = temp->next;
    }
    return -1;
}

//There are 4 types of insertions.

//1. Insertion at the last.
void insertionAtEnd(node* &head, int p)
{
    node* temp = head;
    node* n = new node(p);
    if(temp==NULL)
    {
        head=n;
        return;
    }
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

//2. Insertion at specific position.
void insertionAtpos(node* &head, int p, int pos)
{
    node* temp = head;
    node* n = new node(p);
    while(pos>1)
    {
        temp = temp->next;
        pos--;
    }
    n->next = temp->next;
    temp->next = n;
}

//3. Insertion at head.
void insertionAthead(node* &head, int p)
{
    node* temp = head;
    node* n = new node(p);
    head = n;
    n->next = temp;
}

//4. Insertion after specific node.
void insertionAfter(node* &head, int p, int s)
{
    int pos = search(head, s);
    insertionAtpos(head, p, pos+1);
}

//Traversal of a linked list.
void traverse(node* head)
{
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


//Deletion in a linkedlist.
//There are 4 cases in deletion.

//1. Deleting the first node
void deletehead(node* &head)
{
    node* temp = head;
    if(head==NULL)
    {
        return;
    }
    head = temp->next;
    delete temp;
}

//2. Delete the last node.
void deletelast(node* &head)
{
    node* temp = head;
    node* n = head->next;
    if(head==NULL)
    {
        return;
    }
    while(n->next!=NULL)
    {
        temp = temp->next;
        n = n->next;
    }
    temp->next = NULL;
    delete n;
}

//3. Delete the node at specific position.
void deleteAtpos(node* &head, int pos)
{
    if(pos==0)
    {
        head = head->next;  
    }
    node* curr = head;
    node* prev= NULL;
    node* nxt = head->next;
    while(pos>0)
    {
        prev = curr;
        curr = curr->next;
        nxt = curr->next;
        pos--;
    }
    prev->next = nxt;
    delete curr;
}

//4. Delete the specific node with key.
void deleteAtkey(node* &head, int key)
{
    int pos = search(head,key);
    if(key==-1)
    {
        cout<<"Could not find key";
        return;
    }
    deleteAtpos(head,pos);
}

int main()
{
    node* head=NULL;
    //Adding nodes at the last.
    insertionAtEnd(head, 10);
    insertionAtEnd(head, 15);
    insertionAtEnd(head, 25);
    insertionAtEnd(head, 35);
    traverse(head);
    //Adding nodes at specific position.
    insertionAtpos(head, 45, 2);
    insertionAtpos(head, 22, 3);
    traverse(head);
    //Adding nodes at head.
    insertionAthead(head, 1);  
    traverse(head);
    //Adding node after specific key.
    insertionAfter(head, 65, 45);
    traverse(head);
    //Deleting the first node.
    deletehead(head);
    traverse(head);
    //Deleteing the last node.
    deletelast(head);
    traverse(head);
    //Deleting at specific position.
    deleteAtpos(head, 3);
    traverse(head);

    insertionAfter(head, 65, 45);
    insertionAtpos(head, 67, 3);
    traverse(head);
    //Deleting node with specific key.
    deleteAtkey(head,45);
    traverse(head);
}