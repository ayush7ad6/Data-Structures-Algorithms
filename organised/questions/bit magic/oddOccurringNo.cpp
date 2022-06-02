#include <bits/stdc++.h>

using namespace std;

void oddOccurring(vector<int> arr)
{
    if (arr.size() == 0)
        return;
    if (arr.size() == 1)
    {
        cout << arr[0] << endl;
        return;
    }
    int a = 0;
    for (int i = 0; i < arr.size(); ++i)
        a = a ^ arr[i];

    cout << a << " is the odd occurring number\n";
    return;
}
/*
variation of the quesiton is to find the missing number in the array with range 1 to n;
*/
int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 3, 3, 4};
    oddOccurring(arr);
    return 0;
}