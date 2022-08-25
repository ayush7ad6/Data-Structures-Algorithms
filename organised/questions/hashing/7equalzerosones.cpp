#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int maximumlenOnesZeros(vector<int> &nums)
{
    int pre = 0;

    unordered_map<int, int> m;
    m[0] = -1;
    int len = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        pre = pre + (nums[i] == 1 ? 1 : -1);
        if (m.find(pre) != m.end())
        {
            cout << "from " << m[pre] + 1 << " to " << i << endl;
            len = max(i - m[pre], len);
        }
        else
            m[pre] = i;
    }

    return len;
}

int main()
{
    vector<int> nums = {1, 0, 1, 1, 1, 0, 0};
    maximumlenOnesZeros(nums);
    return 0;
}