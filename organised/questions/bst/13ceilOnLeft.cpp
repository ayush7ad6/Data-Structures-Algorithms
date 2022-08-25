#include <iostream>
#include <set>
#include <vector>

using namespace std;

void ceilOnLeft(vector<int> &nums)
{
    set<int> s;

    for (auto &i : nums)
    {
        if (s.lower_bound(i) != s.end())
            cout << *s.lower_bound(i) << " ";
        else
            cout << "-1 ";
        s.insert(i);
    }
}

int main()
{
    // vector<int> arr = {2, 8, 30, 15, 25, 12};
    // vector<int> arr = {30, 20, 10};
    vector<int> arr = {10, 20, 30};

    ceilOnLeft(arr);
    return 0;
}