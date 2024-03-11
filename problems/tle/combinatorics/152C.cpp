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

ll solve(vector<string> names, int n, int m) {
    ll ans = 1;
    ll mod = 1000000007;
    vector<ll> pow_2 = pow_2_arr(m);
    for (int i = 0; i < m; i++) {
        unordered_set<char> set;
        for (int j = 0; j < n; j++) {
            set.insert(names[j][i]);
        }

        ans *= set.size();
        ans %= mod;
    }

    return ans;
}

int main() {
    ll n, m;
    cin >> n >> m;

    vector<string> names(n, "");
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        names[i] = str;
    }

    cout << solve(names, n, m);
    return 0;
}