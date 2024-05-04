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

pair<int, int> solve(int n, int x, vector<int> p) {
    int xi = 0;
    while (p[xi] != x) {
        xi++;
    }

    int l = 0;
    int r = n;
    while (r - l > 1) {
        int m = (r + l) / 2;
        if (p[m] <= x) {
            l = m;
        } else {
            r = m;
        }
    }

    return pair(xi + 1, l + 1);
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int x, n;
        cin >> n >> x;

        vector<int> p(n, 0);
        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;

            p[j] = temp;
        }

        auto pair = solve(n, x, p);
        cout << 1 << '\n';
        cout << pair.first << ' ' << pair.second << '\n';
    }

    return 0;
}