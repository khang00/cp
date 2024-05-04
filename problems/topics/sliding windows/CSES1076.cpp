#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void IN_OUT() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

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


vector<ll> solve(int n, int k, vector<ll> a) {
    if (k == 1)
        return a;

    vector<ll> b(a.begin(), a.begin() + k);
    sort(b.begin(), b.end());

    ll m = b[(k - 1) / 2];
    multiset<ll> hset;
    multiset<ll> lset;
    for (int i = 0; i < k; i++) {
        if (m < a[i])
            hset.insert(a[i]);
        else
            lset.insert(a[i]);
    }

    vector<ll> ans;
    ans.push_back(*lset.rbegin());
    for (int i = k; i < n; i++) {
        ll del = a[i - k];
        if (hset.find(del) != hset.end())
            hset.erase(hset.find(del));
        else
            lset.erase(lset.find(del));
        if (lset.empty()) {
            lset.insert(*hset.begin());
            hset.erase(hset.find(*hset.rbegin()));
        }

        ll mid = *lset.rbegin();
        if (mid < a[i]) {
            hset.insert(a[i]);
            if (hset.size() > k / 2) {
                lset.insert(*hset.begin());
                hset.erase(hset.find(*hset.begin()));
            }
        } else {
            lset.insert(a[i]);
            if (lset.size() > (k + 1) / 2) {
                hset.insert(*lset.rbegin());
                lset.erase(lset.find(*lset.rbegin()));
            }
        }

        ans.push_back(*lset.rbegin());
    }

    return ans;
}

int main() {
    fastio();
    IN_OUT();
    int n, k;
    cin >> n >> k;

    vector<ll> a(n, 0);
    for (int j = 0; j < n; j++) {
        cin >> a[j];
    }

    auto ans = solve(n, k, a);
    for (long long j: ans) {
        cout << j << ' ';
    }

    return 0;
}