#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node* left;
    Node* right;
    int value;
    int position;
    int balance;
    int height;
};

unsigned char height(Node* p)
{
	return p?p->height:0;
}

int fixheight(Node* p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = max(hl, hr) + 1;
	return hr - hl;
}

void balance(Node* cur)
{
    if (cur -> left != nullptr) balance(cur->left);
    if (cur -> right != nullptr) balance(cur->right);
    cur->balance = fixheight(cur);
}

Node* make_node (int number)
{
    Node* sm = new Node;
    sm -> value = number;
    sm -> left = nullptr;
    sm -> right = nullptr;
    sm -> balance = 0;
    sm -> height = 0;
    return sm;
}

int height2(Node* cur)
{
    if (cur == nullptr) return 0;
    else
    {
        int right_height = height2(cur->right);
        int left_height = height2(cur->left);
        cur->balance = right_height - left_height;
        return 1 + max(right_height, left_height);
    }
}

int main()
{
    int amount;
    cin>>amount;
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
    height2(tree[0]);
    for (int i = 0; i < amount; i++) cout<<tree[i]->balance<<'\n';
    return 0;
}
