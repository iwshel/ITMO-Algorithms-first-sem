#include <bits/stdc++.h>

using namespace std;

int main()
{
    int amount;
    cin>>amount;
    vector<pair<int,int>> numbers;
    for (int i = 0; i < amount; i++)
    {
        int x, y;
        cin>>x>>y;
        numbers.push_back(make_pair(x,y));
    }
    for (int i = 1; i < amount; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (numbers[j-1].second < numbers[j].second)
                    swap(numbers[j-1], numbers[j]);

            else break;
        }
    }
    for (int i = 1; i < amount; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (numbers [j-1].second == numbers[j].second){
            if (numbers[j-1].first > numbers[j].first) swap(numbers[j-1] ,numbers[j]);}
            else break;
        }
    }
    for (int i = 0; i < amount; i++) cout<<numbers[i].first<<" "<<numbers[i].second<<endl;
    return 0;
}
