#include <bits/stdc++.h>

using namespace std;

#define ll long long

double log_a_to_base_b(double a, double b) {
    return std::log(a) / std::log(b);
}

int main() {
    ll n, m;
    cin >> n >> m;

    vector<ll> _2_pow(max(m,n)+1);
    _2_pow[0] = 1;
    for (int i = 1; i <= max(m,n); i++) {
        _2_pow[i] = _2_pow[i-1]*2;
    }

    ll cnt = 0;
    vector<ll> cols(m, 0);
    vector<ll> rows(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ll cell;
            cin >> cell;

            rows[i] += cell;
            cols[j] += cell;
        }
    }

    for (int i = 0; i < n; i++) {
        ll row = rows[i];
        cnt += _2_pow[row] - 1 + _2_pow[m - row] - 1;
    }

    for (int j = 0; j < m; j++) {
        ll col = cols[j];
        cnt += _2_pow[col] - 1 + _2_pow[n - col] - 1;
    }

    cout << cnt - n * m;

    return 0;
}