#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <utility>

using namespace std;
using namespace __gnu_pbds;

#define INF (ll)1e18
#define MAX (int)1e6
#define ll long long
#define ul unsigned long
#define ld long double
#define fastio()                                                               \
ios_base::sync_with_stdio(false);                                            \
cin.tie(NULL);                                                               \
cout.tie(NULL);                                                              \
cout << fixed << std::setprecision(10)

void IN_OUT() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

ll solve(ll n, ll m, vector<int> &x) {
    ll MOD = 1e9 + 7;
    vector<vector<ll> > dp(n, vector<ll>(m + 1, 0));
    if (x[0] == 0)
        fill(dp[0].begin(), dp[0].end(), 1);
    else
        dp[0][x[0]] = 1;

    for (int i = 1; i < n; i++)
        if (x[i] == 0) {
            for (int j = 1; j <= m; j++)
                for (auto k: {j - 1, j, j + 1})
                    if (1 <= k && k <= m)
                        (dp[i][j] += dp[i - 1][k]) %= MOD;
        } else
            for (auto k: {x[i] - 1, x[i], x[i] + 1})
                if (1 <= k && k <= m)
                    (dp[i][x[i]] += dp[i - 1][k]) %= MOD;

    ll ans = 0;
    for (int j = 1; j <= m; j++)
        (ans += dp[n - 1][j]) %= MOD;

    return ans;
}

int main() {
    fastio();
    IN_OUT();

    ll n, m;
    cin >> n >> m;

    vector<int> x(n, 0);
    for (auto i = 0; i < n; i++)
        cin >> x[i];

    cout << solve(n, m, x);

    return 0;
}