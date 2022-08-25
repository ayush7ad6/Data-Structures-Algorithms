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

ListNode *swapPairs(ListNode *head)
{
    if (head == NULL)
        return head;

    ListNode *dummy = new ListNode(0, head);
    ListNode *curr(dummy);

    while (curr->next && curr->next->next)
    {
        ListNode *first = curr->next;
        ListNode *second = curr->next->next;
        // cout << curr->val << " " << first->val << " " << second->val << endl;
        curr->next = second;
        first->next = second->next;
        second->next = first;

        curr = first;
    }

    return dummy->next;
}

ListNode *swapPairsRec(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *temp = head->next;
    ListNode *next = temp->next;
    temp->next = head;

    head->next = swapPairsRec(next);

    return temp;
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(50);
    // head->next->next->next->next->next = new ListNode(60);

    head = swapPairsRec(head);
    show(head);
    return 0;
}