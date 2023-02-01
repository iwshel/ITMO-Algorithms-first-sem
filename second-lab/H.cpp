#include <bits/stdc++.h>

using namespace std;

void quickSort(vector <pair<int,int>>& numbers, int left, int right)
{
    int i = left, j = right;
    int pivot = numbers[(left+right)/2].first;

    while(i <= j)
    {
        while(numbers[i].first < pivot) i++;
        while(numbers[j].first > pivot) j--;
        if (i <= j) {
                swap(numbers[i], numbers[j]);
                i++;
                j--;
    }
    }

    if (left < j) quickSort(numbers, left, j);
    if (i < right) quickSort(numbers, i, right);
}

int main()
{
    int amount, counter = 0,maxg=0;
    vector<pair<int,int>> numbers;
    cin>>amount;
    for(int i = 0; i < amount; i++)
    {
        int x, y;
        cin>>x>>y;
        numbers.push_back(make_pair(x,y));
    }
    quickSort(numbers,0,amount-1);
    counter += numbers[0].second-numbers[0].first+1;
    maxg = max(maxg, numbers[0].second);
    for (int i = 1; i < amount; i++)
    {
        cout<<numbers[i].first<<" "<<numbers[i].second<<endl;
        counter += numbers[i].second-numbers[i].first+1;
        if (numbers[i].first <= maxg) counter -= min(maxg,numbers[i].second)-numbers[i].first+1;
        maxg = max(maxg, numbers[i].second);
        cout<<maxg<<endl;
        cout<<counter<<endl;
    }
    cout<<counter;
    return 0;
}
