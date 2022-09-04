#include <iostream>
#include <vector>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

private:
    void insertWord(TrieNode *root, string word)
    {
        // Base Case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        // Recursive Call
        insertWord(child, word.substr(1));
    }

    bool search(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal && true;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return root->isTerminal && false;
        }
        bool ans = search(child, word.substr(1));
        return ans;
    }
    void removeWord(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = false;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // Word not found
            return;
        }
        removeWord(child, word.substr(1));

        // Remove Child Node if it is useless
        if (child->isTerminal == false)
        {
            for (int i = 0; i < 26; i++)
            {
                if (child->children[i] != NULL)
                {
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }
    }

public:
    void insertWord(string word)
    {
        insertWord(root, word);
    }

    bool search(string word)
    {
        return search(root, word);
    }

    void removeWord(string word)
    {
        removeWord(root, word);
    }
};

int main()
{
    Trie t;
    t.insertWord("and");
    t.insertWord("dot");
    t.insertWord("double");
    cout << t.search("and") << endl;
    t.removeWord("and");
    cout << t.search("and") << endl;
}