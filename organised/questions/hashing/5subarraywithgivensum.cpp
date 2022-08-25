#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool subarrayWithGivenSum(vector<int> &arr, int target)
{
    int pre = 0;
    unordered_set<int> hash;

    for (int i = 0; i < arr.size(); ++i)
    {
        pre += arr[i];
        if (pre == target)
        {
            cout << "0 to " << i << endl;
            return true;
        }

        if (hash.find(pre - target) != hash.end())
        {
            cout << "to " << i << endl;
            return true;
        }

        hash.insert(pre);
    }

    return false;
}

int main()
{
    vector<int> arr = {5, 8, 6, 13, 3, -1};
    subarrayWithGivenSum(arr, 3);
    return 0;
}