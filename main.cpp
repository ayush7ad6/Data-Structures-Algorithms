//#include <iostream>

#include "header.h"
#include "hashing.h"
#include "linkedlist.h"
#include "queue.h"


//using namespace::std;

int main()
{
    queue<int> q;
    q.push(10);
    q.push(89);
    cout<<q.front()<<" "<<q.back();
    return 0;
}


