// In this module we have implemented the binary search algorithm
//Compuslory condition: The array should be in sorted order

#include<iostream>
using namespace std;

int array_size;

int binarySearch(int* arr, int s)
{
    int ind=0;
    int low=0, high=array_size-1;
    while(low<high)
    {
        if(low+1==high)
        {
            if(arr[high]==s)
            {
                return high;
            }
            else if(arr[low]==s)
            {
                return low;
            }
            return -1;
        }
        ind = (low+high)/2;
        if(arr[ind]==s)
        {
            return ind;
        }
        else if(arr[ind]>s)
        {
            high=ind;
        }
        else if(arr[ind]<s)
        {
            low=ind;
        }

    }
    return -1;
}

void traverse(int* arr)
{
    for(int i=0; i<array_size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[] = {10,12,45,54,98,224,345,355,949};
    array_size = sizeof(arr)/sizeof(arr[0]);
    traverse(arr);
    int n = binarySearch(arr, 10);
    cout<<"Binary search result is: "<<n<<endl;
    n = binarySearch(arr, 54);
    cout<<"Binary search result is: "<<n<<endl;
    n = binarySearch(arr, 949);
    cout<<"Binary search result is: "<<n<<endl;
    return 0;
}