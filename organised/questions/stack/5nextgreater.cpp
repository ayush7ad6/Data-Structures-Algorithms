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

void nextGreater(vector<int> &arr)
{
    vector<int> t = arr;
    reverse(t.begin(), t.end());
    previousGreater(t);
}

int main()
{
    // vector<int> nums = {15, 10, 18, 12, 4, 6, 2, 8};
    vector<int> nums = {5, 15, 10, 8, 6, 12, 9, 18};
    nextGreater(nums);
    return 0;
}