#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int firstPetrolStationToStart(vector<int> &petrol, vector<int> &dist)
{
    int tank = 0, d = 0;
    int s = 0;
    int curr = 0;
    vector<int> vis(petrol.size(), 0);
    while (vis[curr] == 0)
    {
        if (tank < d)
        {
            tank = 0;
            d = 0;
            s = (s + 1) % petrol.size();
            curr = s;
        }
        vis[curr] = 1;
        tank += petrol[curr];
        d += dist[curr];
        curr = (curr + 1) % petrol.size();
    }

    return curr == s ? s : -1;
}

int firstPetrolStationToStart_dq(vector<int> &petrol, vector<int> &dist)
{
    deque<int> dq;
    int start = 0, end = 0;
    int curr = 0;
    while (true)
    {
        if (curr < 0)
        {
            curr -= (petrol[dq.front()] - dist[dq.front()]);
            dq.pop_front();
        }
        else
        {
            curr += (petrol[end] - dist[end]);
            dq.push_back(end);
            end = (end + 1) % petrol.size();
        }

        if (curr >= 0 && end == dq.front())
        {
            cout << dq.empty() << endl;
            return end;
        }
    }

    return -1;
}

int main()
{
    // vector<int> p = {4, 8, 7, 4};
    vector<int> p = {8, 9, 4};
    // vector<int> d = {6, 5, 3, 5};
    vector<int> d = {5, 10, 12};
    cout << firstPetrolStationToStart_dq(p, d);
    return 0;
}
