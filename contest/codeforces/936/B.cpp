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

ll solve(int n, int k, vector<ll> a) {
    ll m = 1e9 + 7;
    ll curr_max = a[0];
    ll all_max = a[0];
    ll sum = a[0];
    for (int i = 1; i < n; i++) {
        curr_max = max(curr_max + a[i], a[i]);
        all_max = max(all_max, curr_max);
        sum = sum + a[i];
    }

    if (all_max < 0) {
        return (sum % m + m) % m;
    }

    for (int j = 0; j < k; j++) {
        ll temp =  (all_max % m);
        sum = ((sum % m + m) + temp) % m;
        all_max = (temp + temp) % m;
    }

    return sum;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;

        vector<ll> a(n, 0);
        for (int j = 0; j < n; j++) {
            ll temp;
            cin >> temp;

            a[j] = temp;
        }

        cout << solve(n, k, a) << "\n";
    }
    return 0;
}