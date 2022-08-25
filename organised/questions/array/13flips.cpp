#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> minimumFlips(vector<int> &arr)
{
    vector<vector<pair<int, int>>> index(2);

    int zero = arr[0] == 0 ? 1 : 0;
    int curr = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (zero == 0 && arr[i] == 0)
        {
            index[1].push_back({curr, i - 1});
            curr = i;
            zero = 1;
        }
        else if (zero == 1 && arr[i] == 1)
        {
            index[0].push_back({curr, i - 1});
            curr = i;
            zero = 0;
        }
    }
    if (zero == 0)
        index[1].push_back({curr, arr.size() - 1});
    else
        index[0].push_back({curr, arr.size() - 1});

    // for (auto i : index[0])
    //     cout << i.first << " " << i.second << endl;

    // cout << endl;
    // for (auto i : index[1])
    //     cout << i.first << " " << i.second << endl;

    if (index[0].size() > index[1].size())
        return index[1];

    return index[0];
}

void minimumFlips(vector<int> &arr, int flag = 1)
{
    // if (arr[0] != arr[arr.size() - 1])
    //     return;

    for (int i = 1; i < arr.size(); ++i)
    {
        if (arr[i] != arr[i - 1])
        {
            if (arr[i] != arr[0])
                cout << "From " << i << " to ";
            else
                cout << i - 1 << endl;
        }
    }
    if (arr[0] != arr[arr.size() - 1])
        cout << arr.size() - 1 << endl;
}
int main()
{
    // vector<int> arr = {1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1};
    vector<int> arr = {1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0};
    // vector<int> arr = {1, 1, 1, 1, 1};

    // vector<pair<int, int>> ans;
    // ans = minimumFlips(arr);

    // for (auto i : ans)
    // {
    //     cout << "Flip from " << i.first << " to " << i.second << endl;
    // }

    minimumFlips(arr, 1);

    return 0;
}