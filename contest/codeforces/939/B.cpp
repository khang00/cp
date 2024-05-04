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

int solve(int n, vector<int> a) {
    int dup = 0;
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) {
        if (map.contains(a[i]))
            dup += 1;
        else
            map[a[i]] = 1;
    }

    return dup;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> a(n, 0);
        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;

            a[j] = temp;
        }

        cout << solve(n, a) << '\n';
    }

    return 0;
}