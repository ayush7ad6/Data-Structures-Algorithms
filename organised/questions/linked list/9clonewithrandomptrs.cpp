#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *random;

    ListNode(int x)
    {
        val = x;
        next = NULL;
        random = NULL;
    }

    ListNode(int x, ListNode *next)
    {
        val = x;
        this->next = next;
        random = NULL;
    }
    ListNode(int x, ListNode *next, ListNode *random) : val(x), next(next), random(random)
    {
    }
};

void show(ListNode *head)
{
    if (!head)
        return;

    while (head)
    {
        cout << head->val << " ";
        if (head->random)
            cout << "random: " << head->random->val;
        cout << endl;
        head = head->next;
    }

    cout << endl;
}
ListNode *clone(ListNode *head)
{
    unordered_map<ListNode *, ListNode *> hash;

    for (auto curr = head; curr != NULL; curr = curr->next)
    {
        hash[curr] = new ListNode(curr->val + 1);
    }

    for (auto curr = head; curr != NULL; curr = curr->next)
    {
        auto cloneNode = hash[curr];
        cloneNode->next = hash[curr->next];
        cloneNode->random = hash[curr->random];
    }

    return hash[head];
}

ListNode *clone(ListNode *head, bool space = true)
{
    for (auto curr = head; curr != NULL;)
    {
        ListNode *copy = new ListNode(curr->val + 1);
        // cout << curr->val << " ";
        auto n = curr->next;
        curr->next = new ListNode(curr->val + 1);
        curr->next->next = n;
        // curr->next->next = curr->random;
        curr = n;
    }
    // cout << endl;
    // show(head);
    cout << endl;
    for (auto curr = head; curr != NULL;)
    {
        ListNode *cloneNode = curr->next;
        cloneNode->random = curr->random == NULL ? NULL : curr->random->next;
        // curr = cloneNode->next;
        // cloneNode->next = curr->next;
        curr = cloneNode->next;
    }
    // show(head);
    cout << endl;
    ListNode *nhead = head->next;
    // for (auto curr = nhead; curr->next != NULL;)
    // {
    //     curr->next = curr->next->next;
    //     curr = curr->next;
    // }

    ListNode *t = nhead;

    while (head)
    {
        head->next = t->next;
        head = t->next;
        t->next = head == NULL ? NULL : head->next;
        t = head == NULL ? NULL : head->next;
    }
    return nhead;
}
int main()
{
    ListNode *head = new ListNode(10);
    head->next = new ListNode(5);
    head->next->next = new ListNode(20);
    head->next->next->next = new ListNode(15);
    head->next->next->next->next = new ListNode(20);

    head->random = head->next->next;
    head->next->random = head->next->next->next;
    // head->next->next->random = head;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next->next->next;

    cout << endl;
    ListNode *nhead = clone(head, true);
    show(nhead);
    cout << endl
         << endl;
    show(head);
    // show(head);
    return 0;
}