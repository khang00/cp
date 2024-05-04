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

string solve(int n, int c, int d, vector<ll> a) {
    unordered_map<ll, int> map;
    for (int i = 0; i < n * n; i++) {
        if (map.contains(a[i])) {
            map[a[i]] += 1;
        } else {
            map[a[i]] = 1;
        }
    }

    auto start = *min_element(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll t = start + c * i + d * j;
            map[t] -= 1;
        }
    }

    for (auto it = map.begin(); it != map.end(); it++) {
        if (it->second != 0) {
            return "No";
        }
    }

    return "Yes";
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, c, d;
        cin >> n >> c >> d;

        vector<ll> a(n * n, 0);
        for (int j = 0; j < n * n; j++) {
            ll temp;
            cin >> temp;

            a[j] = temp;
        }

        cout << solve(n, c, d, a) << '\n';
    }

    return 0;
}