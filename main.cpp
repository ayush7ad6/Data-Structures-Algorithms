//#include <iostream>

#include "header.h"
#include "hashing.h"
#include "linkedlist.h"
#include "queue.h"
#include "tree.h"
#include "bst.h"
#include "minheap.h"


//using namespace::std;

int main()
{
    int a[] = {10,50,20,30,40,31};
    MinHeap heap(6,a);
    heap.show();
    heap.heapify(0);
    heap.show();
    cout<<heap.extractMin()<<endl;
    heap.show();
    heap.decreaseKey(3,1);
    heap.show();
    heap.deleteNode(0);
    heap.show();
    return 0;
}





