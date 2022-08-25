/*
    Count distinct elements in every k sized window
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> countDistinctinKwindow(vector<int> &arr, int k)
{
    unordered_map<int, int> hash;
    vector<int> distinct;

    for (int i = 0; i < k; ++i)
    {
        hash[arr[i]]++;
    }

    distinct.push_back(hash.size());
    // hash.clear();

    for (int i = k; i < arr.size(); ++i)
    {
        hash[arr[i - k]]--;
        if (hash[arr[i - k]] == 0)
            hash.erase(arr[i - k]);

        hash[arr[i]]++;
        distinct.push_back(hash.size());
    }

    for (auto i : distinct)
        cout << i << " ";

    return distinct;
}

int main()
{
    vector<int> arr = {1, 2, 1, 3, 4, 3, 3};
    int k = 4;
    countDistinctinKwindow(arr, k);
    return 0;
}