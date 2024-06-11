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

double solve(int n, vector<double> a) {
    vector<vector<double>> dp(n, vector<double>(n + 1, 0.0));
    dp[0][1] = a[0];
    dp[0][0] = 1 - a[0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = dp[i - 1][j - 1] * a[i] + dp[i - 1][j] * (1 - a[i]);
        }
    }

    double cnt = 0;
    for (int i = n / 2 + 1; i <= n; i++)
        cnt += dp[n - 1][i];

    return cnt;
}

int main() {
    fastio();
    IN_OUT();

    int n;
    cin >> n;

    vector<double> a(n, 0.0);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << solve(n, a) << '\n';
    return 0;
}