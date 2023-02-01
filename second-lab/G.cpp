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
    int amount1, amount2;
    vector <int> numbers;
    vector <int> numbers_copy;
    cin>>amount1;
    for (int i = 0; i < amount1; i++)
    {
        int x;
        cin>>x;
        numbers.push_back(x);
    }
    cin>>amount2;
    for (int i = 0; i < amount2; i++)
    {
        int x;
        cin>>x;
        numbers_copy.push_back(x);
    }
    quickSort(numbers, 0, amount1 - 1);
    quickSort(numbers_copy, 0, amount2 - 1);
    int i=0;
    int j=0;
    bool flag=1;
    while(i<amount1 && j<amount2){
        if(numbers[i]==numbers_copy[j]){
            i++;
            j++;
            while(i<amount1 && numbers[i-1]==numbers[i]) i++;
            while(j<amount2 && numbers_copy[j-1]==numbers_copy[j]) j++;
        }
        else{
            flag=0;
            break;
        }
    }
    if(i<=amount1-1 || j<=amount2-1) flag=0;
    if (flag) cout<<"YES";
    else cout<<"NO";
    return 0;
}
