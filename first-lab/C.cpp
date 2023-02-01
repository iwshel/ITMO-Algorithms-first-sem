#include <bits/stdc++.h>

using namespace std;

int main() {
    int amount, answer, minraz = 100000, numx;
    bool flag = false;
    cin >> amount;
    int *numbers = new int [amount];
    for (int i = 0; i < amount; i++)
    {
        cin>>numbers[i];
    }
    cin>>numx;
    for (int i = 0; i < amount; i++)
    {
       if (abs(numx - numbers[i]) < minraz)
       {
           minraz = abs(numx - numbers[i]);
           answer = numbers[i];
       }
    }
    cout<<answer;
    delete[] numbers;
    return 0;
}
