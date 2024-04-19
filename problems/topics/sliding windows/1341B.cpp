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

pair<ll, ll> solve(int n, int k, vector<int> a) {
    int p = 0;
    int l = 0, r = 0;
    while (r - l + 1 < k) {
        if (r - l + 1 >= 3 && a[r - 2] < a[r - 1] && a[r - 1] > a[r]) {
            p++;
        }
        r++;
    }

    int min_l = 0;
    int max_p = p;
    while (n > r && r >= l) {
        while (r >= l && r - l + 1 > k) {
            if (r - l + 1 >= 3 && a[l] < a[l + 1] && a[l + 1] > a[l + 2]) {
                p = max(0, p - 1);
            }
            l++;
        }

        if (r - l + 1 >= 3 && a[r - 2] < a[r - 1] && a[r - 1] > a[r]) {
            p++;
            if (p > max_p) {
                max_p = max(p, max_p);
                min_l = l;
            }
        }
        r++;
    }

    return pair(max_p + 1, min_l + 1);
}


int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n, 0);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }

        pair<int, int> res = solve(n, k, a);
        cout << res.first << ' ' << res.second << '\n';
    }
    return 0;
}