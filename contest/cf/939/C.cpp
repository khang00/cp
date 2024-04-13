#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

double log_a_to_base_b(double a, double b) {
    return std::log(a) / std::log(b);
}

ll comb(ll n, ll k) {
    ld res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;

    return (ll) (res + 0.01);
}

vector<ll> pow_2_arr(ll exp) {
    vector<ll> _2_pow(exp + 1, 1);
    _2_pow[0] = 1;

    for (int i = 1; i <= exp; i++) {
        _2_pow[i] = _2_pow[i - 1] * 2;
    }

    return _2_pow;
}

ll big_pow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll solve(int n) {
    ll sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += (2 * i - 1) * i;
    }

    return sum;
}

void print_arr(int n) {
    for (int j = 1; j <= n; j++) {
        cout << j << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;

    vector<int> a(t, 0);
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        cout << solve(n) << ' ' << 2 * n << '\n';
        for (int j = n; j >= 1; j--) {
            cout << 1 << ' ' << j << ' ';
            print_arr(n);

            cout << 2 << ' ' << j << ' ';
            print_arr(n);
        }
    }

    return 0;
}