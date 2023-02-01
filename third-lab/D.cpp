#include <bits/stdc++.h>
//#include <stdlib.h>


using namespace std;

struct Node {
  int value;
  Node* prev;
  Node* next;
};

struct Stack
{
    int Size;
    Node *first = nullptr;
    Node *last = nullptr;

int Top()
{
    return last->value;
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
    }
    else {
            last->next = a;
            last = a;
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
    Stack numbers;
    int answer = 0,x,y;
    string inp;
    string cur="";
    getline(cin, inp);
    for (int i = 0; i < inp.length(); i ++)
    {
        if (isdigit(inp[i])) {
                cur += inp[i];
        }
        else{
            if (cur != ""){
                int x = stoi(cur);
                numbers.Push(x);
            }
            cur = "";
            if (inp[i] == '+')
            {
                x = numbers.Top();
                numbers.Pop();
                y = numbers.Top();
                numbers.Pop();
                numbers.Push(x + y);
            }
            if (inp[i] == '-')
            {
                x = numbers.Top();
                numbers.Pop();
                y = numbers.Top();
                numbers.Pop();
                numbers.Push((x - y)*-1);
            }
            if (inp[i] == '*')
            {
                x = numbers.Top();
                numbers.Pop();
                y = numbers.Top();
                numbers.Pop();
                numbers.Push(x * y);
            }
        }
    }
    cout<<numbers.Top();
    return 0;
}
