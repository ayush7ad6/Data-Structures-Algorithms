#include <iostream>

using namespace std;

class Person
{
protected:
    int id;
    string name;

public:
    void setID(int id)
    {
        this->id = id;
    }

    void setName(string name)
    {
        this->name = name;
    }
};

class Student : public Person
{
private:
    int marks;

public:
    void print()
    {
        cout << id << " " << name << " " << marks << endl;
    }
};

int main()
{
    Student s1;
    s1.setID(1);
    s1.setName("ayush");
    s1.print();
    return 0;
}