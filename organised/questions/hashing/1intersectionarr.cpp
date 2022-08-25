#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int intersectionOfArrays(vector<int> &a, vector<int> &b)
{
    unordered_set<int> hash;

    for (auto i : a)
        hash.insert(i);

    int res = 0;
    for (auto i : b)
    {
        if (hash.find(i) != hash.end())
        {
            cout << i << " ";
            ++res;
            hash.erase(i);
        }
    }
    cout << endl;

    return res;
}

int main()
{
    vector<int> a = {10, 15, 20, 15, 30, 30, 5};
    vector<int> b = {30, 5, 30, 80};

    cout << intersectionOfArrays(a, b);
    return 0;
}