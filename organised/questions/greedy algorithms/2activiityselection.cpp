#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int activitySelection(vector<pair<int, int>> pairs)
{
    sort(pairs.begin(), pairs.end());

    int ans = 0, count = 1;
    int n = pairs.size();
    int i = 0, j = 1;
    while (j < n)
    {
        // int j = i + 1;
        // count = 1;
        if (pairs[j].first >= pairs[i].second)
        {
            ++count;
            cout << pairs[j].first << " " << pairs[j].second << endl;
            i = j;
        }
        ++j;
        ans = max(ans, count);
    }
    cout << ans;
    return ans;
}

int main()
{
    vector<pair<int, int>> arr;
    arr = {{2, 3}, {1, 4}, {5, 8}, {6, 10}};
    activitySelection(arr);
    arr = {{1, 3}, {2, 4}, {3, 8}, {10, 11}};
    cout << endl;
    activitySelection(arr);
    return 0;
}