#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> distinctelementsinwindow(vector<int> &nums, int k)
{
    unordered_map<int, int> m;
    vector<int> ans;
    for (int i = 0; i < k; ++i)
    {
        ++m[nums[i]];
    }

    ans.push_back(m.size());

    for (int i = k; i < nums.size(); ++i)
    {
        m[nums[i - k]]--;
        if (m[nums[i - k]] == 0)
            m.erase(nums[i - k]);
        m[nums[i]]++;
        ans.push_back(m.size());
    }

    return ans;
}

int main()
{
    vector<int> a = {10, 20, 10, 10, 30, 40, 50};
    int k = 4;

    vector<int> ans;
    ans = distinctelementsinwindow(a, k);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}