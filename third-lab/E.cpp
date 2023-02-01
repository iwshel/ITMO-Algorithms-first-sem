#include <bits/stdc++.h>

using namespace std;

struct Node {
  int value;
  int curmax;
  Node* prev;
  Node* next;
};

struct Stack
{
    int Size;
    int curmax = INT_MAX;
    Node *first = nullptr;
    Node *last = nullptr;

int maxtop()
{
    return last->curmax;
}

void Push(int num)
{
    Node *a = new Node;
    a->value = num;
    a->prev = last;
    a->next = NULL;
    if (first == nullptr && last == nullptr) {
            first = a;
            last = a;
            a -> curmax = a->value;
    }
    else {
            last->next = a;
            last = a;
            if (a->value > a->prev->curmax) a->curmax = a->value;
            else a->curmax = a->prev->curmax;
    }
}
int Pop()
{
    int num = last->value;
    if (first == last){
        first = nullptr;
        last = nullptr;
    }
    else {
    last = last->prev;
    }
    return num;
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
    Stack q;
    int amount;
    cin>>amount;
    for(int i = 0; i < amount; i++)
    {
        char sign;
        int number;
        cin>>sign;
        if (sign == '+')
        {
            cin>>number;
            q.Push(number);
        }
        if (sign == '-') q.Pop();
        if(sign == 'm') {
                string rest;
                cin>>rest;
                cout<<q.maxtop()<<'\n';
        }
    }
    return 0;
}
