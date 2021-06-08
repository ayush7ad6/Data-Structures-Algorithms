//#include <iostream>

#include "header.h"
#include "hashing.h"
#include "linkedlist.h"

//using namespace::std;

int main()
{
    Node *head = NULL;
    head = insertSort(head,4);
    head = insertSort(head,33);
    head = insertSort(head,34);
    head = insertSort(head, 30);

    printList(head);

    RemoveDup(head);
    cout<<endl;
    printList(head);


    return 0;
}


