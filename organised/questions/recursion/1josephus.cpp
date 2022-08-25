#include <iostream>

using namespace std;

void josephus(int arr[], int n, int k, int curr, int size = 0)
{
    if (size == n - 1)
        return;
    // while (arr[curr % n] == -1)
    //     ++curr;
    for (auto i = 1; i <= k; ++i)
    {
        ++curr;
        while (arr[curr % n] == -1)
            ++curr;
    }

    // while (arr[curr % n] == -1)
    //     ++curr;

    cout << arr[curr % n] << " ";
    arr[curr % n] = -1;
    ++size;

    while (arr[curr % n] == -1)
    {
        // cout << curr % n << " ";
        ++curr;
    }

    // cout << endl;

    josephus(arr, n, k, curr, size);
}

// better MUCH MUCH MUCH

int josephus(int n, int k)
{
    if (n == 1)
        return 0;

    return (josephus(n - 1, k) + k) % n;
}

int main()
{
    int n = 3;
    int k = 3;

    cout << josephus(n, k);
    // for (auto i : arr)
    //     if (i != -1)
    //         std::cout << i;
    return 0;
}