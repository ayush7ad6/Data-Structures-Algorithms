#include <iostream>
#include <vector>

using namespace std;

int subsetSum(vector<int> &arr, int sum, int i = 0)
{
    if (i == arr.size())
        return sum == 0;

    return subsetSum(arr, sum - arr[i], i + 1) + subsetSum(arr, sum, i + 1);
}

int main()
{

    vector<int> arr = {10,
                       20,
                       15}; //, 2, 3, 6};
    int sum = 25;
    cout << subsetSum(arr, sum);

    return 0;
}