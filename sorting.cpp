#include <iostream>
using namespace std;

void bubble_sort(int arr[], int n)
{
    bool swapped = false;
    for(int i = n-2; i>=0; --i)   //i = 0; i<n-1; ++i
    {
        swapped = false;

        for(int j = 0; j<=i; ++j) // j = 0; j<n-i-1; ++j
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }

        }
        if(swapped == false)
        {
            break;
        }
        for(int i = 0; i<n; ++i)
        cout<<arr[i]<<" ";
        cout<<endl;
    }
}

void selection_sort(int arr[], int n)
{
    int s;
    for(int i = 0; i<n-1; ++i)
    {
        s = i;
        for(int j = i+1; j<n; ++j)
        {
            if(arr[s]>arr[j])
                s = j;
        }
        swap(arr[s],arr[i]);
        for(int i = 0; i<n; ++i)
        cout<<arr[i]<<" ";
        cout<<endl;
    }
}

void isort(int arr[], int n)
{
    for(int i = 1; i<n; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;

        for(int i = 0; i<n; ++i)
        cout<<arr[i]<<" ";
        cout<<endl;
    }
}

