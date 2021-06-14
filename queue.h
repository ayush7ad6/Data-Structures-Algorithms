#include <list>
#include <queue>

struct ll
{
    int data;
    ll *next;
    ll(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Queue
{
    ll *front, *rear;
    int size;
    Queue()
    {
        front = NULL;
        rear = NULL;
        size = 0;
    }


    void enqueue(int x)
    {
        ll *temp = new ll(x);
        size++;

        if(front == NULL)
        {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }

    void dequeue()
    {
        if(front == NULL)
        {
            cout<<"Underflow"<<endl;
            return;
        }

        ll *temp = front;
        front = front->next;
        if(front == NULL)
            rear = NULL;
        delete(temp);
        size--;
    }

    int getSize()
    {
        return size;

    }

    void pQueue()
    {
        if(front==NULL)
        {
            cout<<"Underflow"<<endl;
            return;
        }
        ll *temp = front;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

