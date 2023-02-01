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
void fill_bin_tree (Node* cur, int& counter)
{
    if (cur -> left != nullptr) fill_bin_tree(cur->left, counter);
    cur->value = counter;
    counter ++;
    if (cur -> right != nullptr) fill_bin_tree(cur->right, counter);
}
int main()
{
    int amount;
    cin>>amount;
    vector<pair<int,int>> sons;
    vector<Node*> tree;
    for (int i = 0; i < amount; i++)
    {
        int l, r;
        cin>>l>>r;
        Node* smth = new Node;
        smth = make_node(0);
        tree.push_back(smth);
        sons.push_back(make_pair(l, r));
    }
    for (int i = 0; i < amount; i++)
    {

        if (sons[i].first != 0) tree[i]->left = tree[sons[i].first - 1];
        if (sons[i].second != 0) tree[i]->right = tree[sons[i].second - 1];
    }
    int cou = 1;
    fill_bin_tree(tree[0], cou);
    for (int i = 0; i < amount; i++) cout<<tree[i]->value<<" ";
    return 0;
}
