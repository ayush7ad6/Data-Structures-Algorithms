#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxOddEven(vector<int> &arr)
{
    int res = 1;
    int curr = 1;
    for (int i = 1; i < arr.size(); ++i)
    {
        if (((arr[i] & 1) && !(arr[i - 1] & 1)) || (!(arr[i] & 1) && (arr[i - 1] & 1)))
        {
            ++curr;
            res = max(res, curr);
        }
        else
        {
            curr = 1;
        }
    }

    return res;
}

int main()
{
    // vector<int> arr = {1, 2, 3, 4, 5, 5, 6, 5, 4, 3, 2, 1, 0};
    vector<int> arr = {11, 10, 11, 2, 3};

    cout << maxOddEven(arr);
    return 0;
}