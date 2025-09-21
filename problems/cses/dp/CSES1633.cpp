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

ll solve(ll n) {
  ll mod = 1e9 + 7;

  vector<ll> dp(n + 1, 0);
  dp[0] = 1;

  for (auto i = 1; i <= n; i++)
    for (auto j = 1; j <= 6; j++)
      if (i - j >= 0)
        dp[i] += dp[i - j] % mod;

  return dp[n] % mod;
}

int main() {
  fastio();
  IN_OUT();

  ll n;
  cin >> n;

  cout << solve(n);

  return 0;
}
