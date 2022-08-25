#include <iostream>
#include <string>

using namespace std;

bool anagramSearch(string anagram, string text)
{
    int n = anagram.size();
    int m = text.size();
    if (n > m)
        return false;

    int pFreq[26] = {0};
    int tFreq[26] = {0};

    for (int i = 0; i < n; ++i)
    {
        pFreq[anagram[i] - 'a']++;
        tFreq[text[i] - 'a']++;
        // cout << pFreq[anagram[i] - 'a'] << " ";
    }
    if (equal(pFreq, pFreq + 26, tFreq))
        return true;
    for (int i = n; i < m; ++i)
    {
        tFreq[text[i - n] - 'a']--;
        tFreq[text[i] - 'a']++;
        if (equal(pFreq, pFreq + 26, tFreq))
            return true;
    }

    return false;
}

int main()
{
    string t = "geeksforgeeks";
    string p = "rseek";

    cout << anagramSearch(p, t);
    return 0;
}