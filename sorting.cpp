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

void merge(int arr[], int l, int m, int r)               //merge function
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int left[n1];
    int right[n2];


    for(int i = 0; i<n1; ++i)
        left[i] = arr[l+i];
    for(int i = 0; i<n2; ++i)
        right[i] = arr[m + 1 +i];

    int i= 0;
    int j = 0;
    int k = l;

    while(i<n1 && j<n2)
    {
        if(left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }
    while(n1>i)
    {
        arr[k++] = left[i++];
    }

    while(n2>j)
    {
        arr[k++] = right[j++];
    }
}


void mergesort(int arr[], int l, int r)             // merge sort function
{
    if(l<r)
    {
        int m = l + (r-l)/2;
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        merge(arr,l,m,r);
    }
}


void partition(int arr[], int l, int p, int r)           //naive partition
{
    int temp[r-l+1];
    int index = 0;
    for(int i = 0; i<=r; i++)
    {
        if(arr[i]<=arr[p])
            temp[index++] = arr[i];
    }

    for(int i = 0; i<=r; i++)
    {
        if(arr[i]>arr[p])
            temp[index++] = arr[i];
    }

    for(int i = 0; i<=r; ++i)
        arr[i] = temp[i];
}


int lomuto(int arr[], int l, int r)                     //lumoto partition
{
    int pivot = arr[r];
    int i = l-1;
    for(int j = l; j<r; ++j)
    {
        if(arr[j]<pivot)                    //no equal
        {
            ++i;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}


int hoares(int arr[], int l, int r)                     //hoare's partition
{
    int i = l - 1;
    int j = r+1;
    int pivot = arr[l];
    while(true)
    {
        do
        {
            ++i;
        }while(arr[i]<pivot);

        do
        {
            --j;
        }while(arr[j] > pivot);
        if(i>=j)
        {
            return j;
        }
        swap(arr[i],arr[j]);
    }
}


void quicksort(int arr[], int l, int r)        //lomuto partition
{
    if(l < r)
    {
        int p = hoares(arr, l , r);
        quicksort(arr, l, p-1);                     //p instead of p-1 in hoares
        quicksort(arr, p+1, r);
    }
}



void ncsort(int arr[], int n, int k)            //counting sort naive
{
    int count[k] = {};
    for(int i = 0; i<n; ++i)
    {
        count[arr[i]]++;
    }

    int ind = 0;

    for(int i = 0; i<k; ++i)
    {
        for(int j = 0; j<count[i]; ++j)
        {
            arr[ind] = i;
            ++ind;
        }
    }
}

void csort(int arr[], int n, int k)            //counting sort general
{
    int count[k] = {};
    for(int i = 0; i<n; ++i)
    {
        count[arr[i]]++;
    }

    int output[n];

    for(int i = 1; i<k; ++i)
    {
        count[i] = count[i] + count[i-1];
    }

    for(int j = n-1; j>-1; --j)
    {
        output[count[arr[j]] - 1] = arr[j];
        count[arr[j]]--;
    }

    for(int i = 0; i<n; ++i)
    {
        arr[i] = output[i];
    }
}

void rcsort(int arr[], int n, int exp)           //counting routine
{
    int count[10] = {0};
    int output[n];
    for(int i = 0; i<n; ++i)
    {
        count[(arr[i]/exp) % 10]++;
    }

    for(int i = 1; i<10; ++i)
    {
        count[i] = count[i] + count[i-1];
    }

    for(int i = n-1; i>=0; --i)
    {
        output[count[(arr[i]/exp)%10]-1] = arr[i];
        count[arr[i]/exp % 10]--;
    }

    for(int j = 0; j<n; ++j)
    {
        arr[j] = output[j];
    }
}

void rsort(int arr[], int n)                       //radix sort
{
    int mx = arr[0];
    for(int i = 1; i<n; ++i)
    {
        if(mx<arr[i])
            mx = arr[i];
    }

    for(int exp = 1; mx/exp > 0; mx = mx*10)
    {
        rcsort(arr, n, exp);
    }
}








