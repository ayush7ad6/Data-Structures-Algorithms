//#include <iostream>

#include "header.h"
#include "hashing.h"

//using namespace::std;

int main()
{
    struct chaining A(7);


    A.insert(10);
    A.remove(10);
    cout<<A.search(10);

    return 0;
}


