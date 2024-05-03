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

ll solve(ll n, ll k, ll d, vector<ll> a) {
    unordered_map<ll, ll> map;
    for (int i = 0; i < d; i++)
        map[a[i]] += 1;

    ll min_unq = map.size();
    ll l = 0, r = d;
    while (n > r) {
        map[a[r]] += 1;
        while (r - l + 1 > d) {
            map[a[l]] -= 1;
            if (map[a[l]] == 0)
                map.erase(a[l]);
            l += 1;
        }

        min_unq = min(min_unq, (ll) map.size());
        r += 1;
    }

    return min_unq;
}

int main() {
    fastio();
    IN_OUT();
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        ll n, k, d;
        cin >> n >> k >> d;

        vector<ll> a(n, 0);
        for (int j = 0; j < n; j++)
            cin >> a[j];

        cout << solve(n, k, d, a) << endl;
    }

    return 0;
}