//#include <iostream>

#include "header.h"
#include "hashing.h"

//using namespace::std;

int main()
{
    hashlp a(7);
    a.insert(49);
    a.insert(50);
    a.insert(63);
    a.insert(64);
    a.insert(69);
    a.insert(68);
    a.getSize();
    a.remove(69);
    a.getSize();
    a.insert(99);

    a.insert(99);

    return 0;
}


