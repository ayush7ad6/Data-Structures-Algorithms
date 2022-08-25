#include <bits/stdc++.h>

using namespace std;
class Base_class
{
public:
    void show()
    {
        cout << "Apni Kaksha base" << endl;
    }
};
class Derived_class : public Base_class
{
public:
    void show()
    {
        cout << "Apni Kaksha derived" << endl;
    }
};
int main()
{
    Base_class *b;
    Derived_class d;
    b = &d;
    d.show();
    b->show(); // prints the content of show() declared in derived class
    return 0;
}