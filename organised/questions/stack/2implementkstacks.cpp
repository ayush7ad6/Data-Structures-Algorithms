#include <iostream>
#include <vector>

using namespace std;

class KStacks
{
    int *arr, *next, *top;
    int cap, k, freetop = 0;

public:
    KStacks(int cap, int k)
    {
        this->cap = cap;
        this->k = k;
        arr = new int[cap];
        next = new int[cap];
        top = new int[k];

        for (int i = 0; i < k; ++i)
            top[i] = -1;
        for (int i = 0; i < cap; ++i)
        {
            next[i] = i + 1;
        }
        next[cap - 1] = -1;
    }

    void push(int x, int sn)
    {
        if (freetop == -1)
            exit(1);
        int i = freetop;
        freetop = next[i];
        next[i] = top[sn];
        top[sn] = i;
        arr[i] = x;
    }

    int pop(int sn)
    {
        if (top[sn] == -1)
            exit(1);
        int i = top[sn];
        top[sn] = next[i];
        next[i] = freetop;
        freetop = i;

        return arr[i];
    }
};

int main()
{
    KStacks a(5, 3);
    a.push(100, 0);
    a.push(200, 0);
    a.push(400, 0);
    a.push(300, 1);
    cout << a.pop(1) << endl;
    return 0;
}