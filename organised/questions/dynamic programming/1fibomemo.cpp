#include <iostream>
#include <vector>

using namespace std;
int memo[1000];
int fibo(int n)
{
    if (memo[n] == -1)
    {
        int res;
        if (n == 0 || n == 1)
            res = n;
        else
        {
            res = fibo(n - 1) + fibo(n - 2);
        }
        memo[n] = res;
    }
    return memo[n];
}

int main()
{
    for (int i = 0; i < 1000; ++i)
        memo[i] = -1;

    cout << fibo(40);
    return 0;
}