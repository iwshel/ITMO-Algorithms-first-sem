#include <bits/stdc++.h>

using namespace std;

int main() {
    int amount, last_element;
    cin >> amount;
    vector <int> answer;
    for (int i = 0; i < amount; i++)
    {
        int number;
        cin >> number;
        if (i == amount - 1) last_element = number;
        else answer.push_back(number);
    }
    answer.insert(answer.begin(), last_element);
    for (int i = 0; i < amount; i++) cout<<answer[i]<<" ";
    return 0;
}
