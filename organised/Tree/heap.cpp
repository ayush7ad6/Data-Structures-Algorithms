#include <bits/stdc++.h>

using namespace std;

class minHeap
{
public:
    vector<int> arr;
    int size = 0;
    int capacity = 0;
    minHeap()
    {
    }
    // minHeap(int x) : arr(x)
    // {
    //     capacity = x;
    // }
    int left(int i)
    {
        return (2 * i) + 1;
    }
    int right(int i)
    {
        return (2 * i) + 2;
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    void insert(int val)
    {
        arr.push_back(val);
        ++size;
        int i = size - 1;
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
        return;
    }

    void insertAt(int i, int val)
    {
        ++size;
        arr.insert(arr.begin() + i, val);
    }

    void minHeapify(int i)
    {

        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < size && arr[l] < arr[smallest])
            smallest = l;
        if (r < size && arr[r] < arr[smallest])
            smallest = r;

        if (smallest != i)
        {
            swap(arr[smallest], arr[i]);
            minHeapify(smallest);
        }
    }

    int extractMin()
    {
        int m = arr[0];
        swap(arr[0], arr[size - 1]);
        arr.pop_back();
        --size;
        minHeapify(0);

        return m;
    }

    void decreaseKey(int i, int val)
    {
        arr[i] = val;
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    void del(int i)
    {
        arr[i] = INT_MIN;
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
        extractMin();
    }

    int getSize()
    {
        return size;
    }
    void print()
    {
        for (auto x : arr)
            cout << x << " ";
    }
};

void buildHeap(vector<int> &narr)
{
    minHeap m;
    m.arr = narr;
    m.size = narr.size();
    for (int i = (m.size - 2) / 2; i >= 0; --i)
        m.minHeapify(i);
    narr = m.arr;
}
