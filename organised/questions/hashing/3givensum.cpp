#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twosum(vector<int> &a, int target)
{
    unordered_map<int, int> m;

    for (int i = 0; i < a.size(); ++i)
    {
        if (m.find(target - a[i]) != m.end())
            return {i, m[target - a[i]]};

        m[a[i]] = i;
    }

    return {-1, -1};
}

int main()
{
    // vector<int> a = {3, 2, 8, 15, -8};
    vector<int> a = {11, 5, 6};
    cout << twosum(a, 10)[0] << " " << twosum(a, 10)[1];
    return 0;
}