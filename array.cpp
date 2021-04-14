#include <iostream>
using namespace std;

int show(int arr[],int cap)                               //p r i n t   a r r a y
{
    int i;
    for(i = 0; i<cap; ++i)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
    if(cap==0)
        cout<<"Emptry Array";
    return 0;
}

int in_arr(int arr[],int n,int cap, int x)                   //i n s e r t   f u n c t i o n
{
    int i;
    for(i= 0; i<cap; ++i);          //

    if(cap==n)
    {
        cout<<"O V E R F L O W"<<endl;
        return -1;
    }

    arr[i]=x;
    //cout<<i<<endl;
    return 1;

}


bool search(int arr[], int n, int cap, int x)                    // s e a r c h
{
    int i;
    for(i = 0; i<n; ++i)
    {
        if(arr[i]==x)
            break;
    }
    if(i!=n)
        return 1;
    return 0;

}

void del(int arr[], int n, int &cap, int x)       //d e l e t e
{
    if(cap==0)
    cout<<"U N D E R F L O W";
    int i;
    if(search(arr,n,cap,x)==1)
    {
        for(i = 0; i<cap; i++)
            if(arr[i]==x)
            break;
        for(int j = i; j<cap-1; ++j)
        {
            arr[j]=arr[j+1];
        }
        --cap;
    }
    else
        cout<<"Element to be deleted not found";


}

int max_index(int arr[], int n, int cap)
{
    if(cap==0)
    {
        cout<<"NO ELEMENT PRESENT";
        return -1;
    }

    int i=0;
    int l = 0;
    for( i =0; i<cap; ++i)
    {
        if(arr[l]<arr[i])
            l=i;

    }
    return l;
}

int sec_max(int arr[], int n)           //second largest element's index
{
    int l2,l1;
    l1=0;
    l2=-1;
    for(int i=0; i<n; i++)
    {
        if(l2==-1 && arr[i]!=arr[l1])
            {
                if(arr[i]>arr[l1])
                {
                    l2=l1;
                    l1=i;
                }
                else
                    l2=i;
            }
        if(arr[l1]<arr[i])
        {
            arr[l2]=arr[l1];
            arr[l1]=arr[i];
        }
        else if(arr[l2]<arr[i] && arr[l1]>arr[i] && l2!=-1)
        {
            l2=i;
        }

    }
    if(l2==-1)
        return -1;
    return l2;

}

int z_right(int arr[], int n)                //zeros to the right in an array (complex solution could be linear)
{
    int nonzero[n]={};
    int cap = 0;
    for(int i = 0; i<n; ++i)
    {
        if(arr[i]!=0)
        {
            nonzero[cap]=i;
            cap++;
        }
    }
    int j;
    for(j = 0; j<cap; j++)
    {
        arr[j]=arr[nonzero[j]];
    }

    if(cap!=n)
    {
        for(int k = cap; k<n; ++k)
            arr[k]=0;
    }
    show(arr,n);

}

int rev_arr(int a[], int n)       //reverse an array
{
    int start=0;
    int end=n-1;
    while((start-end)!=1 && start!=end)     //SIMPLY KEEP END>START
    {
        int temp;
        temp = a[start];
        a[start]=a[end];
        a[end]=temp;
        start++;
        end--;
    }
    show(a,n);
}



int rotate_arr(int a[], int n)             //clockwise rotation
{

    int temp = a[0];
    for(int i=1; i<n; ++i)
    {
        a[i-1]=a[i];
    }
    a[n-1] = temp;
    show(a,n);
    return 1;
}

//int main()
//{
//    int a[] = {0,1,2,3,4,5};
//    rotate_arr(a,6);
//    show(a,6);
//
//    int b[] = {10,10,10};
//    cout<<sec_max(b,3);
//}


