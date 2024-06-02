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
// OV, OV
// dp[1][1] = 0
// dp[2][3] = dp[2][2] + 1 add/remove letter I
// dp[3][2] = dp[2][2] + 1 replace E with I or I with E
ll solve(string a, string b) {
    int n = a.size(), m = b.size();

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, INF));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
        dp[i][0] = dp[i - 1][0] + 1;
    for (int j = 1; j <= m; j++)
        dp[0][j] = dp[0][j - 1] + 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else {
                dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
            }
        }
    }

#ifndef ONLINE_JUDGE
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
#endif

    return dp[n][m];
}

int main() {
    fastio();
    IN_OUT();

    string a, b;
    cin >> a >> b;

    cout << solve(a, b);

    return 0;
}