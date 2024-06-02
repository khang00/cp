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

ll solve(ll n, vector<vector<char>> a) {
    ll mod = 1e9 + 7;

    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = (a[i][j] == '*') ? 0 : 1;
                continue;
            }
            if (a[i][j] == '*')
                continue;

            if (i == 0)
                dp[i][j] = dp[i][j - 1];
            else if (j == 0)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] % mod + dp[i][j - 1] % mod;
        }

    return dp[n - 1][n - 1] % mod;
}

int main() {
    fastio();
    IN_OUT();

    ll n;
    cin >> n;

    vector<vector<char>> a(n, vector<char>(n, '.'));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << solve(n, a);

    return 0;
}