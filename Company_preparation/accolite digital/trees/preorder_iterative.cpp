

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

vector<int> levelorder(struct Node *root, vector<int> &pre)
{

    if (!root)
        return pre;

    stack<Node *> q;
    q.push(root);
    while (!q.empty())
    {

        Node *node = q.top();
        q.pop();
        pre.push_back(node->data);
        if (node->right != NULL)
            q.push(node->right);
        if (node->left != NULL)
            q.push(node->left);
    }
    return pre;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    vector<int> pre;
    levelorder(root, pre);

    for (auto x : pre)
    {
        cout << x << " ";
    }

    return 0;
}