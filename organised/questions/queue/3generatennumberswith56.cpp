#include <iostream>
#include <queue>

using namespace std;

void generateNumbers(int n)
{
    int numbers[] = {3, 5, 6};

    queue<int> q;

    for (int i = 0; i < sizeof(numbers) / sizeof(int); ++i)
        q.push(numbers[i]);
    // q.push(numbers[1]);

    while (n--)
    {
        auto curr = q.front();
        q.pop();
        cout << curr << " ";

        for (int i = 0; i < sizeof(numbers) / sizeof(int); ++i)
            q.push(curr * 10 + numbers[i]);
    }
}

int main()
{
    generateNumbers(20);
    return 0;
}