#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node* left;
    Node* right;
    int value;
    int position;
};

Node* make_node (int number)
{
    Node* sm = new Node;
    sm -> value = number;
    sm -> left = nullptr;
    sm -> right = nullptr;
    return sm;
}
int height (Node* cur)
{
    if (cur == nullptr) return 0;
    else
    {
        return 1 + max(height(cur->left), height(cur->right));
    }
}
int main()
{
    int amount;
    cin>>amount;
    if (amount == 0)
    {
        cout<<'0';
        return 0;
    }
    vector<pair<int,int>> sons;
    vector<Node*> tree;
    for (int i = 0; i < amount; i++)
    {
        int p, l, r;
        cin>>p>>l>>r;
        Node* smth = new Node;
        smth = make_node(p);
        tree.push_back(smth);
        sons.push_back(make_pair(l, r));
    }
    for (int i = 0; i < amount; i++)
    {

        if (sons[i].first != 0) tree[i]->left = tree[sons[i].first - 1];
        if (sons[i].second != 0) tree[i]->right = tree[sons[i].second - 1];
    }
    cout<<height(tree[0]);
    return 0;
}
