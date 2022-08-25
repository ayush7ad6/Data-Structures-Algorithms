#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> previousSmaller(vector<int> arr)
{
    vector<int> ans(arr.size(), 1);

    stack<int> st;

    for (int i = 0; i < arr.size(); ++i)
    {
        while (st.empty() == false && arr[i] <= arr[st.top()])
            st.pop();

        int span = st.empty() ? i : i - st.top() - 1;
        ans[i] = span;
        st.push(i);
    }

    return ans;
}

vector<int> nextSmaller(vector<int> arr)
{
    vector<int> ans(arr.size(), 1);
    stack<int> st;

    for (int i = arr.size() - 1; i >= 0; --i)
    {
        while (st.empty() == false && arr[i] <= arr[st.top()])
            st.pop();
        int span = st.empty() ? arr.size() - 1 - i : st.top() - i - 1;
        ans[i] = span;
        st.push(i);
    }

    return ans;
}

int maximumArea(vector<int> &nums)
{
    stack<int> st;
    int res = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        int curr = 0;
        while (st.empty() == false && nums[st.top()] >= nums[i])
        {
            int tp = st.top();
            st.pop();
            curr = nums[tp] * (st.empty() ? i : i - st.top() - 1);
            res = max(res, curr);
        }
        st.push(i);
    }

    while (st.empty() == false)
    {
        int tp = st.top();
        st.pop();
        int curr = nums[tp] * (st.empty() ? nums.size() : nums.size() - st.top() - 1);
        res = max(curr, res);
    }

    return res;
}
int main()
{
    vector<int> a = {5, 6, 5, 4, 1, 5, 6};

    vector<int> pre = previousSmaller(a);
    vector<int> next = nextSmaller(a);
    for (auto i : pre)
        cout << i << " ";
    cout << endl;

    for (auto i : next)
        cout << i << " ";
    cout << endl;

    int ans = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        int curr = a[i] * (pre[i] + next[i] + 1);
        ans = max(ans, curr);
    }

    cout << ans;

    ans = maximumArea(a);
    cout << endl
         << ans;
    return 0;
}