#include <list>




struct chaining
{
    int bucket;
    list <int> *table;
    chaining(int b)
    {
        bucket = b;
        table = new list<int> [bucket];
    }
    int hash(int key)
    {
        return key % bucket;
    }

    void insert(int key)
    {
        int i = hash(key);
        table[i].push_back(key);
    }

    bool search(int key)
    {
        int i = hash(key);
        for(auto x : table[i])
            if(x==key)
                return true;
        return false;
    }

    void remove(int key)
    {
        int i = hash(key);
        table[i].remove(key);
    }
};




