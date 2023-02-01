#include <bits/stdc++.h>

using namespace std;

int main() {
    int amount, minimum1, minimum2;
    cin >> amount;
    cin>>minimum1>>minimum2;
    for (int i = 2; i < amount; i++)
    {
        int number;
        cin>>number;
        if (number < minimum1) {
                if (minimum1 < minimum2) minimum2 = minimum1;
                minimum1 = number;
        }
        else if (number < minimum2) minimum2 = number;
    }
    cout<<minimum1<<" "<<minimum2;
    return 0;
}
