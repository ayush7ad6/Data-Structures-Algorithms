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

bool cycleDetection(ListNode *head)
{
    if (!head)
        return false;
    ListNode *slow(head), *fast(head);

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

void removeCycle(ListNode *head)
{
    if (!head)
        return;

    ListNode *slow(head), *fast(head);

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (slow != fast)
        return;

    slow = head;

    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = NULL;
}

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

int main()
{
    ListNode *head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);
    head->next->next->next->next->next = new ListNode(60);
    head->next->next->next->next->next->next = head->next->next->next;

    cout << cycleDetection(head);
    removeCycle(head);
    cout << endl
         << cycleDetection(head);
    cout << endl;
    show(head);
    return 0;
}