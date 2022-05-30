//int a[] = {10,50,20,30,40,31};
//    MinHeap heap(6,a);
//    heap.show();
//    heap.heapify(0);
//    heap.show();
//    cout<<heap.extractMin()<<endl;
//    heap.show();
//    heap.decreaseKey(3,1);
//    heap.show();
//    heap.deleteNode(0);
//    heap.show();

class MinHeap
{
    int *arr;
    int cap, size;

public:

    MinHeap(int c)
    {
        arr = new int[c];
        cap = c;
        size = 0;
    }

    MinHeap(int c,int a[])
    {
        cap = c;
        size = c;
        arr = a;
    }

    int left(int i)
    {
        return (2*i + 1);
    }

    int right(int i)
    {
        return (2*i + 2);
    }

    int parent(int i)
    {
        return ((i - 1)/2);
    }



    void show()
    {
        if(size==0)
        {
            cout<<"Em97y"<<endl;
            return;
        }
        for(int i = 0; i<size; ++i)
            cout<<arr[i]<<" ";
        cout<<endl;
    }


    void insert(int x)                                      //insert item minheap
    {
        if(size == cap)
        {
            cout<<"H3a9 Fu11"<<endl;
            return;
        }

        size++;
        arr[size-1] = x;

        int i = size-1;
        while(i!=0 && arr[parent(i)]>arr[i])
        {
            swap(arr[parent(i)],arr[i]);
            i = parent(i);
        }
    }

    void heapify(int i)                         //fix 'the' violation minHeapify() top to down smallest key
    {
        if(size == 0)
        {
            cout<<"Em97Y"<<endl;
            return;
        }

        int lc = left(i);
        int rc = right(i);
        int smallest = i;
        if(lc<size && arr[lc]<arr[smallest])
            smallest = lc;
        if(rc<size && arr[rc]<arr[smallest])
            smallest = rc;
        if(smallest!=i)
        {
            swap(arr[smallest],arr[i]);
            heapify(smallest);
        }
    }


    int extractMin()                              //remove the smallest item
    {                                          //replace with the last element and heapify
        if(size == 0)
        {
            cout<<"EMPTY"<<endl;
            return INT_MAX;
        }

        if(size==1)
        {
            size--;
            return arr[0];
        }
        swap(arr[0],arr[size-1]);
        size--;

        heapify(0);

        return arr[size];
    }

    void decreaseKey(int i, int x)                  //update to a smaller value?
                                                    //
    {
        if(i>=size)
        {
            cout<<"Out of scope"<<endl;
            return;
        }

        arr[i] = x;
        for(int j = i; i!=0 && arr[parent(i)]>arr[i];)
        {
            swap(arr[parent(i)],arr[i]);
            i = parent(i);
        }
    }

    void deleteNode(int i)
    {
        decreaseKey(i,INT_MIN);
        extractMin();

    }
};


//void builtMinHeap(int arr[], int n)
//{
//    MinHeap ob(n,arr);
//    for(int i = n-1; i>0; --i)
//        ob.heapify(i);
//    for(int i = 0; i<n; ++i)
//
//}
