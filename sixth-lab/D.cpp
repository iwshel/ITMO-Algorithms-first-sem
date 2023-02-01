#include <bits/stdc++.h>

using namespace std;

struct Node
{
    string value;
    bool f1;
    bool f2;
    bool f3;
    Node* left;
    Node* right;
    Node* parent;
    int balance;
    int height;
};

Node* make_node (string number)
{
    Node* sm = new Node;
    sm -> value = number;
    sm -> left = nullptr;
    sm -> right = nullptr;
    sm->parent = nullptr;
    sm -> f1 = false;
    sm -> f2 = false;
    sm -> f3 = false;
    return sm;
}
struct Tree
{
int Height(Node* p) {
    if (p == nullptr) {
        return 0;
    }
    return p->height;
}

void FixHeight(Node* p) {
    p->height = max(Height(p->left), Height(p->right)) + 1;
}

int BFactor(Node* p) {
    return Height(p->left) - Height(p->right);
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
    if (BFactor(p) == -2) {
    if (BFactor(p->right) == 1) {
      p = BigLeft(p);
    }
    else {
      p = LeftRotate(p);
    }
  }
  else if (BFactor(p) == 2) {
    if (BFactor(p->left) == -1) {
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
Node* ser(Node* root, string num)
{
    if (root == nullptr || num == root->value) return root;
    if (num < root->value) return ser(root->left, num);
    else return ser(root->right, num);
}
void obh(Node* cur, int& cou1, int& cou2, int& cou3, Node* root)
{
    if (cur == nullptr) return;
    if (cur->f1 && !cur->f2 && !cur->f3) cou1 += 3;
    else if (!cur->f1 && cur->f2 && !cur->f3) cou2 += 3;
    else if (!cur->f1 && !cur->f2 && cur->f3) cou3 += 3;
    else if (cur->f1 && !cur->f2 && cur->f3)
    {
        cou1++;
        cou3++;
    }
    else if (cur->f1 && cur->f2 && !cur->f3)
    {
        cou1++;
        cou2++;
    }
    else if (!cur->f1 && cur->f2 && cur->f3)
    {
        cou2++;
        cou3++;
    }
    obh(cur->right, cou1, cou2, cou3, root);
    obh(cur->left, cou1, cou2, cou3, root);
    if (cur->value == root->value) {
            cout<<cou1<<" "<<cou2<<" "<<cou3;
    return;
    }

}
};

int main()
{
    Tree tree;
    Node* Root = nullptr;
    string inp;
    int amount;
    cin>>amount;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < amount; j++)
        {
            cin>>inp;
            Node* smth = new Node;
            smth = make_node(inp);
            if (Root == nullptr) {
                smth->f1 = true;
                Root = smth;
            }
            else {
                //tree.Balance(Root);
                Node *s = tree.ser(Root, inp);
                if (s == nullptr) {
                    if (i == 0) smth->f1 = true;
                    else if (i == 1) smth->f2 = true;
                    else smth->f3 = true;
                    Root = tree.insrt(Root, smth);
                } else if (s != nullptr) {
                    if (i == 0) s->f1 = true;
                    else if (i == 1) s->f2 = true;
                    else s->f3 = true;
                }
            }
        }
    }
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    tree.obh(Root,c1,c2,c3, Root);
    return 0;
}
