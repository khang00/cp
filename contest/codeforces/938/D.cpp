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

int solve(int n, int m, int k, vector<ll> a, vector<ll> b) {
    unordered_map<ll, int> mb;
    for (int i = 0; i < m; i++) {
        if (mb.contains(b[i])) {
            mb[b[i]] += 1;
        } else {
            mb[b[i]] = 1;
        }
    }

    int cnt = 0;
    int matched = 0;
    int l = 0;
    unordered_map<ll, int> ma;
    for (int i = 0; i < m; i++) {
        matched -= min(ma[a[i]], mb[a[i]]);
        ma[a[i]] += 1;
        matched += min(ma[a[i]], mb[a[i]]);
    }

    cnt += matched >= k;
    for (int i = m; i < n; i++) {
        while (i - l + 1 > m) {
            matched -= min(ma[a[l]], mb[a[l]]);
            ma[a[l]] -= 1;
            matched += min(ma[a[l]], mb[a[l]]);
            l++;
        }

        matched -= min(ma[a[i]], mb[a[i]]);
        ma[a[i]] += 1;
        matched += min(ma[a[i]], mb[a[i]]);

        cnt += matched >= k;
    }

    return cnt;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<ll> a(n, 0);
        for (int j = 0; j < n; j++) {
            ll temp;
            cin >> temp;

            a[j] = temp;
        }

        vector<ll> b(m, 0);
        for (int j = 0; j < m; j++) {
            ll temp;
            cin >> temp;

            b[j] = temp;
        }

        cout << solve(n, m, k, a, b) << '\n';
    }

    return 0;
}