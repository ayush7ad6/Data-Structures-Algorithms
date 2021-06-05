#include <iostream>
#include <string>
#include "header.h"




using namespace std;

bool anagram(string s1, string s2)   //to check if two strings are permutations of each other
{
    int count[256] = {0};
    if(s1.length()!=s2.length())
        return false;

    for(int i = 0; i<s1.length(); ++i)
    {
        count[s1[i]]++;
    }

    for(int i = 0; i<s2.length(); ++i)
    {
        count[s2[i]]--;
    }

    for(int i = 0; i<256; ++i)
        if(count[i]!=0)
            return false;

    return true;
}


int leftindex(string s)             //index for the leftmost repeating character
{
    int res = INT_MAX;
    int count[256];
    for(int i = 0; i<256; ++i)
        count[i] = -1;

    for(int i = 0; i<s.length(); ++i)
    {
        if(count[s[i]]==-1)
            count[s[i]] = i;
        else
            res = min(res, count[s[i]]);
    }

    return (res == INT_MAX)?-1:res;
}


int nonrepeat(string s)        //index for the leftmost non repeating character
{
    int res = INT_MAX;
    int count[256];
    for(int i = 0; i<256; ++i)
        count[i] = -1;

    for(int i = 0; i<s.length(); ++i)
    {
        if(count[s[i]]==-1)
            count[s[i]] = i;
        else
            count[s[i]] = INT_MAX;

        //res = min(res, count[s[i]]);
    }
    for(int i = 0; i<256; ++i)
    {
        if(count[i]>0)
            res = min(res, count[i]);

    }

    return (res == INT_MAX)?-1:res;
}


int lexirank(string s)         //rank
{
    int rank = 1;
    int n = s.length();
    int f = fact(n);

    int count[256] = {0};

    for(int i = 0; i<n; ++i)
        count[s[i]]++;

    for(int i = 0; i<256; ++i)
        count[i] = count[i] + count[i-1];

    for(int i = 0; i<n; ++i)
    {
        f = f/(n-i);
        rank = rank + f*count[s[i] - 1];

        for(int j = 0; j<256; ++j)
            count[s[j]]--;
    }

    return rank;
}


bool aresame(int c[], int cc[])            //compare two
{
    for(int i = 0; i<256; ++i)
    {
        if(c[i]!=cc[i])
            return false;
    }

    return true;
}

bool anagrampresent(string txt, string pat)    //substring continuous present
{
    int counttxt[256] = {0};
    int countpat[256] = {0};

    for(int i = 0; i<pat.length(); ++i)
    {
        counttxt[txt[i]]++;
        countpat[pat[i]]++;
    }

    for(int i = pat.length(); i<txt.length(); ++i)
    {
        if(aresame(counttxt, countpat))
            return true;

        counttxt[txt[i]]++;

        counttxt[txt[i - pat.length()]]--;

    }
    if(aresame(counttxt, countpat))
            return true;

    return false;
}

bool rotation(string s1, string s2)        //check it two strings are rotations
{
    if(s1.length()!= s2.length())
        return false;

    s1 = s1 + s1;
    return (s1.find(s2) != string::npos);
}

