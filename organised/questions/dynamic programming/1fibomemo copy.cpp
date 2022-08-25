#include <iostream>
#include <vector>

using namespace std;
int tabulation[1000] = {0, 1};
int fibo(int n)
{
    for (int i = 2; i <= n; ++i)
    {
        tabulation[i] = tabulation[i - 1] + tabulation[i - 2];
    }

    return tabulation[n];
}

int main()
{

    cout << fibo(50);
    return 0;
}