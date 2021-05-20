// This module contains code for operations on Stack data structure using Array

#include<iostream>
using namespace std;

class stack
{
    int* arr;
    int top=-1;
    public:

    stack(int n)
    {
        arr = new int[n];
    }

    void push(int val)
    {
        if(top>1000)
        {
            cout<<"Overflow"<<endl;
            return;
        }
        top++;
        arr[top] = val;
    }

    void pop()
    {
        if(top<0)
        {
            cout<<"Underflow"<<endl;
            return;
        }
        top--;
    }

    bool isEmpty()
    {
        if(top==-1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if(top==1000-1)
        {
            return true;
        }
        return false;
    }

    int peek(int pos)
    {
        if(pos>top)
        {
            return -1;
        }
        return arr[pos];
    }

    int getTop()
    {
        return top;
    }

    void printStack()
    {
        int t = top;
        while(t>=0)
        {
            cout<<arr[t]<<" ";
            t--;
        }
        cout<<endl;
    }

};

int main()
{
    stack arr = stack(10);
    arr.push(10);
    arr.push(20);
    arr.push(30);
    arr.push(40);
    arr.push(50);
    arr.push(60);
    cout<<"At pos=3 : "<<arr.peek(3)<<endl;
    arr.printStack();
    int stack_size = arr.getTop();
    for(int i=0;i<=stack_size; i++)
    {
        arr.pop();
    }
    cout<<"Checking isEmpty(): "<<arr.isEmpty()<<endl;
    cout<<"Checking isFull: "<<arr.isFull()<<endl;
}