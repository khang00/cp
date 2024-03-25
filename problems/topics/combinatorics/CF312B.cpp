#include <bits/stdc++.h>

using namespace std;

#define ll long long

double log_a_to_base_b(double a, double b) {
    return std::log(a) / std::log(b);
}

int main() {
    long double a, b, c, d;
    cin >> a >> b >> c >> d;

    long double res = (a / b) / (1 - (1 - a / b) * (1 - c / d));
    cout << fixed << setprecision(12) << res;

    return 0;
}