#include <bits/stdc++.h>

using namespace std;

void MergeSort(vector <int> numbers, int first, int last)
{
    if (first < last)
    {
        MergeSort(numbers, first, (first + last)/2);
        MergeSort(numbers, (first + last)/2+1, last);
        Merge(numbers, first, last);
    }
}
void Merge(vector <int> numbers, int first, int last)
{
    int start = first, middle = (first + last)/2, final = middle + 1;

}
int main()
{
    vector <int> numbers;
    int first, last, amount;
    cin>>amount;
    for(int i = 0; i < amount; i++)
    {
        int x;
        cin>>x;
        numbers.push_back(x);
    }
    return 0;
}
