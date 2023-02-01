#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int value;
    Node* left;
    Node* right;
    Node* parent;
};

Node* make_node (int number)
{
    Node* sm = new Node;
    sm -> value = number;
    sm -> left = nullptr;
    sm -> right = nullptr;
    sm->parent = nullptr;
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

Node* mini(Node* cur)
{
    if (cur->left == nullptr) return cur;
    return mini(cur->left);
}

Node* maxi(Node* cur)
{
    if (cur->right == nullptr) return cur;
    return maxi(cur->right);
}

Node* del (Node* root, int num)
{
    if (root == nullptr) return root;
    if (num < root->value) root->left = del(root->left, num);
    else if (num > root->value) root->right = del(root->right, num);
    else if (root->left != nullptr && root->right != nullptr)
    {
        root->value = mini(root->right)->value;
        root->right = del(root->right, root->value);
    }
    else
    {
        if (root->left != nullptr) root = root->left;
        else if (root->right != nullptr) root = root->right;
        else root = nullptr;
    }
    return root;
}

Node* ser(Node* root, int num)
{
    if (root == nullptr || num == root->value) return root;
    if (num < root->value) return ser(root->left, num);
    else return ser(root->right, num);
}

Node* next(Node* root, int num)
{
    Node* suc = nullptr;
    Node* cur = root;
    while (cur != nullptr)
    {
        if (cur->value > num)
        {
            suc = cur;
            cur = cur->left;
        }
        else cur = cur->right;
    }
    return suc;
}

Node* prev(Node* root, int num)
{
    Node* suc = nullptr;
    Node* cur = root;
    while (cur != nullptr)
    {
        if (cur->value < num)
        {
            suc = cur;
            cur = cur->right;
        }
        else cur = cur->left;
    }
    return suc;
}
};

int main()
{
    Tree tree;
    Node* Root = nullptr;
    string inp;
    int val;
    while(cin>>inp)
    {
        if (inp == "insert")
        {
            cin>>val;
            Node* smth = new Node;
            smth = make_node(val);
            if (Root == nullptr) Root = smth;
            if (Root != smth && tree.ser(Root, val) == nullptr && Root != nullptr) tree.ins(Root, smth);
        }
        else if (inp == "delete")
        {
            cin>>val;
            if (Root != nullptr && tree.ser(Root, val) != nullptr && Root->value == val) Root = tree.del(Root, val);
            else if (Root != nullptr && tree.ser(Root, val) != nullptr) tree.del(Root, val);
        }
        else if (inp == "exists")
        {
            cin>>val;
            if (tree.ser(Root, val)!= nullptr && Root != nullptr) cout<<"true"<<endl;
            else cout<<"false"<<endl;
        }
        else if (inp == "next")
        {
            cin>>val;
            if (tree.next(Root, val) != nullptr && Root != nullptr) cout<<tree.next(Root, val)->value<<endl;
            else cout<<"none"<<endl;
        }
        else
        {
            cin>>val;
            if (tree.prev(Root, val) != nullptr && Root != nullptr) cout<<tree.prev(Root, val)->value<<endl;
            else cout<<"none"<<endl;
        }
    }
    return 0;
}
