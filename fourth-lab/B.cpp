#include <bits/stdc++.h>

using namespace std;

void heapify(vector <int> &numbers, int amount, int i)
{
    int large = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < amount && numbers[left] > numbers[large]) large = left;
    if (right < amount && numbers[right] > numbers[large]) large = right;
    if (large != i)
    {
        swap(numbers[i], numbers[large]);
        heapify(numbers, amount, large);
    }
}

void heap_sort(vector <int> &numbers, int amount)
{
    for (int i = amount/2 - 1; i >= 0; i--) heapify(numbers, amount, i);
    for (int i = amount-1; i >= 0; i--)
    {
        swap(numbers[0], numbers[i]);
        heapify(numbers, i, 0);
    }
}

int main()
{
    int amount;
    cin>>amount;
    vector <int> numbers (amount);
    for (int i = 0; i < amount; i++) cin>>numbers[i];
    heap_sort(numbers, amount);
    for (int i = 0; i < amount; i++) cout<<numbers[i]<<" ";
    return 0;
}
