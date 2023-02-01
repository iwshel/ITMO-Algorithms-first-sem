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
    int indx;
};

Node* make_node (int number, int i)
{
    Node* sm = new Node;
    sm -> value = number;
    sm -> left = nullptr;
    sm -> right = nullptr;
    sm -> balance = 0;
    sm -> height = 0;
    sm -> indx = i+1;
    return sm;
}

int height2(Node* cur)
{
    if (cur == nullptr) return 0;
    else
    {
        int right_height = height2(cur->right);
        int left_height = height2(cur->left);
        cur->balance = left_height - right_height;
        return 1 + max(right_height, left_height);
    }
}

Node* LeftRotate(Node* t) {
  Node* p = t->right;
  t->right = p->left;
  p->left = t;
  height2(p);
  return p;
}

Node* RightRotate(Node* t) {
  Node* p = t->left;
  t->left = p->right;
  p->right = t;
  height2(p);
  return p;
}

Node* BigLeft(Node* avl) {
  avl->right = RightRotate(avl->right);
  return LeftRotate(avl);
}

void new_indx(Node* root, int& in)
{
    if (root == nullptr) return;
    root->indx = in;
    in++;
    new_indx(root->left, in);
    new_indx(root->right, in);
}

void print_tree(Node* tree) {
  if (tree != nullptr) {
    cout << tree->value <<" ";
    if (tree->left != nullptr) cout << tree->left->indx << ' ';
    else cout<<"0"<<" ";
    if (tree->right != nullptr) cout << tree->right->indx << '\n';
    else cout<<"0"<<"\n";
    print_tree(tree->left);
    print_tree(tree->right);
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
        smth = make_node(p, i);
        tree.push_back(smth);
        sons.push_back(make_pair(l, r));
    }
    for (int i = 0; i < amount; i++)
    {

        if (sons[i].first != 0) tree[i]->left = tree[sons[i].first - 1];
        if (sons[i].second != 0) tree[i]->right = tree[sons[i].second - 1];
    }
    height2(tree[0]);
    Node* Root = tree[0];
    if (Root->right->balance == 1)
    {
        Root = BigLeft(Root);
    }
    else
    {
        Root = LeftRotate(Root);
    }
    int ko = 1;
    new_indx(Root, ko);
    cout<<amount<<"\n";
    int k = 0;
    print_tree(Root);
    return 0;
}
