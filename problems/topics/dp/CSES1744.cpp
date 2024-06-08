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

ll solve(ll a, ll b) {
    vector<vector<ll>> dp(a + 1, vector<ll>(b + 1, INF));
    for (int i = 0; i <= min(a, b); i++)
        dp[i][i] = 0;

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            for (int k = 1; k <= i / 2; k++) {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
            }

            for (int k = 1; k <= j / 2; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            }
        }
    }

#ifndef ONLINE_JUDGE
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
#endif

    return dp[a][b];
}

int main() {
    fastio();
    IN_OUT();

    ll a, b;
    cin >> a >> b;

    cout << solve(a, b) << '\n';
    return 0;
}