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

ListNode *reverse(ListNode *head)
{
    ListNode *curr(head), *next(NULL), *prev(NULL);

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return curr;
}
void show(ListNode *head)
{
    if (head == NULL)
        return;

    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
}

ListNode *reverseGroup(ListNode *head, int k)
{
    if (head == NULL)
        return head;

    ListNode *curr(head), *next(NULL), *prev(NULL);

    int count = 0;
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        ++count;
    }

    head->next = reverseGroup(next, k);

    return prev;
}

ListNode *reverseGroupI(ListNode *head, int k)
{
    ListNode *curr(head), *next(head), *prev(NULL), *prevEnd(NULL);
    ListNode *nhead(NULL);
    while (next != NULL)
    {
        int count = 0;
        while (curr != NULL && count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            ++count;
        }
        if (nhead == NULL)
        {
            nhead = prev;
        }
        else
        {
            prevEnd->next = prev;
        }
        prevEnd = head;
        prev = head;
        head->next = curr;
        head = curr;
    }

    return nhead;
}
int main()
{
    ListNode *head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);
    head->next->next->next->next->next = new ListNode(60);

    show(head);
    cout << endl;
    head = reverseGroupI(head, 3);
    cout << endl;
    // head = reverse(head, NULL);
    show(head);
    return 0;
}