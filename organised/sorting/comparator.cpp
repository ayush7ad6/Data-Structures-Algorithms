#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

class mycmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }
};

int main()
{

    vector<pair<int, int>> arr = {{1, 2}, {2, 3}, {2323, 231}, {1, 111}};
    // sort(arr.begin(), arr.end(), cmp);

    priority_queue<pair<int, int>, vector<pair<int, int>>, mycmp> pq(arr.begin(), arr.end());

    while (pq.empty() == false)
    {
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }
    return 0;
}