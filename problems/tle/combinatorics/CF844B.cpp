#include <bits/stdc++.h>

using namespace std;

#define ll long long

double log_a_to_base_b(double a, double b) {
    return std::log(a) / std::log(b);
}

int main() {
    ll n, m;
    cin >> n >> m;

    ll cnt = 0;
    vector<ll> cols(m, 0);
    for (int i = 0; i < n; i++) {
        ll row = 0;
        for (int j = 0; j < m; j++) {
            ll cell;
            cin >> cell;

            row += cell;
            cols[j] += cell;
        }

        cnt += pow(2, row) - 1 + pow(2, m - row) - 1;
    }

    for (int j = 0; j < m; j++) {
        ll col = cols[j];
        cnt += pow(2, col) - 1 + pow(2, n - col) - 1;
    }

    cout << cnt - n * m;

    return 0;
}