#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int coins(vector<int> coin, int sum)
{
    int count, curr = sum;
    int ans = INT_MAX;
    int tmp = 0;
    while (curr != 0)
    {
        count = 0;
        curr = sum;
        for (int i = tmp; i < coin.size(); ++i)
        {
            cout << "CURR: " << curr << endl;
            if (curr >= coin[i])
            {
                // cout << curr << ">" << coin[i] << endl;
                count += (curr / coin[i]);
                curr = curr % coin[i];
                cout << coin[i] << " " << count << " " << curr << "\n\n"
                     << endl;
            }
        }
        ++tmp;
        if (curr == 0)
            ans = min(count, ans);
    }

    cout << ans;
    return ans;
}

int main()
{
    vector<int> coin = {25, 10, 5};
    coins(coin, 30);
    return 0;
}