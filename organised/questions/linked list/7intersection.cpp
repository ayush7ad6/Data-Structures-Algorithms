/**
 * Definition for singly-linked list.

 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    int countNodes(ListNode *head)
    {
        if (!head)
            return 0;

        int count = 0;
        while (head)
        {
            head = head->next;
            ++count;
        }

        return count;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int m = countNodes(headA);
        int n = countNodes(headB);

        int diff = abs(m - n);

        for (int i = 0; i < diff; ++i)
        {
            if (m > n)
            {
                headA = headA->next;
            }
            else
                headB = headB->next;
        }

        while (headA && headB && headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }

        if (headA == headB)
            return headA;

        return NULL;
    }
};