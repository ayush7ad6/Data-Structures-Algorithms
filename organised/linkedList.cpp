#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node *next;
    int val;

    Node(int x)
    {
        val = x;
        next = NULL;
    }

    Node(int x, Node *n)
    {
        val = x;
        next = n;
    }
};

Node *insertB(Node *head, int val)
{
    if (head == NULL)
        return new Node(val);

    Node *temp = new Node(val);
    temp->next = head;
    return temp;
}

Node *insertE(Node *head, int val)
{
    if (head == NULL)
        return new Node(val);

    Node *temp = head;
    while (temp->next)
        temp = temp->next;

    Node *n = new Node(val);

    temp->next = n;
    return head;
}

Node *delF(Node *head)
{
    if (head == NULL)
        return head;
    Node *temp = head;
    Node *nhead = head->next;

    delete (temp);

    return nhead;
}

Node *delE(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *temp = head;
    while (temp->next->next)
    {
        temp = temp->next;
    }

    Node *toDel = temp->next;
    temp->next = NULL;
    delete (toDel);

    return head;
}

Node *insertAtK(Node *head, int val, int k)
{
    if (k == 1)
        return insertB(head, val);

    int count = 1;
    Node *temp = head;

    while (count != k - 1 && temp)
    {
        ++count;
        temp = temp->next;
    }

    Node *newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}
void showLL(Node *head)
{
    if (head == NULL)
        return;
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}