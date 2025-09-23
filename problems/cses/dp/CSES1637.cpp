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
  vector<ll> dp(n + 1, -1);
  dp[0] = 0;

  function<ll(ll)> recurse = [&](ll x) -> ll {
    if (dp[x] != -1)
      return dp[x];

    ll temp = x;
    ll minStep = INF;
    while (temp > 0) {
      ll digit = temp % 10;
      temp /= 10;

      if (digit == 0)
        continue;

      minStep = min(minStep, recurse(x - digit) + 1);
    }

    dp[x] = minStep;
    return minStep;
  };

  return recurse(n);
}

int main() {
  fastio();
  IN_OUT();

  ll n;
  cin >> n;

  cout << solve(n);

  return 0;
}
