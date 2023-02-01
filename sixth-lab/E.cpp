#include <bits/stdc++.h>

using namespace std;

struct Node
{
  int value;
  Node* left;
  Node* right;
  int balance;
  int height;
};

Node* make_node (int number)
{
  Node* sm = new Node;
  sm -> value = number;
  sm -> left = nullptr;
  sm -> right = nullptr;
  sm ->balance = 0;
  sm ->height = 1;
  return sm;
}
struct Tree
{
  int BFactor(Node* cur) {
    return Height(cur -> right) - Height(cur -> left);
  }

  int Height(Node* cur) {
    if (cur == nullptr) {
      return 0;
    } else {
      return cur->height;
    }
  }

  void FixHeight(Node* cur) {
    cur -> height = 1 + max(Height(cur -> left), Height(cur -> right));
  }

  Node* LeftRotate(Node* t) {
    Node* p = t->right;
    t->right = p->left;
    p->left = t;
    FixHeight(t);
    FixHeight(p);
    return p;
  }

  Node* RightRotate(Node* t) {
    Node* p = t->left;
    t->left = p->right;
    p->right = t;
    FixHeight(t);
    FixHeight(p);
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
    FixHeight(p);
    if (BFactor(p) == 2) {
      if (BFactor(p->right) < 0) {
        p = BigLeft(p);
      }
      else {
        p = LeftRotate(p);
      }
    }
    else if (BFactor(p) == -2) {
      if (BFactor(p->left) > 0) {
        p = BigRight(p);
      }
      else {
        p = RightRotate(p);
      }
    }
    return p;
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
    else if (val->value > root->value)
    {
      root->right = insrt(root->right, val);
    }
    return Balance(root);
  }
  Node* ser(Node* root, int num)
  {
    if (root == nullptr || num == root->value) return root;
    if (num < root->value) return ser(root->left, num);
    return ser(root->right, num);
  }

  Node* maxi(Node* cur)
  {
    if (cur->right == nullptr) return cur;
    return maxi(cur->right);
  }

  Node* deletemin(Node* cur) {
    if(cur->right == nullptr) return cur->left;
    cur->right = deletemin(cur->right);
    return Balance(cur);
  }

  Node* del (Node* root, int num)
  {
    if (root == nullptr) return root;
    if (num < root->value) root->left = del(root->left, num);
    else if (num > root->value) root->right = del(root->right, num);
    else
    {
      if (root->left == nullptr && root->right != nullptr)
      {
        root = root->right;
      }
      else if (root->left != nullptr && root->right == nullptr)
      {
        root = root->left;
      }
      else if (root->left == nullptr && root->right == nullptr) root = nullptr;
      else {
        Node *temp = maxi(root->left);
        temp->left = deletemin(root->left);
        temp->right = root->right;
        root->value= temp->value;
        root->right = del(root->right, temp->value);
        return Balance(temp);
      }
    }
    if (root == nullptr) return root;
    return Balance(root);
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int amount;
  cin>>amount;
  Tree tree;
  Node* Root = nullptr;
  char que;
  int val;
  Node* ser;
  Node* smth;
  for (int i = 0; i < amount; i++)
  {
    cin>>que>>val;
    smth = make_node(val);
    ser = tree.ser(Root, val);
    if (que == 'A')
    {
      if (Root == nullptr)
      {
        Root = smth;
      }
      else
      {
        if (ser == nullptr)
        {
          Root = tree.insrt(Root, smth);
        }
      }
      cout<<tree.BFactor(Root)<<"\n";
    }
    else if (que == 'D')
    {
      if (Root != nullptr && ser != nullptr)
      {
        Root = tree.del(Root, val);
      }
      if (Root == nullptr) cout<<"0"<<"\n";
      else cout<<tree.BFactor(Root)<<"\n";
    }
    else
    {
      if (ser != nullptr) cout<<'Y'<<"\n";
      else cout<<'N'<<"\n";
    }
  }
  return 0;
}
