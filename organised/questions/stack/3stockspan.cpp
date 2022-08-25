#include <bits/stdc++.h>
#include <stack>
#include <vector>

using namespace std;

void stockSpan(vector<int> &nums)
{
    stack<int> st;

    for (int i = 0; i < nums.size(); ++i)
    {
        while (st.empty() == false && nums[st.top()] <= nums[i])
            st.pop();

        int span = st.empty() ? i + 1 : i - st.top();
        cout << span << " ";
        st.push(i);
    }
}

int main()
{
    vector<int> a = {15, 13, 12, 14, 16, 8, 6, 4, 10, 30};

    stockSpan(a);
    return 0;
}