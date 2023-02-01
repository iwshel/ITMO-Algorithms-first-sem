#include <bits/stdc++.h>

using namespace std;

void radix_sort(vector <string> &elements, int index, int amount, int phase, int counter)
{
    int alph [26] = {0};
    for (int i = 0; i < amount; i++)
    {
        string current = elements[i];
        char cur = current[index];
        alph[cur - '0' - 49]++;
    }
    for (int i = 1; i < 26; i++) alph[i] += alph[i-1];
    vector <string> cur_answer (amount);
    for (int i = amount - 1; i >= 0; i--)
    {
        string current = elements[i];
        char cur = current[index];
        cur_answer[alph[cur - '0' - 49] - 1] = current;
        alph[cur-'0' - 49]--;
    }
    for (int i = 0; i < amount; i++) elements[i] = cur_answer[i];
}

int main()
{
    int amount, length, phase;
    cin>>amount>>length>>phase;
    vector <string> elements (amount);
    for (int i = 0; i < amount; i++) cin>>elements[i];
    int counter = 0;
    for (int i = length - 1; i >= 0; i--)
    {
        phase--;
        radix_sort(elements, i, amount, phase, counter);
        if (phase == 0)
        {
            for (int i = 0; i < amount; i++) cout<<elements[i]<<'\n';
            break;
        }
    }
    return 0;
}
