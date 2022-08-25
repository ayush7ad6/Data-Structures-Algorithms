#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int minJumps(vector<int> &arr, int curr, vector<int> st = {})
{
    st.push_back(arr[curr]);
    if (curr == arr.size() - 1)
    {
        for (auto x : st)
            cout << x << " ";
        cout << endl;
        return 0;
    }
    int res = INT_MAX;
    for (int i = curr + 1; i <= curr + arr[curr]; ++i)
    {
        if (i < arr.size())
        {

            int sub = minJumps(arr, i, st);
            if (sub != INT_MAX)
            {
                res = min(res, sub + 1);
                // if (res == sub + 1)
                //     cout << arr[curr] << " ";
            }
        }
    }

    return res;
}

int main()
{
    vector<int> arr = {4, 1, 5, 3, 1, 3, 2, 1, 8};

    cout << minJumps(arr, 0);
    return 0;
}