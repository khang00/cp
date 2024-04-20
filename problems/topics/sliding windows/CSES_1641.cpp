#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void IN_OUT() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

struct CHash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

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

vector<int> solve(int n, ll x, vector<ll> a) {
    vector<pair<ll, int>> arr(n, pair(0, 0));
    for (int i = 0; i < n; i++) {
        arr[i] = pair(a[i], i);
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        ll t = x - arr[i].first;

        int l = i + 1, r = n;
        while (r - l > 1) {
            ll k = arr[l].first + arr[r - 1].first;
            if (k == t)
                return vector<int>{arr[i].second + 1, arr[l].second + 1, arr[r - 1].second + 1};
            else if (k > t)
                r -= 1;
            else
                l += 1;
        }
    }

    return vector<int>(0, 0);
}

int main() {
    fastio();
    IN_OUT();
    int n;
    ll x;
    cin >> n >> x;

    vector<ll> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto ans = solve(n, x, a);
    if (ans.empty())
        cout << "IMPOSSIBLE";
    else
        for (auto c: ans)
            cout << c << ' ';

    return 0;
}