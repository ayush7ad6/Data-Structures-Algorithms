#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

#include <unordered_map>
#include <map>

using namespace std;

// vector<int> jobSequencing(vector<pair<int, int>> jobs)
// {
//     int low = INT_MAX, high = INT_MIN;

//     unordered_map<int, priority_queue<int>> m;

//     for (auto x : jobs)
//     {
//         int mind = x.first;
//         for (int i = mind; i >= 1; --i)
//         {
//             m[i].push(x.second);
//         }
//         if (low > x.first)
//             low = x.first;
//         if (high < x.first)
//             high = x.first;
//     }
//     cout << low << " " << high << endl
//          << endl;
//     unordered_map<int, int> vis;
//     vector<int> ans;
//     int profit = 0;

//     for (int i = high; i >= 1; --i)
//     {
//         while (m[i].empty() == false && vis[m[i].top()] == 1)
//             m[i].pop();

//         int curr = m[i].top();
//         cout << i << " " << curr << " " << vis[curr] << endl;

//         if (vis[curr] == 0)
//         {
//             ans.push_back(curr);
//             profit += curr;
//             vis[curr] = 1;
//         }
//         cout << "Profit: " << profit << endl;
//         cout << endl;
//         m[i].pop();
//     }
//     cout << profit << endl;

//     for (auto i : ans)
//         cout << i << " ";
//     return ans;
// }
bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}
vector<pair<int, int>> jobSequencing(vector<pair<int, int>> jobs)
{
    sort(jobs.begin(), jobs.end(), compare);

    map<int, pair<int, int>> m;
    int high = INT_MIN;
    for (auto i : jobs)
    {
        int j = i.first;
        if (high < j)
            high = j;
        while (j > 0)
        {
            if (m.find(j) == m.end())
            {
                m[j] = i;
                break;
            }
            --j;
        }
    }

    vector<pair<int, int>> seq(high);
    for (auto c : m)
    {
        seq[c.first - 1] = c.second;
        // cout << c.second.first << " " << c.second.second << endl;
    }

    for (auto i : seq)
        cout << i.first << " " << i.second << endl;

    return seq;
}

int main()
{
    vector<pair<int, int>> jobs;

    jobs = {{4, 70}, {1, 80}, {1, 30}, {1, 100}};
    jobs = {{2, 50}, {2, 60}, {3, 20}, {3, 30}};
    jobs = {{4, 50}, {1, 5}, {1, 20}, {5, 10}, {5, 80}};

    jobSequencing(jobs);
    return 0;
}