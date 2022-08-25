/*
    find the longest subarray with equal zeros and ones
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestSubarrayEqualzerosones(vector<int> &nums)
{
    unordered_map<int, int> m;
    m[0] = 0;

    int count = 0;
    int ans = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        count = count + (nums[i] == 1 ? 1 : -1);

        if (m.find(count) != m.end())
        {
            ans = max(ans, i - m[count] + 1);
        }
        else
            m[count] = i + 1;
    }

    return ans;
}

int main()
{
    vector<int> arr = {0, 0, 0, 1, 1, 0, 0, 0, 0, 1};

    cout << longestSubarrayEqualzerosones(arr);
    return 0;
}