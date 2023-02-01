#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node {
    int value;
    int number;
    Node(int val, int num = 0): value(val), number(num) {};
};

struct Heap {
    vector <Node*> numbers;
    void Push(Node* num)
    {
        numbers.push_back(num);
        numbers[numbers.size()-1]->number = numbers.size()-1;
        Sift_up(numbers.size()-1);
    }
    void Pop()
    {
        if (numbers.size() == 0) cout<<'*'<<'\n';
        else
        {
            cout<<numbers[0]->value<<'\n';
            swap(numbers[0], numbers[numbers.size()-1]);
            numbers[0]->number = 0;
            numbers.pop_back();
            Sift_down(0);
        }
    }
    void Sift_up(int amount)
    {
        while(numbers[amount]->value < numbers[(amount-1)/2]->value)
        {
            if (amount > 0)
            {
                swap(numbers[amount], numbers[(amount-1)/2]);
                numbers[amount]->number = amount;
                numbers[(amount-1)/2]->number = (amount-1)/2;
                amount = (amount-1)/2;
            }
        }
    }
    void Sift_down(int amount)
    {
        while (2 * amount + 1 < numbers.size())
        {
            int left = 2 * amount + 1;
            int right = 2 * amount + 2;
            int j = left;
            if (right < numbers.size() && numbers[right]->value < numbers[left]->value) j = right;
            if (numbers[amount]->value <= numbers[j]->value) break;
            swap(numbers[amount], numbers[j]);
            numbers[amount]->number = amount;
            numbers[j]->number = j;
            amount = j;
        }
    }
};
int main()
{
    Heap que;
    unordered_map <int, Node*> values;
    string inp;
    int counter = 0;
    while (cin>>inp)
    {
        counter++;
        int num;
        int x,y;
        if (inp == "push")
        {
            cin>>num;
            Node* sm = new Node(num);
            que.Push(sm);
            pair <int, Node*> smth = {counter, sm};
            values.insert(smth);
        }
        else if (inp == "extract-min")
        {
            que.Pop();
        }
        else
        {
            cin>>x>>y;
            values[x]->value = y;
            que.Sift_up(values[x]->number);
        }
    }
    return 0;
}
