#include <iostream>
#include <vector>

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
    Stack q;
    vector<int>answer;
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
        else answer.push_back(q.Pop());
    }
    for(int i = 0; i < answer.size(); i++) {
        if (i < answer.size()-1) cout<<answer[i]<<'\n';
        else cout<<answer[i];
    }
    return 0;
}
