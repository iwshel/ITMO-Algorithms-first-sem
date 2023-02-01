#include <bits/stdc++.h>

using namespace std;

int main()
{
    int amount, number, place;
    vector <int> numbers;
    cin>>amount;
    for (int i = 0; i < amount; i++)
    {
        int x;
        cin>>x;
        numbers.push_back(x);
    }
    cin>>number>>place;
    numbers.push_back(number);
    for (int i = amount; i > place-1; i--)
    {
        swap(numbers[i], numbers[i-1]);
    }
    for (int i = 0; i <= amount; i++) cout<<numbers[i]<<" ";
    return 0;
}
