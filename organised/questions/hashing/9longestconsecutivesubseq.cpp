#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int longestConsecutiveSub(vector<int> &nums)
{
    unordered_set<int> hash;

    for (auto i : nums)
        hash.insert(i);

    int ans = 0;
    int len = 0;
    for (auto i : nums)
    {
        if (hash.find(i - 1) == hash.end())
        {
            len = 1;
            int curr = i;
            while (hash.find(curr + 1) != hash.end())
            {
                curr = curr + 1;
                ++len;
            }
        }

        ans = max(ans, len);
        cout << ans << " ";
    }

    return ans;
}

int main()
{
    vector<int> v = {1, 9, 10, 11, 12, 13, 14, 15, 3, 4, 2, 20};
    longestConsecutiveSub(v);
    return 0;
}