#include <bits/stdc++.h>

using namespace std;

void quickSort(vector <int>& numbers, int left, int right)
{
    int i = left, j = right;
    int pivot = numbers[(left+right)/2];

    while(i <= j)
    {
        while(numbers[i] < pivot) i++;
        while(numbers[j] > pivot) j--;
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
    int amount;
    vector <int> numbers;
    cin>>amount;
    for (int i = 0; i < amount; i++)
    {
        int x;
        cin>>x;
        numbers.push_back(x);
    }
    quickSort(numbers,0,amount-1);
    for (int i = 0; i < amount; i++) cout<<numbers[i]<<" ";
    return 0;
}
