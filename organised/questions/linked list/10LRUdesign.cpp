#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;

    ListNode(int x)
    {
        val = x;
        next = NULL;
        prev = NULL;
    }

    ListNode(int x, ListNode *next)
    {
        val = x;
        this->next = next;
        prev = NULL;
    }
    ListNode(int x, ListNode *next, ListNode *prev) : val(x), next(next), prev(prev)
    {
    }
};

class LRU
{
    unordered_map<int, pair<int, ListNode *>> hash;
    int cap;
    int size;
    ListNode *head;
    ListNode *tail;

public:
    LRU(int capacity) : cap(capacity)
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void show(bool h)
    {
        for (auto i : hash)
        {
            cout << i.first << " " << i.second.first << "-" << i.second.second->val << endl;
        }

        cout << endl;
    }
    void show()
    {
        if (!head)
            return;

        ListNode *temp = head;
        while (head)
        {
            cout << head->val << " ";

            head = head->next;
        }
        head = temp;
        cout << endl;
    }

    void bringToFront(ListNode *node)
    {
        if (node == head)
            return;
        ListNode *temp = head;
        while (temp != node)
        {
            temp = temp->next;
        }

        ListNode *prev = temp->prev;
        if (temp == tail)
            tail = prev;

        ListNode *next = temp->next;
        if (prev)
            prev->next = next;
        if (next)
            next->prev = prev;

        temp->next = head;
        temp->prev = NULL;
        head->prev = temp;

        head = temp;
    }

    void removeLRU()
    {
        int key = tail->val;
        hash.erase(key);

        ListNode *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;

        delete (temp);
    }

    void addNode(ListNode *node)
    {
        if (head == NULL)
        {
            head = node;
            tail = head;
            return;
        }

        node->next = head;
        node->prev = NULL;
        head->prev = node;
        head = node;
    }

    int get(int key)
    {
        if (hash.find(key) == hash.end())
        {
            cout << "\nNOT FOUND\n";
            return -1;
        }

        bringToFront(hash[key].second);
        cout << hash[key].first << endl;
        return hash[key].first;
    }

    void push(int key, int value)
    {
        if (hash.find(key) != hash.end())
        {
            hash[key].first = value;
            bringToFront(hash[key].second);
            return;
        }

        if (size == cap)
        {
            ListNode *node = new ListNode(key);
            addNode(node);
            hash[key] = {value, node};
            // cout << "--" << tail->val << "--";
            removeLRU();
        }
        else
        {
            ListNode *node = new ListNode(key);
            addNode(node);
            hash[key] = {value, node};
            ++size;
        }
    }
};

int main()
{

    LRU cache(3);
    cache.push(1, 1);
    cache.push(2, 2);
    cache.push(3, 3);
    cache.push(4, 4);
    cache.push(5, 5);
    cache.show();
    cout << endl;
    cache.show(true);
    cache.get(1);
    cache.show();
    cout << endl;
    cache.push(5, 5);
    cache.show();
    cache.push(2, 2);
    cache.show();

    cache.push(10, 10);
    cache.show();
    cache.show(true);

    // show(head);
    return 0;
}