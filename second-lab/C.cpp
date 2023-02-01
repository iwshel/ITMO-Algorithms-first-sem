#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, amountm, counter = 0;
    vector <int> mesc;
    vector <int> plots;
    cin>>n>>m;
    for (int i = 0; i < n * m; i++)
    {
        int x;
        cin>>x;
        plots.push_back(x);
    }
    cin>>amountm;
    for (int i = 0; i < amountm; i++)
    {
        int x;
        cin>>x;
        mesc.push_back(x);
    }
    for (int i = 1; i < n*m; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (plots[j-1] > plots[j]) swap(plots[j-1] ,plots[j]);
            else break;
        }
    }
    for (int i = 1; i < amountm; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (mesc[j-1] > mesc[j]) swap(mesc[j-1] ,mesc[j]);
            else break;
        }
    }
    int j = 0;
    for (int i = 0; i < n * m; i++)
    {
        int curj = j;
        bool flag = false;
        for (j; j < amountm; j++)
        {
            if (mesc[j] <= plots[i])
            {
                counter++;
                flag = true;
                j++;
                break;
            }
        }
        if (!flag) j = curj;
    }
    cout<<counter;
    return 0;
}
