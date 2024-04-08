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

bool is_cover(int n, int m, ll r, const vector<ll> &a, const vector<ll> &b) {
    int i = 0;
    int j = 0;

    while (i < n && j < m) {
        if (b[j] - r <= a[i] && a[i] <= b[j] + r) {
            i += 1;
        } else {
            j += 1;
        }
    }

    return i == n;
}

ll solve(int n, int m, vector<ll> a, vector<ll> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll l = -1;
    ll r = (1e9 + 1) * 2;

    while (r - l > 1) {
        ll mid = midpoint(r, l);
        if (!is_cover(n, m, mid, a, b)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    return r;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<ll> a(n, 0), b(m, 0);
    for (int i = 0; i < n; i++) {
        ll temp;
        cin >> temp;

        a[i] = temp;
    }

    for (int i = 0; i < m; i++) {
        ll temp;
        cin >> temp;

        b[i] = temp;
    }

    cout << solve(n, m, a, b);

    return 0;
}