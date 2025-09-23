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

ll solve(ll n, vector<vector<char> > &grid) {
  ll MOD = 1e9 + 7;

  vector<vector<ll> > dp(n, vector<ll>(n, 0));
  if (grid[0][0] != '*')
    dp[0][0] = 1;

  for (auto i = 0; i < n; i++)
    for (auto j = 0; j < n; j++) {
      if (grid[i][j] != '*' && i - 1 >= 0)
        dp[i][j] = dp[i - 1][j] % MOD;

      if (grid[i][j] != '*' && j - 1 >= 0)
        dp[i][j] += dp[i][j - 1] % MOD;
    }

  return dp[n - 1][n - 1] % MOD;
}

int main() {
  fastio();
  IN_OUT();

  ll n;
  cin >> n;

  vector<vector<char> > grid(n, vector<char>(n, '.'));
  for (auto i = 0; i < n; i++)
    for (auto j = 0; j < n; j++)
      cin >> grid[i][j];

  cout << solve(n, grid);

  return 0;
}
