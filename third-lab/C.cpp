#include <bits/stdc++.h>

using namespace std;

struct Node {
  char value;
  Node* prev;
  Node* next;
};

struct Stack
{
    Node *first = nullptr;
    Node *last = nullptr;

char Top()
{
    return last->value;
}

bool Is_empty()
{
    if (first == nullptr && last == nullptr) return 1;
    else return 0;
}

void Push(char num)
{
    Node *a = new Node;
    a->value = num;
    a->prev = last;
    a->next = NULL;
    if (first == nullptr && last == nullptr) {
            first = a;
            last = a;
    }
    else {
            last->next = a;
            last = a;
    }
}
void Pop()
{
    //char num = last->value;
    if (first == last){
        first = nullptr;
        last = nullptr;
    }
    else {
    last = last->prev;
    }
    //return num;
}
void printq()
{
    Node *current = first;
    while(current != NULL)
    {
        cout<<current->value<<endl;
        current = current->next;
    }
}
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string current;
    vector<int> answer;
    while(cin>>current)
    {
        bool flag = false;
        Stack scob;
        for (int i = 0; i < current.length(); i++)
        {
        if (current[i] == '(' || current[i] == '[') scob.Push(current[i]);
        else{
            if (scob.Is_empty())
            {
                flag = true;
                break;
            }
            if (current[i] == ')' && scob.Top() != '(') {
                flag = true;
                break;
            }
            if (current[i] == ']' && scob.Top() != '[') {
                flag = true;
                break;
            }
            else scob.Pop();
        }
        }
        if (!scob.Is_empty()) flag = true;
        if (flag) answer.push_back(0);
        else answer.push_back(1);
    }
    for(int i = 0; i < answer.size(); i++)
    {
        if (i < answer.size()-1) {
            if (answer[i]==0) cout<<"NO";
            else cout<<"YES";
            cout<<endl;
        }
        else
        {
            if (answer[i]==0) cout<<"NO";
            else cout<<"YES";
        }
    }
    return 0;
}
