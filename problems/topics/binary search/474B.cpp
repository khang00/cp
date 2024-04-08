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

vector<int> solve(int n, int m, vector<int> a, vector<int> q) {
    for (int i = 1; i < n; i++) {
        a[i] = a[i] + a[i - 1];
    }

    vector<int> ans(m, 0);
    for (int i = 0; i < m; i++) {
        int l = -1;
        int r = n - 1;

        while (r - l > 1) {
            int mid = midpoint(l, r);
            if (q[i] > a[mid]) {
                l = mid;
            } else {
                r = mid;
            }
        }

        ans[i] = r + 1;
    }

    return ans;
}

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        a[i] = temp;
    }

    cin >> m;
    vector<int> q(m, 0);
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;

        q[i] = temp;
    }

    auto ans = solve(n, m, a, q);
    for (int i = 0; i < m; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}