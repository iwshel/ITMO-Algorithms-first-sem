#include <bits/stdc++.h>

using namespace std;

void bin_search_sum (vector <int> &numbers, int k, int left, int right)
{
    int mid = (left + right) / 2;
    vector<int>answer;
    bool flag = true;
    int cur_sum = 0;
    int counter_k = 0;
    int sum_max = INT_MIN;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (cur_sum + numbers[i] <= mid) cur_sum += numbers[i];
        else
        {
            sum_max = max(sum_max, cur_sum);
            cur_sum = numbers[i];
            counter_k ++;
            answer.push_back(i);
        }
        if (counter_k > k)
        {
            flag = false;
            break;
        }
    }
    if (cur_sum > 0 && cur_sum <= mid)
    {
        counter_k ++;
        answer.push_back(numbers.size() - 1);
    }
    if (answer.size() < k - 1 && left == right)
    {
        int razn = k - 1 - answer.size();
        int j = 0;
        bool f = 1;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (razn == 0) break;
            if (f == 0)
            {
                answer.push_back(i + 1);
                razn--;
            }
            else if (i + 1 == answer[j])
            {
                j++;
                if (j == answer.size()) f = 0;
            }
            else if (i + 1 != answer[j])
            {
                answer.insert(answer.cbegin() + j, i + 1);
                counter_k ++;
                j++;
                if (j == answer.size()) f = 0;
                razn--;
            }
        }
    }
    if (!flag) return bin_search_sum(numbers, k, mid, right);
    if (counter_k < k) return bin_search_sum(numbers, k, left, mid);
    if (left == right || counter_k == k)
    {
        for (int i = 0; i < answer.size(); i++) cout<<answer[i]<<" ";
    }
}

int main()
{
    vector <int> mas;
    int amount;
    int k;
    cin>>amount>>k;
    int sum_elem = 0;
    int max_elem = 0;
    for (int i = 0; i < amount; i++)
    {
        int number;
        cin>>number;
        sum_elem += number;
        max_elem = max (max_elem, number);
        mas.push_back(number);
    }
    bin_search_sum(mas, k, max(sum_elem/k, max_elem), sum_elem);
    return 0;
}
