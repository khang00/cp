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

string solve(int n, string top, string bot) {
    for (int i = 0; i < n - 1; i++) {
        if (i % 2 == 0) {
            if (top[i + 1] == '<' && bot[i] == '<') {
                return "NO";
            }
        } else {
            if (top[i] == '<' && bot[i + 1] == '<') {
                return "NO";
            }
        }
    }

    return "YES";
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        string top, bot;
        cin >> top >> bot;

        cout << solve(n, top, bot) << '\n';
    }

    return 0;
}