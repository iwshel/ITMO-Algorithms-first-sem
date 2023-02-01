#include <bits/stdc++.h>

using namespace std;

int main()
{
    int amount;
    vector <int> numbers;
    cin>>amount;
    for (int i = 0; i < amount; i++)
    {
        int x;
        cin>>x;
        numbers.push_back(x);
    }
    for (int i = 1; i < amount; i++)
    {
        bool flag = false;
        for (int j = i; j > 0; j--)
        {
            if (numbers[j-1] > numbers[j]){
                    swap(numbers[j-1] ,numbers[j]);
                    flag = true;
            }
            else break;
        }
        if (flag)
        {
            for (int i = 0; i < amount; i++) cout<<numbers[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
