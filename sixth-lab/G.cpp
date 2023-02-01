#include <bits/stdc++.h>

using namespace std;

int get_sum(vector<int>& tree,int l, int r, int v, int tl, int tr) {
    if (l <= tl && tr <= r)
    {
        return tree[v];
    }
    if (tr < l || r < tl)
    {
        return 0;
    }
    int tm = (tl + tr) / 2;
    return get_sum(tree, l, r, v * 2 + 1, tl, tm) + get_sum(tree, l, r, v * 2 + 2, tm + 1, tr);
}

void update(vector<int>& numbers, vector<int>& tree, int idx, int val, int v, int tl, int tr) {
    if (idx <= tl && tr <= idx) {
        numbers[idx] = val;
        tree[v] = val;
        return;
    }
    if (tr < idx || idx < tl) {
        return;
    }
    int tm = (tl + tr) / 2;
    update(numbers, tree, idx, val, v * 2 + 1,     tl,     tm);
    update(numbers, tree, idx, val, v * 2 + 2, tm + 1, tr);
    tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
}

int main()
{
    int amount;
    cin>>amount;
    int amount_str;
    cin>>amount_str;
    vector<int> tree (amount, 0);
    vector<int> tree_result(amount*4, 0);
    char smth;
    int l, r;
    for (int i = 0; i < amount_str; i++)
    {
        cin>>smth>>l>>r;
        if (smth == '+')
        {
            tree[l-1] += r;
            update(tree, tree_result, l-1, tree[l-1], 0, 0, amount);
        }
        else if (smth == '-')
        {
            tree[l-1] -= r;
            if (tree[l-1] < 0) tree[l-1] = 0;
            update(tree, tree_result, l-1, tree[l-1], 0, 0, amount);
        }
        else if (smth == '?')
        {
            cout<<get_sum(tree_result, l-1, r-1, 0, 0, amount)<<'\n';
        }
    }
    return 0;
}
