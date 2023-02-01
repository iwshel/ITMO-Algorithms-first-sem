#include <bits/stdc++.h>

using namespace std;

int stat(vector <int> &numbers, int k, int left, int right)
{
        if (right - left <=1)
        {
            if (numbers[left] > numbers[right]) swap(numbers[left], numbers[right]);
            return numbers[k];
        }
        if (right - left == 2)
        {
            for (int i = left; i <= right; i++)
                for (int j = i - 1; j >= left; j--) if (numbers[i] < numbers[j]) swap (numbers[i], numbers[j]);
            return numbers[k];
        }
        int m = (left+right)/2;
        int left1 = left, right1 = right;
        int mid = numbers[m];
        while(left1 < right1)
    {
        while(numbers[left1]<mid) left1++;
        while(numbers[right1]>mid) right1--;
        if (left1 >= right1) break;
        swap(numbers[left1], numbers[right1]);
        left1++;
        right1--;
    }
        cout<<right1<<" ";
        if (k <= right1) return stat(numbers, k, left, right1);
        else return stat(numbers, k, left1, right);
}

int main()
{
    int fnd,A,B,C,a0,a1;
    int amount;
    cin>>amount>>fnd;
    vector<int> numbers(3*pow(10,7));
    cin>>A>>B>>C>>a0>>a1;
    numbers[0] = a0;
    numbers[1] = a1;
    for (int i = 2; i < amount; i++)
    {
        numbers[i] = A*numbers[i-2]+B*numbers[i-1] + C;
    }
    for (int i = 0; i < amount; i++) cout<<numbers[i]<<" ";
    cout<<endl;
    cout<<stat(numbers, fnd-1, 0, amount-1);
    return 0;
}
