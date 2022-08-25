#include <iostream>

using namespace std;

int add(int a)
{
    return a;
}

double add(double a)
{
    return a + 10;
}

int main()
{
    cout << add(1);
    cout << endl
         << add(1);
    return 0;
}