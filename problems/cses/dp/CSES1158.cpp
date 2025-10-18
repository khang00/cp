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

ll solve(ll n, ll x, vector<int> &h, vector<int> &s) {
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));
    for (int j = 0; j <= x; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= x; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - h[i - 1] >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - h[i - 1]] + s[i - 1]);
        }

    return dp[n][x];
}

int main() {
    fastio();
    IN_OUT();

    ll n, x;
    cin >> n >> x;

    vector<int> h(n, 0), s(n, 0);
    for (auto i = 0; i < n; i++)
        cin >> h[i];

    for (auto i = 0; i < n; i++)
        cin >> s[i];

    cout << solve(n, x, h, s);

    return 0;
}
