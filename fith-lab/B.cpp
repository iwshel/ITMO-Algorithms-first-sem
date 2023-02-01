#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node* left;
    Node* right;
    int value;
};

Node* make_node (int number)
{
    Node* sm = new Node;
    sm -> value = number;
    sm -> left = nullptr;
    sm -> right = nullptr;
    return sm;
}
bool is_bin_tree (Node* cur, int mini, int maxi)
{
    if (cur == nullptr) return true;
    if (cur -> value <= mini || cur -> value >= maxi) return false;
    return is_bin_tree(cur->left, mini, cur->value) && is_bin_tree(cur->right, cur->value, maxi);
}
int main()
{
    int amount;
    cin>>amount;
    if (amount == 0)
    {
        cout<<"YES";
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
    if (is_bin_tree(tree[0],INT_MIN,INT_MAX)) cout<<"YES";
    if (!is_bin_tree(tree[0],INT_MIN,INT_MAX)) cout<<"NO";
    return 0;
}
