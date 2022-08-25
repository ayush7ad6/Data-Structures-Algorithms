#include <iostream>
#include <vector>

using namespace std;

void segregate(vector<int> &arr)
{
    int typeOneInd = -1;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] & 1)
            continue;
        swap(arr[i], arr[++typeOneInd]);
        // ++typeOneInd;
    }
}

void segregate(vector<int> &arr, bool hoares)
{
    int i = -1, j = arr.size();

    while (true)
    {
        do
        {
            ++i;
        } while (arr[i] % 2 == 0);

        do
        {
            --j;
        } while (arr[j] % 2);

        if (i >= j)
            return;

        swap(arr[i], arr[j]);
    }
}
int main()
{
    vector<int> arr = {5, 4, 3, 2};
    segregate(arr, true);
    for (auto i : arr)
        cout << i << " ";
    return 0;
}