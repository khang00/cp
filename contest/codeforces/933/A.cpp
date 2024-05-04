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

ll solve(vector<ll> b, vector<ll> c, int n, int m, int k) {
    std::sort(b.begin(), b.end());
    std::sort(c.begin(), c.end());

    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[i] + c[j] <= k) {
                cnt += 1;
            }
        }
    }

    return cnt;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<ll> b(n, 0);
        for (int j = 0; j < n; j++) {
            ll temp;
            cin >> temp;

            b[j] = temp;
        }

        vector<ll> c(m, 0);
        for (int j = 0; j < m; j++) {
            ll temp;
            cin >> temp;

            c[j] = temp;
        }

        cout << solve(b, c, n, m, k) << '\n';
    }
}