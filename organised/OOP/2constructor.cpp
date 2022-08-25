#include <iostream>

using namespace std;

class Test
{
    int x;

public:
    Test()
    {
        cout << "Default constructor\n";
    }
    Test(int x) : x(x)
    {
        // this->x = x;
        cout << "Parameterised\n";
    }
};
class Test2
{
    Test t;

public:
    // Test2()
    // {
    //     cout << "Default\n";
    // }
    Test2(Test a) : t(a)
    {
        cout << "parametetrised\n";
    }
};

int main()
{
    Test t1(1);
    Test2 t(t1);

    return 0;
}