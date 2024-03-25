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

bool is_possible(int n, int k, ll s, vector<ll> &x) {
    ll curr_s = 0;

    for (int i = 0; i < n; i++) {
        if (x[i] > s)
            return false;

        if (curr_s + x[i] <= s)
            curr_s += x[i];
        else {
            curr_s = x[i];
            k -= 1;
        }
    }

    if (curr_s > 0)
        k -= 1;

    return k >= 0;
}

ll solve(int n, int k, vector<ll> &x) {
    ll l = 0;
    ll r = LLONG_MAX;

    while (r - l > 1) {
        ll m = midpoint(l, r);
        if (!is_possible(n, k, m, x)) {
            l = m;
        } else {
            r = m;
        }
    }

    return r;
}


int main() {
    int n, k;
    cin >> n >> k;

    vector<ll> x(n, 0);
    for (int i = 0; i < n; i++) {
        ll temp;
        cin >> temp;

        x[i] = temp;
    }

    cout << solve(n, k, x) << '\n';
}