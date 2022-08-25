#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void previousGreater(vector<int> &arr)
{
    stack<int> st;

    for (auto i : arr)
    {
        while (st.empty() == false && st.top() <= i)
            st.pop();

        int pg = st.empty() ? -1 : st.top();
        cout << pg << " ";
        st.push(i);
    }
}

int main()
{
    // vector<int> nums = {8, 2, 6, 4, 12, 18, 10, 15};
    // vector<int> nums = {15, 10, 18, 12, 14, 6, 2, 8};
    vector<int> nums = {15, 10, 18, 9};
    // reverse(nums.begin(), nums.end());
    previousGreater(nums);
    return 0;
}