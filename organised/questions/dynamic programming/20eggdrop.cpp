#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int trials = INT_MAX;
int eggDrop(int f, int e, int tf)
{
    if (f == 0 || f == 1)
        return f;
    if (e == 1)
        return f;
    int trials = INT_MAX;
    for (int i = 1; i <= f; ++i)
    {
        int res = max(eggDrop(i - 1, e - 1, tf), eggDrop(f - i, e, tf));
        trials = min(trials, res);
    }

    return trials + 1;
}

int eggDrop(int n, int k)
{
    // If there are no floors,
    // then no trials needed.
    // OR if there is one floor,
    // one trial needed.
    if (k == 1 || k == 0)
        return k;

    // We need k trials for one
    // egg and k floors
    if (n == 1)
        return k;

    int min = INT_MAX, x, res;

    // Consider all droppings from
    // 1st floor to kth floor and
    // return the minimum of these
    // values plus 1.
    for (x = 1; x <= k; x++)
    {
        res = max(eggDrop(n - 1, x - 1), eggDrop(n, k - x));
        if (res < min)
            min = res;
    }

    return min + 1;
}

int eggDropDP(int f, int e)
{
    int dp[f + 1][e + 1];
    for (int i = 0; i <= e; ++i)
    {
        dp[0][i] = 0;
        dp[1][i] = 1;
    }

    for (int i = 0; i <= f; ++i)
    {
        dp[i][1] = i;
        dp[i][0] = 0;
    }

    for (int i = 2; i <= f; ++i)
    {
        for (int egg = 2; egg <= e; ++egg)
        {
            dp[i][egg] = INT_MAX;
            for (int k = 1; k <= i; ++k)
            {
                int res = 1 + max(dp[k - 1][egg - 1], dp[i - k][egg]);
                dp[i][egg] = min(dp[i][egg], res);
            }
            // dp[i][egg] += 1;
        }
    }

    for (int i = 0; i <= f; ++i)
    {
        for (int j = 0; j <= e; ++j)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    return dp[f][e];
}

// int eggDropDP(int n, int k)
// {
//     /* A 2D table where entry
//     eggFloor[i][j] will represent
//     minimum number of trials needed for
//     i eggs and j floors. */
//     int eggFloor[n + 1][k + 1];
//     int res;
//     int i, j, x;

//     // We need one trial for one floor and 0
//     // trials for 0 floors
//     for (i = 1; i <= n; i++)
//     {
//         eggFloor[i][1] = 1;
//         eggFloor[i][0] = 0;
//     }

//     // We always need j trials for one egg
//     // and j floors.
//     for (j = 1; j <= k; j++)
//         eggFloor[1][j] = j;

//     // Fill rest of the entries in table using
//     // optimal substructure property
//     for (i = 2; i <= n; i++)
//     {
//         for (j = 2; j <= k; j++)
//         {
//             eggFloor[i][j] = INT_MAX;
//             for (x = 1; x <= j; x++)
//             {
//                 res = 1 + max(
//                               eggFloor[i - 1][x - 1],
//                               eggFloor[i][j - x]);
//                 if (res < eggFloor[i][j])
//                     eggFloor[i][j] = res;
//             }
//         }
//     }
//     for (int i = 0; i <= n; ++i)
//     {
//         for (int j = 0; j <= k; ++j)
//             cout << eggFloor[i][j] << " ";
//         cout << endl;
//     }
//     // eggFloor[n][k] holds the result
//     return eggFloor[n][k];
// }
int main()
{
    int trials = INT_MAX;
    int f = 10;
    int e = 2;
    // for (int i = 1; i <= f; ++i)
    // {
    //     int itr = eggDrop(i, f, e);
    //     trials = min(trials, itr);
    // }

    cout << eggDrop(e, f) << endl;
    cout << eggDrop(f, e, f) << endl;
    cout << eggDropDP(f, e) << endl;

    // cout << trials;

    return 0;
}