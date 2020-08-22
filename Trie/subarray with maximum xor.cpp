#include <iostream>
using namespace std;

class Node
{
public:
    Node* left;
    Node* right;
};

class Trie
{

    Node* root;

public:
    Trie()
    {
        root = new Node();
        // root->left=NULL;
        // root->right=NULL;
    }

    void insert(int n)
    {
        Node* temp = root;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (n >> i) & 1;
            if (bit == 0)
            {
                if (temp->left == NULL)
                {
                    temp->left = new Node();
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = new Node();
                }
                temp = temp->right;
            }
        }
    }

    int max_xor_helper(int value)
    {
        Node* temp = root;
        int ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (value >> i) & 1;
            if (bit == 0)
            {
                if (temp->right != NULL)
                {
                    temp = temp->right;
                    ans += (1 << i);
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->left != NULL)
                {
                    temp = temp->left;
                    ans += (1 << i);
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
        return ans;
    }

    int max_xor(int input[], int n)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            insert(input[i]);
            int subans = max_xor_helper(input[i]);
            //cout<<subans<<" ";
            ans = max(ans, subans);
        }
        return ans;
    }
};

int main() {

    int input[] = {8, 1, 2, 12, 7, 6};
    int n = sizeof(input) / sizeof(int);

    //cumulative xor
    int cxor[100];

    int x = input[0];
    cxor[0] = x;

    for (int i = 1; i < n; i++)
    {
        x ^= input[i];
        cxor[i] = x;
    }

    Trie t;
    cout << t.max_xor(cxor, n);

}
