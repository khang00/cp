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

set<int> solve(int n, int m, int s, vector<pair<int, char>> throws) {
    set<int> poss;
    poss.insert(s - 1);

    for (int i = 0; i < m; i++) {
        auto [d, c] = throws[i];

        set<int> news;
        for (int pos: poss) {
            int x = pos;
            if (c == '0') {
                news.insert((x + d) % n);
            } else if (c == '1') {
                news.insert((x - d + n) % n);
            } else if (c == '?') {
                news.insert((x + d) % n);
                news.insert((x - d + n) % n);
            }
        }

        poss = news;
    }

    return poss;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m, x;
        cin >> n >> m >> x;

        vector<pair<int, char>> throws(m, pair(0, 'x'));
        for (int j = 0; j < m; j++) {
            int d;
            char s;
            cin >> d >> s;

            throws[j] = pair(d, s);
        }

        auto res = solve(n, m, x, throws);
        cout << res.size() << '\n';
        for (auto num: res) {
            cout << num + 1 << ' ';
        }
        cout << '\n';
    }

    return 0;
}