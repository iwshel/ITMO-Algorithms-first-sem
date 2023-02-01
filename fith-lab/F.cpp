    #include <bits/stdc++.h>

    using namespace std;

    void second_obh(vector <int> &numbers, int mi, int ma, int& in)
    {
        if (numbers[in] > ma || numbers[in] < mi || in == numbers.size()) return;
        int in_cur = in;
        in++;
        second_obh(numbers, mi, numbers[in_cur], in);
        second_obh(numbers, numbers[in_cur], ma, in);
        cout<<numbers[in_cur]<<" ";
    }

    int main() {
        int amount;
        cin>>amount;
        vector <int> numbers;
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < amount; i++)
        {
            int x;
            cin>>x;
            numbers.push_back(x);
            mini = min(mini, x);
            maxi = max(maxi, x);
        }
        int i = 0;
        second_obh(numbers, mini, maxi, i);
      return 0;
    }
