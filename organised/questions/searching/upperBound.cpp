#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int upperBound(vector<int> &, int);
int lowerBound(vector<int> &, int);

int numMatchingSubseq(string s, vector<string> &words)
{
    vector<vector<int>> hash(26);

    for (int i = 0; i < s.length(); ++i)
    {
        hash[s[i] - 'a'].push_back(i);
        cout << hash[s[i] - 'a'].back() << " ";
    }

    int count = 0;
    for (auto a : words)
    {
        int flag = 1;
        int prev = -1;
        cout << a << "- ";
        for (auto ch : a)
        {
            auto v = hash[ch - 'a'];
            auto ub = upper_bound(begin(v), end(v), prev);
            cout << *ub << " ";
            if (ub == end(v))
            {
                flag = 0;
                break;
            }
            prev = *ub;
        }
        cout << endl;
        if (flag)
            cout << a << " ";
        count += flag;
    }

    return count;
}
int upperBound(vector<int> &nums, int n)
{
    int f = 0, r = nums.size() - 1;
    int mid;

    while (f <= r)
    {
        mid = (f + r) / 2;

        if (nums[mid] <= n)
            f = mid + 1;
        else if (nums[mid] > n)
        {
            if (mid == 0 || nums[mid - 1] <= n)
                return mid;
            r = mid - 1;
        }
    }

    return -1;
}

int lowerBound(vector<int> &nums, int n)
{
    int f = 0, r = nums.size() - 1;
    int mid;

    while (f <= r)
    {
        mid = (f + r) / 2;

        if (nums[mid] >= n)
            r = mid - 1;
        else
        {
            if (mid == nums.size() - 1 || nums[mid + 1] >= n)
                return mid;

            f = mid + 1;
        }
    }

    return -1;
}

int main()
{
    // vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8};
    // vector<int> a = {1};
    // int n = 1;
    // int ub = upperBound(a, n);
    // int lb = lowerBound(a, n);
    // cout << a[lb] << " " << a[ub] << endl;

    string s = "abcde";
    vector<string> words = {"a", "bb", "acd", "ace"};

    cout << endl
         << endl
         << numMatchingSubseq(s, words);

    // vector<int> a = {};
    // int u = upper_bound(a.begin(), a.end(), 1) - a.begin();
    // cout << u;
    return 0;
}