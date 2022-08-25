#include <iostream>
#include <queue>

using namespace std;

class StackQ
{
    queue<int> q1, q2;

public:
    void pop()
    {
        if (q1.empty())
            return;
        q1.pop();
    }

    void push(int x)
    {
        while (q1.empty() == false)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);

        while (q2.empty() == false)
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int top()
    {
        if (q1.size() == 0)
            exit(1);
        return q1.front();
    }
};