#include <bits/stdc++.h>
using namespace std;

class Node
{

public:

    char data;
    unordered_map<char, Node*>children;
    bool terminal;

    Node(char d)
    {
        data = d;
        terminal = false;
    }

};

class Trie
{
    Node* root;
    int count;

public:

    Trie()
    {
        root = new Node('\0');
        count = 0;
    }

    void insert(char *word)
    {
        Node* temp = root;
        for (int i = 0; word[i] != '\0'; i++)
        {
            char ch = word[i];
            if (temp->children.count(ch))
            {
                temp = temp->children[ch];
            }
            else
            {
                Node* n = new Node(ch);
                temp->children[ch] = n;
                temp = n;
            }
        }
        temp->terminal = true;
    }

    bool find(char *word)
    {
        Node* temp = root;
        for (int i = 0; word[i] != '\0'; i++)
        {
            char ch = word[i];
            if (temp->children.count(ch) == 0)
            {
                return false;
            }
            else
            {
                temp = temp->children[ch];
            }
        }
        return temp->terminal;
    }

};

int main() {

    Trie t;

    char words[][10] = {"a", "hello", "not", "news", "apple"};
    char w[10];
    cin >> w;

    for (int i = 0; i < 5; i++)
    {
        t.insert(words[i]);
    }

    if (t.find(w)) cout << "present";
    else cout << "absent";

}