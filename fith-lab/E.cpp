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
void ins (Node* root, Node* what)
{
    while (root != nullptr)
    {
        if (what->value > root->value)
        {
            if (root->right != nullptr) root = root->right;
            else
            {
                what->parent = root;
                root->right = what;
                break;
            }
        }
        else if (what->value < root->value)
        {
            if (root->left != nullptr) root = root->left;
            else
            {
                what->parent = root;
                root->left = what;
                break;
            }
        }
    }
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
                Node *s = tree.ser(Root, inp);
                if (s == nullptr) {
                    if (i == 0) smth->f1 = true;
                    else if (i == 1) smth->f2 = true;
                    else smth->f3 = true;
                    tree.ins(Root, smth);
                } else if (s != nullptr) {
                    if (i == 0) s->f1 = true;
                    else if (i == 1) s->f2 = true;
                    else s->f3 = true;
                }
            }
            //if (s!= nullptr) cout<<s->f1<<" "<<s->f2<<" "<<s->f3<<endl;
        }
    }
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    tree.obh(Root,c1,c2,c3, Root);
    return 0;
}
