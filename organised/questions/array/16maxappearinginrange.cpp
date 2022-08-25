#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxAppearinginRange(vector<int> &start, vector<int> &end)
{
    int n = *max_element(end.begin(), end.end());
    cout << "KKK" << n << endl;
    vector<int> arr(n + 2, 0);

    for (auto i = 0; i < start.size(); ++i)
    {
        arr[start[i]]++;
        arr[end[i] + 1]--;
    }

    int maxFreq = 0;
    int element = -1;
    for (int i = 1; i < n + 2; ++i)
    {
        arr[i] += arr[i - 1];
        if (arr[i] > maxFreq)
        {
            maxFreq = arr[i];
            element = i;
        }
    }
    // for (auto i = 0; i < n + 2; ++i)
    //     cout << arr[i] << " ";

    // cout << endl;

    return element;
}

int main()
{
    vector<int> start = {1, 2, 3};
    vector<int> end = {3, 5, 7};

    cout << maxAppearinginRange(start, end);
    return 0;
}