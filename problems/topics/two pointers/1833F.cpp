#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define INF 1e18
#define ll long long
#define ld long double
#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

void IN_OUT() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

long long inv_euclid_div(long long a, long long m) {
    if (a == 1)
        return 1;
    return (1 - 1ll * inv_euclid_div(m % a, a) * m) / a + m;
}

ll solve(int n, ll m, vector<ll> a) {
    ll mod = 1e9 + 7;
    map<ll, ll> map;
    for (int i = 0; i < n; i++)
        map[a[i]] += 1;

    vector<ll> b;
    for (auto [key, val]: map)
        b.emplace_back(key);
    if (b.size() < m)
        return 0;

    ll cnt = 0, curr_prod = 1;
    for (int i = 0; i < m; i++)
        curr_prod = ((curr_prod % mod) * (map[b[i]] % mod)) % mod;

    if (b[m - 1] - b[0] < m)
        cnt = curr_prod;

    ll l = 0, r = m;
    while (b.size() > r) {
        curr_prod = ((curr_prod % mod) * (map[b[r]] % mod)) % mod;
        while (r - l + 1 > m) {
            curr_prod = ((curr_prod % mod) * (inv_euclid_div(map[b[l]], mod) % mod)) % mod;
            l += 1;
        }

        if (b[r] - b[l] < m)
            cnt = ((cnt % mod) + (curr_prod % mod)) % mod;

        r += 1;
    }

    return cnt;
}

int main() {
    fastio();
    IN_OUT();
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        ll m;
        cin >> n >> m;

        vector<ll> a(n, 0);
        for (int j = 0; j < n; j++)
            cin >> a[j];

        cout << solve(n, m, a) << endl;
    }

    return 0;
}