
struct Node
{
    int data;
    Node* next;
    Node(int a)
    {
        data = a;
        next = NULL;
    }
};

void printList(Node *head)                  //print LL
{

    while(head!=NULL)                       //using head itself won't affect!
    {
        cout<<head->data<<" ";
        head = head->next;
    }

}


void printRecList(Node *head)               //recursive print though iterative is better
{
    if(head == NULL)
        return;

    cout<<head->data<<" ";
    printRecList(head->next);
}

int searchList(Node *head, int key)        //return position of key
{
    int p = 1;
    while(head!=NULL)
    {
        if(head->data == key)
            return p;
        head = head->next;
        ++p;
    }
    return -1;
}


int rsearchList(Node *head, int key,int p = 1)        //same but recursive
{
    if(head==NULL)
        return -1;
    if(head->data == key)
        return p;
    else
    {
        rsearchList(head->next,key,p+1);
    }

}


Node *insertBegin(Node *head, int x)            //insert in the beginning
{
    Node *temp = new Node(x);
    temp->next = head;
    //head->next = NULL;
    return temp;
}

Node *insertEnd(Node *head, int x)               //insert at the end
{
    if(head == NULL)
    {
      head->data = x;
      head->next = NULL;
      return head;
    }
    Node *curr = head;
    while(curr->next!=NULL)
    {
        curr = curr->next;
    }
    Node *tmp = new Node(x);
    curr->next = tmp;

    return head ;

}

Node *delHead(Node *head)               //delete head
{
    if(head == NULL)
        return NULL;

    Node *tmp = head->next;
    delete head;
    return tmp;
}


Node *delEnd(Node *head)                 //delete last Node
{
    if(head == NULL)
        return NULL;

    if(head->next == NULL)
    {
        delete head;
        head = NULL;
        return head;
    }

    Node *curr = head;
    while(curr->next->next!=NULL)
        curr = curr->next;

    delete curr->next;
    curr->next = NULL;

    return head;
}



Node *insertPos(Node *head, int pos, int x)         //insert at a particular position
{
    Node *tmp = head;
    int c = 1;
    if(pos==1)
        return insertBegin(head,x);

    while(tmp!=NULL && c!=(pos-1))
    {
        tmp = tmp->next;
        ++c;
    }
    if(pos == c+1)
    {
        Node *curr = new Node(x);
        curr->next = tmp->next;
        tmp->next = curr;
    }
    return head;
}


Node *insertSort(Node *head, int key)
{
    Node *tmp = new Node(key);
    //cout<<"C1: "<<key<<endl;
    if(head == NULL)
    {
        //cout<<"NULL: "<<key<<endl;
        return tmp;
    }


    if(head->data>key)
    {
        //cout<<"insertBegin: "<<key<<endl;
        return insertBegin(head, key);
    }


    Node *curr = head;

    while(curr->next!=NULL && curr->next->data<key)   //the order of conditions matters!! UGH!!!
     {
         //cout<<"LOOP: "<<key;
         curr = curr->next;
     }
     //cout<<endl;

    tmp->next = curr->next;
    curr->next = tmp;

    return head;
}

void printMid(Node *head)                       //print middle element efficient method
{

    if(head == NULL)
        return;

    Node *fast = head;
    Node *slow = head;

    while(fast!=NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    cout<<slow->data;

    return;
}


//print nth element from the end

Node *reverseList(Node *head)               //REVERSE A LINKED LIST
{
    if(head == NULL)
        return head;

    Node *nhead = NULL;
    while(head!=NULL)
    {
        nhead = insertBegin(nhead, head->data);
        head = head->next;
    }

    return nhead;
}

Node *rRevList(Node *head)                  //reverse recursively M1
{
    if(head == NULL || head->next == NULL)
        return head;

    Node *rest_head = rRevList(head->next);
    Node *rest_tail = head->next;
    rest_tail->next = head;
    head->next = NULL;
    return rest_head;
}


Node *rrRevList(Node *curr, Node *prev = NULL)              //recursive reverse method2
{
    if(curr == NULL)
        return prev;
    Node *next = curr->next;
    curr->next = prev;
    //prev = curr;

    return rrRevList(next,curr);
}


Node *rmDuplicate(Node *head)           //remove duplicate MINE MEMORY LEAKS
{

    if(head == NULL)
        return head;

    Node *temp = new Node(head->data);

    head = head->next;

    Node *hh = temp;

    while(head!=NULL)
    {
        cout<<head->data<<" ";
        if(temp->data != head->data)
        {

            Node *add = new Node(head->data);
            temp->next = add;
            temp = add;


        }
        head = head->next;

    }
    return hh;
}


void RemoveDup(Node *head)              //remove duplicates efficient SEE VOID!!
{
    if(head == NULL)
        return;

    Node *curr = head;
    while(curr->next!=NULL)
    {
        if(curr->data == curr->next->data)
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else
        {
            curr = curr->next;
        }
    }
}
