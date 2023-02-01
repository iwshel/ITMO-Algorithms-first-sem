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
        cur->balance = left_height - right_height;
        return 1 + max(right_height, left_height);
    }
}

Node* LeftRotate(Node* t) {
  Node* p = t->right;
  t->right = p->left;
  p->left = t;
  height2(t);
  height2(p);
  return p;
}

Node* RightRotate(Node* t) {
  Node* p = t->left;
  t->left = p->right;
  p->right = t;
  height2(t);
  height2(p);
  return p;
}

Node* BigLeft(Node* avl) {
  avl->right = RightRotate(avl->right);
  return LeftRotate(avl);
}

Node* BigRight(Node* avl) {
  avl->left = LeftRotate(avl->left);
  return RightRotate(avl);
}

Node* Balance(Node* p) {
    height2(p);
    if (p->balance == -2) {
    if (p->right->balance == 1) {
      p = BigLeft(p);
    }
    else {
      p = LeftRotate(p);
    }
  }
  else if (p->balance == 2) {
    if (p->left->balance == -1) {
      p = BigRight(p);
    }
    else {
      p = RightRotate(p);
    }
  }
  //if (p->balance >)
    //all_balance(p);
    return p;
}


void all_balance(Node*& cur) {
    if(cur == nullptr) return;
    Node* left = cur->left;
    Node* right = cur->right;
    if (left != nullptr) all_balance(left);
    if (right != nullptr) all_balance(right);
    cur = Balance(cur);
}

Node* insrt(Node* root, Node* val)
{
    if (root == nullptr)
    {
        return val;
    }
    if (val->value < root->value)
    {
        root->left = insrt(root->left, val);
    }
    else
    {
        root->right = insrt(root->right, val);
    }
    return Balance(root);
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
        smth = make_node(p);
        tree.push_back(smth);
        sons.push_back(make_pair(l, r));
    }
    int x;
    cin>>x;
    if (amount == 0) {
        cout<<'1'<<'\n';
        cout<<x<<" "<<'0'<<" "<<'0';
        return 0;
    }
    for (int i = 0; i < amount; i++)
    {

        if (sons[i].first != 0) tree[i]->left = tree[sons[i].first - 1];
        if (sons[i].second != 0) tree[i]->right = tree[sons[i].second - 1];
    }
    height2(tree[0]);
    Node* ins = new Node;
    ins = make_node(x);
    Node* Root = tree[0];
    Root = insrt(Root, ins);
    all_balance(Root);
    int ko = 1;
    new_indx(Root, ko);
    cout<<amount + 1<<"\n";
    print_tree(Root);
    return 0;
}
