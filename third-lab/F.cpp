#include <iostream>
#include <vector>

using namespace std;

int bin_search_left(vector<int>&numbers, int key)
{
    int left = -1;
    int right = numbers.size();
    while (left < right - 1)
    {
        int mid = (left + right) / 2;
        if(numbers[mid] >= key)
            right = mid;
        else
            left = mid;
    }
    if (numbers[right] == key)
        return right+1;
    else
        return -1;
}
int bin_search_right(vector<int>&numbers, int key)
{
    int left = -1;
    int right = numbers.size();
    while (left < right - 1)
    {
        int mid = (left + right) / 2;
        if(numbers[mid] <= key)
            left = mid;
        else
            right = mid;
    }
    if (numbers[left] == key)
        return left+1;
    else
        return -1;
}

int main()
{
    int amount;
    cin>>amount;
    vector<int> numbers;
    for(int i = 0; i < amount; i++)
    {
        int number;
        cin>>number;
        numbers.push_back(number);
    }
    int amount_search;
    cin>>amount_search;
    vector<int> numbers_search;
    for(int i = 0; i < amount_search; i++)
    {
        int search1;
        cin>>search1;
        numbers_search.push_back(search1);
    }
    for (int i = 0; i < numbers_search.size(); i++)
    {
        int key = numbers_search[i];
        //if (bin_search(numbers, key)!=-1)
        /*{
            int j = bin_search(numbers, key)-1;
            while(numbers[j+1] == numbers[j]) j++;
            cout<<bin_search(numbers, key)<<" "<<j+1<<'\n';
        }*/
        //else cout<<"-1 -1"<<'\n';
        cout<<bin_search_left(numbers,key)<<" "<<bin_search_right(numbers,key)<<'\n';
    }
    return 0;
}
