#include <iostream>
#include <vector>

using namespace std;

bool isSafe(string s, int i, int l, int r)
{
    if (l != 0 && s[i] == 'B' && s[l - 1] == 'A')
        return false;

    if (r == l + 1 && s[i] == 'A' && s[l] == 'B' || r == l + 1 && l == i && s[r] == 'B' && s[l] == 'A')
        return false;

    return true;
}
void permutation(string s, int l, int r)
{
    if (l == r)
    {
        cout << s << endl;
        return;
    }

    for (int i = l; i <= r; ++i)
    {
        if (isSafe(s, i, l, r))
        {
            swap(s[i], s[l]);
            permutation(s, l + 1, r);
            swap(s[i], s[l]);
        }
        else
        {
            cout << s << " skipped: " << l << " " << i << endl;
        }
    }
}

int main()
{
    string s = "ABC";

    permutation(s, 0, 2);
}