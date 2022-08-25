#include <iostream>

using namespace std;

int majority(int arr[], int n)
{
    int count = 1, ans = 0;
    for (int i = 1; i < n; ++i)
    {
        if (arr[ans] == arr[i])
            ++count;
        else
        {
            count = 1;
            ans = i;
        }
    }

    return arr[ans];
}

int main()
{
    int arr[] = {8, 8, 6, 6, 6, 4, 6};
    cout << majority(arr, 7);
    return 0;
}