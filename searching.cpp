#include <iostream>
#include <string>
#include "header.h"


int binarysearch(int arr[], int n, int num)
{
    int begin = 0;
    int mid = n/2;
    while(arr[mid]!=num && begin<=mid)
    {
        if(arr[mid]>num)
        {
            mid = (mid + begin)/2;
        }
        else
        {
            begin = mid + 1;
            mid = (begin + n)/2;
        }
    }
    if(arr[mid] == num)
        return mid;
    else
        return -1;
}

int recbsearch(int arr[], int low, int high, int num)
{
    int mid = (low+high)/2;


    if(low>high)
        return -1;

    if(arr[mid]==num)
        return mid;

    if(arr[mid]>num)
        recbsearch(arr,low, mid-1, num);
    else
        recbsearch(arr, mid+1, high, num);
}


