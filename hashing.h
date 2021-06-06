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









class hashlp          //hashing using open addressing LINEAR PROBING USED
{
private:
    int *arr;
    int cap;
    int size;

public:
    hashlp(int a)                    //constructor to assign capacity
    {
        cap = a;
        size = 0;
        for(int i = 0; i<cap; ++i)
            arr[i] = -1;
        cout<<"Hash with capacity "<<a<<" created!\n";
    }
    int getSize()
    {
        cout<<size<<endl;
        return size;
    }

    int hash(int key)                  //hash function LP
    {
        return key%cap;
    }

    bool insert(int key)                //insert
    {
        if(size==cap)
        {
            cout<<"I'm full!\n";
            return false;
        }

        int h = hash(key);
        int i = h;

        while(arr[i]!=-1 && arr[i]!=-2 && arr[i]!=key)
            i = (i + 1) % cap;

        if(arr[i]==key)
        {
            cout<<key<<" already present"; return false;
        }
        else
        {
            arr[i] = key;
            size++;
            cout<<key<<" inserted!\n";
            return true;
        }

    }

    bool search(int key)                //search function
    {
        int h = hash(key);
        int i = h;
        while(arr[i]!=-1)
        {
            if(arr[i] == key)
            {
                cout<<key<<" found!\n";
                return true;
            }
            i = (i + 1) % cap;
            if(i == h)
            {
                cout<<key<<" not found!\n";
                return false;
            }
        }
        cout<<key<<" not found!\n";
        return false;
    }

    bool remove(int key)                //remove function
    {
        if(size == 0)
        {
            cout<<"I'm empty!\n";
            return false;
        }

        int h = hash(key);
        int i = h;

        while(arr[i]!=-1)
        {
            if(arr[i]==key)
            {
                arr[i] = -2;
                size--;
                cout<<key<<" removed!\n";
                return true;
            }
            i = (i + 1) % cap;
            if(i == h)
            {
                cout<<"Can't delete keys not present!\n";
                return false;
            }
        }
        cout<<"Can't delete keys not present!\n";
        return false;

    }

    void show()                     //print values present
    {
        if(size == 0)
        {
            cout<<"Nothing in hash!";
            return;
        }

        for(int i = 0; i<cap; ++i)
        {
            if(arr[i] == -1 || arr[i]==-2)
                continue;

            cout<<arr[i]<<'\t';
        }
        cout<<endl;
    }
};




