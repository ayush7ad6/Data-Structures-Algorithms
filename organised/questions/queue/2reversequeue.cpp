#include <iostream>
#include <queue>

using namespace std;

void reverse(queue<int> &q)
{
    if (q.empty())
        return;
    int front = q.front();
    q.pop();
    reverse(q);

    q.push(front);
}
void printQ(queue<int> q)
{
    while (q.empty() == false)
    {
        cout << q.front() << " ";
        q.pop();
    }
}
int main()
{
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    printQ(q);
    cout << endl;
    reverse(q);
    printQ(q);

    return 0;
}