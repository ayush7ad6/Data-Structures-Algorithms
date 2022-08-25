#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool givenSum(vector<int> &arr, int sum)
{
    // non negative integers
    int f = 0, r = 0;
    int curr = 0;

    while (r < arr.size() && curr != sum)
    {

        if (curr > sum)
        {
            curr -= arr[f];
            ++f;
        }
        else if (curr < sum)
        {
            curr += arr[r];
            ++r;
        }
        // cout << curr << " ";
    }

    return sum == curr;
}

int main()
{
    vector<int> arr = {1, 4, 20, 3, 10, 5};
    int sum = 33;

    cout << givenSum(arr, sum);
    return 0;
}