#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void leftRotate(vector<int> &arr, int d)
{
    reverse(arr.begin(), arr.begin() + d + 1);
    reverse(arr.begin() + d + 1, arr.end());
    reverse(arr.begin(), arr.end());
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};

    leftRotate(arr, 2);

    for (auto i = arr.begin(); i != arr.end(); ++i)
        cout << *i << " ";
    return 0;
}
