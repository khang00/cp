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
  cout.tie(NULL);                                                              \
  cout << fixed << std::setprecision(10)

void IN_OUT() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

ll solve(int n, vector<ll> a, vector<ll> b) {
    ll mod = 998244353;
    int m = 3000;
    vector<vector<ll>> dp(n, vector<ll>(m + 1, 0));

    for (ll j = a[0]; j <= m; j++)
        if (j == a[0])
            dp[0][j] = 1;
        else if (j <= b[0])
            dp[0][j] = dp[0][j - 1] + 1;
        else
            dp[0][j] = dp[0][j - 1];

    for (int i = 1; i < n; i++) {
        for (ll j = a[i]; j <= m; j++) {
            if (j == 0)
                dp[i][j] = 1;
            else if (j <= b[i])
                dp[i][j] = ((ll) dp[i - 1][j] % mod + (ll) dp[i][j - 1] % mod) % mod;
            else
                dp[i][j] = dp[i][j - 1];
        }
    }

    return dp[n - 1][b[n - 1]];
}

int main() {
    fastio();
    IN_OUT();

    int n;
    cin >> n;

    vector<ll> a(n, 0);
    vector<ll> b(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];


    cout << solve(n, a, b);
    return 0;
}