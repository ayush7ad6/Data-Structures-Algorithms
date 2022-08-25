#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool subarraywithzerosum(vector<int> &arr)
{
    unordered_map<int, int> m;

    m[0] = 1;
    int pref = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        pref += arr[i];

        if (m[pref - 0] != 0)
            return true;

        m[pref] = 1;
    }

    return false;
}

int main()
{
    // vector<int> arr = {6, 4, -2, -2, 8};
    vector<int> arr = {4, 2, 0, 1, 6};

    cout << subarraywithzerosum(arr);
    return 0;
}