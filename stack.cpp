#include <stack>
#include <string>
#include <iostream>
using namespace std;

bool matching(char a, char b)      //for bracket matching and code efficiency
{
    return ((a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']'));
}

bool isBalanced(string str)        //balanced bracket checking using stack STL
{
    stack<int> s;
    for(int i = 0; i<str.length(); ++i)
    {
        if(str[i] == '(' || str[i]=='{' || str[i]=='[')
            s.push(str[i]);
        else
        {
            if(s.empty()==true)
                return false;
            else if(matching(s.top(),str[i])==true)
                s.pop();
            else
                return false;
        }


        //if(s[i] == ')' || s[i]=='}' || s[i]==']')

    }
    return (s.empty()==true);

}




string isWhat(char c)              //operator or operand
{
    if(c>96 && c<123)
        return "operand";
    else
        return "operator";
}


bool isHigh(char s, char c)        //precedence high
{
    if((s=='*' || s=='/') && (c=='+' || c=='-'))
        return true;
    if((s=='^') && (c=='*' || c=='/' || c=='+' || c=='-'))
        return true;
    if((s=='+' && c=='-') ||(s=='-' || c=='+') || (s=='*' && c=='/') || (s=='/' && c=='*'))
        return false;
    if(c=='(')
        return true;
    return false;
}


void toPostfix(string str)       //conversion
{
    stack<int> tack;
    //string res = "";

    for(int i = 0; i<str.length(); ++i)
    {
        //cout<<endl<<i<<str[i]<<endl;
        if(isWhat(str[i])=="operand")
            cout<<str[i];
        else
        {
            if(tack.empty()==true || str[i]=='(')
                tack.push(str[i]);


            else if(str[i]==')')
            {
                while(tack.empty()!=true && tack.top()!='(')
                {
                    cout<<(char)tack.top();
                    tack.pop();
                }
                tack.pop();
            }


            else if(isHigh(str[i],tack.top())==true)
                tack.push(str[i]);


            else if(isHigh(str[i],tack.top())==false)
            {

                while(tack.empty()!=true && isHigh(str[i],tack.top())!=true)
                {
                    cout<<(char)tack.top();
                    tack.pop();
                }
                tack.push(str[i]);
            }

        }
    }

    while(tack.empty()==false)
    {
        //res = res + (char)tack.top();
        cout<<(char)tack.top();
        tack.pop();
    }
    //return res;
}





int evaluate(int op1, int op2, char op)        //evaluate arithmetic
{
    switch(op)
    {
        case '+': return op2+op1;
                    break;
        case '-': return op2-op1;
                    break;
        case '*': return op2*op1;
                    break;
        case '/': return op2/op1;
                    break;
    }
    return 0;
}


int EPostfix(string s)             //evaluate postfix expression
{
    int res;
    stack<int> stck;
    for(int i = 0; i<s.length(); ++i)
    {
        if(isWhat(s[i])=="operand")
        {
            if(stck.empty()==true)
                stck.push(s[i]);
        }
        else
        {
            int op1, op2;
            op1 = stck.top();
            op2 = stck.top();
            res = evaluate(op1,op2,s[i]);
            stck.push(res);

        }
    }
    res = stck.top();
    stck.pop();
    return res;

}
