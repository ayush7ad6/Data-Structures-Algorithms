#include <iostream>
using namespace std;

int fact(int n)
{
    if(n<1)
        return 1;
    return n * fact(n-1);
}

int tail_fact(int n, int val = 1)         //tail recursion of factorial
{
    if(n==0)
        return val;
    tail_fact(n-1, n*val);    //QUESTION in writing return and not writing return?
}

int fibo(int n)
{
    if(n<1)
        return 0;
    if(n==1)
        return 1;
    return fibo(n-1) + fibo(n-2);
}


int sum_dig(int n)
{
    if(n==0)
        return 0;
    return n%10 + sum_dig(n/10);
}
int printn(int n)
{
    if(n==1)
    {
        cout<<"1\t";
        return 1;
    }
    printn(n-1);
    cout<<n<<'\t';
}


void tail_print(int n, int k = 1)     //tail recursion of print 1 to n
{
    if(n==0)
    {
        return;
    }
    cout<<k<<"\t";
    tail_print(n-1,++k);  //k++ will cause only 1 to print! ouch
}

bool isPal(string str, int s, int e)     //palindrome checking
{
    if(s==e || s>e)
        return true;
    if(str[s]!=str[e])
        return false;
     isPal(str, ++s, --e);         //use here return and without return
}






bool comp(int a, int b)
{
    return (a < b);
}
int maxcuts(int n, int a, int b, int c)      //rope problem
{
    if(n==0)
        return 0;
    if(n<0)
        return -1;

    int res;

    if(maxcuts(n-a, a,b,c)>=maxcuts(n-b, a,b,c)&& maxcuts(n-a, a,b,c)>=maxcuts(n-c, a,b,c))
        res = maxcuts(n-a, a,b,c);
    if(maxcuts(n-b, a,b,c) >= maxcuts(n-a, a,b,c) && maxcuts(n-b, a,b,c) >= maxcuts(n-c, a,b,c))
        res = maxcuts(n-b, a,b,c);
    if(maxcuts(n-c, a,b,c) >= maxcuts(n-a, a,b,c) && maxcuts(n-c, a,b,c) >= maxcuts(n-b, a,b,c))
        res = maxcuts(n-c, a,b,c);
    //cout<<res<<" ";
    if(res<0)
        return -1;
    return (res+1);
}


void printsub(string str, string curr="", int index = 0)
{
    if(index == str.length())
    {
        cout<<curr<<" ";
        return;
    }

    printsub(str, curr, index+1);
    printsub(str, curr+str[index], index+1);
}

int toh(int n, char a='A', char b = 'B', char c = 'C', int nos=0)
{
    if(n==1)
    {
        cout<<"Move "<<n<<" from "<<a<<" to "<<c<<endl;
        ++nos;
        return nos;
    }
    toh(n-1,a,c,b,nos+2);
    cout<<"Move "<<n<<" from "<<a<<" to "<<c<<endl;
    ++nos;
    toh(n-1,b,a,c,nos+2);
}


//QUESTIONS from THEORY
bool find(int arr[], int n, int s)     //to check a num present in an array
{                                      //can't pass array directly into func C++ protocol!
    if(n==0)
        return false;
    if(arr[n-1]==s)
        return true;
    return find(arr, n-1,s);   //O(N)
}




void permu(string str, int s = 0, int e=0)  //permutations (selfmade 50%)
{
    if(e==str.length())
    {
        cout<<str<<" ";
        return;
    }

    for(int i = e; i<str.length(); ++i)
    {
        swap(str[i],str[e]);
        ++s;
        //cout<<str<<" ";
        permu(str,s,e+1);
        //swap(str[i],str[e]);
    }
}





