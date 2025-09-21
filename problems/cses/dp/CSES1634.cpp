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

ll solve(int n, int x, vector<int> c) {
  vector<ll> dp(x + 1, INF);
  dp[0] = 0;

  for (auto i = 1; i <= x; i++)
    for (auto j = 0; j < n; j++)
      if (i - c[j] >= 0)
        dp[i] = min(dp[i], dp[i - c[j]] + 1);

  if (dp[x] == INF)
    return -1;

  return dp[x];
}

int main() {
  fastio();
  IN_OUT();

  int n, x;
  cin >> n >> x;

  vector<int> c(n, 0);
  for (auto i = 0; i < n; i++)
    cin >> c[i];

  cout << solve(n, x, c);

  return 0;
}
