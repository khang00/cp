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

ll solve(int n, ll k, vector<ll> a) {
    vector<ll> pre_sum(n, 0);
    pre_sum[0] = a[0];
    for (int i = 1; i < n; i++) {
        pre_sum[i] = pre_sum[i - 1] + a[i];
    }

    if (k - pre_sum[n - 1] >= 0) {
        return n;
    }

    vector<ll> suf_sum(n, 0);
    suf_sum[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suf_sum[i] = suf_sum[i + 1] + a[i];
    }

    ll ans = 0;
    ll lk = ceil((double) k / 2);
    int l = -1;
    int r = n;
    while (r - l > 1) {
        int mid = midpoint(l, r);
        if (lk - pre_sum[mid] >= 0) {
            l = mid;
        } else {
            r = mid;
        }
    }

    ans += l + 1;

    ll rk = k - lk;
    l = -1;
    r = n;
    while (r - l > 1) {
        int mid = midpoint(l, r);
        if (rk - suf_sum[mid] < 0) {
            l = mid;
        } else {
            r = mid;
        }
    }

    ans += n - r;

    return ans;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        ll k;
        cin >> n >> k;

        vector<ll> a(n, 0);
        for (int j = 0; j < n; j++) {
            ll temp;
            cin >> temp;

            a[j] = temp;
        }

        cout << solve(n, k, a) << '\n';
    }

    return 0;
}