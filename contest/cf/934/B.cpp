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

pair<vector<int>, vector<int>> solve(int n, int k, vector<int> a) {
    vector<int> l(0, 0);
    vector<int> r(0, 0);

    unordered_set<int> ls(a.begin(), a.begin() + n);
    unordered_set<int> rs(a.begin() + n, a.begin() + n * 2);
    for(int it : ls) {
        if (rs.find(it) == rs.end()) {
            l.push_back(it);
            l.push_back(it);
        }

        if(l.size() == 2 * k) {
            break;
        }
    }

    for(int it : rs) {
        if (ls.find(it) == ls.end()) {
            r.push_back(it);
            r.push_back(it);
        }

        if(r.size() == 2 * k) {
            break;
        }
    }

    if(l.size() == r.size() && l.size() == 2 * k) {
        return {l, r};
    }

    for(int it : ls) {
        if (rs.find(it) != rs.end()) {
            l.push_back(it);
            r.push_back(it);
        }

        if(l.size() == r.size() && l.size() == 2 * k) {
            break;
        }
    }

    return {l, r};
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;

        vector<int> a(2 * n, 0);
        for (int j = 0; j < 2 * n; j++) {
            int temp;
            cin >> temp;

            a[j] = temp;
        }

        auto [l, r] = solve(n, k, a);
        for (int j: l) {
            cout << j << ' ';
        }
        cout << '\n';

        for (int j: r) {
            cout << j << ' ';
        }
        cout << '\n';
    }

    return 0;
}