#include <iostream>

using namespace std;

class ArrayStack
{
    int *arr;
    int cap;
    int top1, top2;

public:
    ArrayStack(int n)
    {
        cap = n;
        top1 = -1;
        top2 = cap;
        arr = new int[n];
    }

    void push1(int x)
    {
        if (top1 < top2 - 1)
        {
            top1++;
            arr[top1] = x;
        }
    }

    void push2(int x)
    {
        if (top1 < top2 - 1)
        {
            top2--;
            arr[top2] = x;
        }
    }

    int pop1()
    {
        if (top1 >= 0)
        {
            int x = arr[top1];
            --top1;
            return x;
        }
        exit(1);
    }

    int pop2()
    {
        if (top2 < cap)
        {
            int x = arr[top2];
            ++top2;
            return x;
        }

        exit(1);
    }
};

int main()
{
    ArrayStack a(5);
    a.push1(10);
    a.push1(5);
    a.push1(15);
    a.push2(20);
    a.push1(25);
    cout << a.pop1();
    cout << a.pop2();
    cout << a.pop1();
    cout << a.pop2();
    cout << a.pop2();
    return 0;
}