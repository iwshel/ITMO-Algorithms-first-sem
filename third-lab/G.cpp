#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

double gir_fill(int amount, double height1, double height2)
{
    double h1 = height1;
    double h2 = height2;
    bool flag = true;
    for (int i = 2; i < amount; i++)
    {
        double h3 = 2*h2 - h1 + 2;
        if (h3 <= 0)
        {
            flag = false;
            break;
        }
        h1 = h2;
        h2 = h3;
    }
    if (!flag) return 0;
    else return h2;
}

double bin_search(double h1, int amount)
{
    double left = 0.0;
    double right = 2000000000;
    double mini = 1000000000000.0;
    while (right - left > 0.000001)
    {
        double mid = (left + right) / 2.0;
        if (gir_fill(amount, h1, mid) > 0)
        {
            if (mini > gir_fill(amount, h1, mid)) mini = gir_fill(amount, h1, mid);
            right = mid;
        }
        else
        {
            left = mid;
        }
    }
    return mini;
}

int main()
{
    int amount;
    double height;
    cin>>amount>>height;
    cout<<fixed<<setprecision(2)<<bin_search(height, amount);
    return 0;
}
