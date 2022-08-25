#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int maxsubarrayWithGivenSum(vector<int> &arr, int target)
{
    int pre = 0;
    unordered_map<int, int> hash;
    int len = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        pre += arr[i];
        if (pre == target)
        {
            hash.insert({pre, i});
            len = max(len, i + 1);
            cout << "from 0 to " << i << endl;
            // return true;
        }

        else if (hash.find(pre - target) != hash.end())
        {
            len = max(len, i - hash[pre - target]);
            cout << "from " << hash[pre - target] + 1 << " to " << i << endl;
        }
        if (hash.find(pre) == hash.end())
            hash.insert({pre, i});
    }

    return len;
}

int main()
{
    vector<int> arr = {5, 8, 6, 13, 3, -1};
    cout << endl
         << maxsubarrayWithGivenSum(arr, 16);
    return 0;
}
