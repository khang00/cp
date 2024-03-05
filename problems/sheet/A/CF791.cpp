#include <bits/stdc++.h>
using namespace std;

#define ll long long

double log_a_to_base_b(double a, double b) {
    return std::log(a) / std::log(b);
}

int main() {
    ll a, b;
    cin >> a >> b;

    auto i = 0;
    while (a <= b) {
        a *= 3;
        b *= 2;
        i++;
    }

    cout << i;

    return 0;
}