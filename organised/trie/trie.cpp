#include <iostream>
#include <vector>

using namespace std;
const int ALPHABET_SIZE = 26;
struct TrieNode
{
    TrieNode *children[ALPHABET_SIZE];
    bool isEnd;

    TrieNode()
    {
        isEnd = false;
        for (int i = 0; i < ALPHABET_SIZE; ++i)
            children[i] = NULL;
    }
};

void insert(TrieNode *root, string &key)
{
    // cout << "Adding '" << key << "' to the dictionary\n";
    TrieNode *curr = root;
    for (auto ch : key)
    {
        // cout << ch << " ";
        int index = ch - 'a';
        if (curr->children[index] == NULL)
        {
            curr->children[index] = new TrieNode();
        }
        curr = curr->children[index];
    }

    curr->isEnd = true;
}
void *createDict(TrieNode *root, vector<string> &dict)
{
    TrieNode *curr = root;
    for (auto key : dict)
    {
        insert(root, key);
    }
}

bool search(TrieNode *root, string key)
{
    TrieNode *curr = root;
    for (auto ch : key)
    {
        int index = ch - 'a';
        if (curr->children[index] == NULL)
            return false;
        curr = curr->children[index];
    }

    return curr->isEnd;
}
int main()
{
    TrieNode *root = new TrieNode();
    vector<string> dict = {"bad", "bat", "geek", "geeks", "cat", "cut", "batman"};
    createDict(root, dict);

    cout << search(root, "bat") << endl;
    cout << search(root, "batman") << endl;
    cout << search(root, "batmans") << endl;
    cout << search(root, "batmans") << endl;

    return 0;
}