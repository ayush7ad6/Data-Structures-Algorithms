#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }

    ListNode(int x, ListNode *next)
    {
        val = x;
        this->next = next;
    }
};

void show(ListNode *head)
{
    if (!head)
        return;

    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

ListNode *segreateEvenOdd(ListNode *head)
{
    if (!head)
        return head;
    ListNode *evenhead = new ListNode(0, head);
    ListNode *even = evenhead;
    ListNode *oddhead = new ListNode(0, head);
    ListNode *odd = oddhead;

    while (head)
    {
        // cout << head->val << "-";
        if (head->val % 2)
        {
            odd->next = head;
            odd = head;
        }
        else
        {
            even->next = head;
            even = head;
        }
        head = head->next;
    }

    odd->next = NULL;
    even->next = oddhead->next;

    // show(oddhead->next);
    // cout << endl;
    // show(evenhead->next);
    return evenhead->next;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    // head->next->next->next->next->next->next = head->next->next->next;

    head = segreateEvenOdd(head);

    show(head);
    return 0;
}