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

bool is_min(int n, vector<int> h, int mid) {
    vector<int> fh(h.begin(), h.end());
    for (int i = n - 1; i >= 2; i--) {
        int d = min(fh[i], (h[i] - mid)) / 3;
        if (d < 0)
            return false;
        h[i] = h[i] - 3 * d;
        h[i - 1] = h[i - 1] + d;
        h[i - 2] = h[i - 2] + 2 * d;
    }

    int min_ = 1e9 + 7;
    for (int i = 0; i < n; i++) {
        min_ = min(min_, h[i]);
    }

    return min_ >= mid;
}

int solve(int n, vector<int> h) {
    int l = 0, r = 1e9 + 7;

    while (r - l > 1) {
        int mid = midpoint(l, r);
        if (is_min(n, h, mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    return l;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> h(n, 0);
        for (int j = 0; j < n; j++) {
            cin >> h[j];
        }

        cout << solve(n, h) << '\n';
    }
    return 0;
}