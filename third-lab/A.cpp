#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int value;
  Node* next;
};

struct Queue
{
    int Size;
    Node *first = nullptr;
    Node *last = nullptr;

int Top()
{
    return first->value;
}

void Push(int num)
{
    Node *a = new Node;
    a->value = num;
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
    int num = first->value;
    if (first == last){
        first = nullptr;
        last = nullptr;
    }
    else {
    first = first->next;
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
    Queue q;
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
