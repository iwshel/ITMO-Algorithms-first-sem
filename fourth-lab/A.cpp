#include <bits/stdc++.h>

using namespace std;

int main()
{
    int amount;
    cin>>amount;
    vector <int> numbers (amount+1);
    for (int i = 1; i <= amount; i++) cin>>numbers[i];
    bool flag = true;
    for (int i = 1; i < amount/2 + 1; i++)
    {
        if ((2*i <= amount) && (numbers[i] > numbers[2*i]))
        {
            flag = false;
            break;
        }
        if ((2*i + 1 <= amount) && (numbers[i] > numbers[2*i + 1]))
        {
            flag = false;
            break;
        }
    }
    if (flag) cout<<"YES";
    else cout<<"NO";
    return 0;
}
