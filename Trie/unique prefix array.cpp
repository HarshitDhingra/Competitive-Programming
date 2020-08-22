#include <bits/stdc++.h>
using namespace std;

vector<string>ans;

class Node
{
public:

    char data;
    unordered_map<char, pair<int, Node*>>children;
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
                temp->children[ch].first++;
                temp = temp->children[ch].second;
            }
            else
            {
                Node* n = new Node(ch);
                temp->children[ch].first = 1;
                temp->children[ch].second = n;
                temp = n;
            }
        }
        temp->terminal = true;
    }

    string find(char *word)
    {
        Node* temp = root;
        string s;
        for (int i = 0; word[i] != '\0'; i++)
        {
            char ch = word[i];
            s += ch;
            if (temp->children[ch].first == 1)
            {
                return s;
            }
            else
            {
                temp = temp->children[ch].second;
            }
        }
        return "null";
    }

};

int main() {

    Trie t;

    char words[][10] = {"cobra", "cobras", "dog", "dove", "duck"};
    char w[10];
    cin >> w;

    for (int i = 0; i <= 4; i++)
    {
        t.insert(words[i]);
    }

    for (int i = 0; i <= 4; i++)
    {
        ans.push_back(t.find(words[i]));
    }

    for (auto i : ans) {
        cout << i << " ";
    }



}
