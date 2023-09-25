#include <iostream>
#include <cmath>

using namespace std;

long double s_f(int q)
{
    if (q == 0)
        return 1;
    if (q == 1)
        return 1;
    return q * s_f(q - 2);
}

long double t_one(double x) {
    long double s1 = 0;
    long double s2 = 0;
    for (int k = 0; k <= 10; k ++)
    {
        s1 = s1 + pow(x, 2 * k + 1) / s_f(2 * k + 1);
    }
    for (int k = 0; k <= 10; k ++)
    {
        s2 = s2 + pow(x, 2 * k) / s_f(2 * k);
    }
    return s1 / s2;
}

int main() {
    long double ans;
    long double y;
    cin >> y;
    ans = (7 * t_one(0.25) + 2 * t_one(1 + y)) / (6 - t_one(y * y - 1));
    cout << ans;
    return 0;
}