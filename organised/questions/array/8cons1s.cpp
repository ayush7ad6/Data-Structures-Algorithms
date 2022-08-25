#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxConsecutiveone(vector<int> &arr)
{
    int curr = 0, res = 0;
    for (auto i : arr)
    {
        if (i == 0)
        {
            curr = 0;
        }
        else
        {
            ++curr;
            res = max(res, curr);
        }
    }

    return res;
}

int main()
{
    vector<int> arr = {0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1};

    cout << maxConsecutiveone(arr);
    return 0;
}