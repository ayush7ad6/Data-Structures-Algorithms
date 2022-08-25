#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int game(vector<int> &arr, int f, int r)
{
    if (r < f)
        return 0;
    int first = arr[f] + min(game(arr, f + 1, r - 1), game(arr, f + 2, r));
    int last = arr[r] + min(game(arr, f + 1, r - 1), game(arr, f, r - 2));

    return max(first, last);
}

int main()
{
    vector<int> arr = {20, 5, 4, 6};

    cout << game(arr, 0, 3);
    return 0;
}