#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define INF (ll) 1e18
#define ll long long
#define ul unsigned long
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

ll solve(ll n, ll t, vector<ll> a) {
    vector<ll> dp(t + 1, INF);
    for (int i = 0; i < n; i++)
        if (t >= a[i])
            dp[a[i]] = 1;

    for (int i = 1; i <= t; i++) {
        for (int j = 0; j < n; j++) {
            if (i > a[j])
                dp[i] = min(dp[i], dp[i - a[j]] + 1);
        }
    }

    if (dp[t] == INF)
        return -1;

    return dp[t];
}

int main() {
    fastio();
    IN_OUT();

    ll n, t;
    cin >> n >> t;

    vector<ll> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << solve(n, t, a);

    return 0;
}