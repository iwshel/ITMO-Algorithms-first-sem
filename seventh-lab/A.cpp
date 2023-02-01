#include <bits/stdc++.h>

using namespace std;

void findLIS(vector<int>& a)
{
   int amount = a.size();
   int *prev = new int[amount];
   int *d = new int[amount];

   for (int i = 0; i < amount; i++)
   {
        d[i] = 1;
        prev[i] = -1;
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i] and d[j] + 1 > d[i])
                {
                    d[i] = d[j] + 1;
                    prev[i] = j;
                }
        }
    }
    int pos = 0;
    int length = d[0];
    for (int i = 0; i < amount; i++)
    {
        if (d[i] > length)
        {
            pos = i;
            length = d[i];
        }
    }
    vector <int> answer;
    while (pos != -1)
    {
        answer.push_back(a[pos]);
        pos = prev[pos];
    }
    cout<<length<<'\n';
    for (int i = answer.size() - 1; i >=0; i--)
    {
        cout<<answer[i]<<" ";
    }
}

int main()
{
    int amount;
    cin>>amount;
    vector<int> numbers (amount);
    for (int i = 0; i < amount; i++) cin>>numbers[i];
    findLIS(numbers);
    return 0;
}
