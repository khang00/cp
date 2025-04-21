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

vector<ll> getDigits(ll n) {
  vector<ll> digits;
  while (n > 0) {
    ll mod = n % 10;
    n /= 10;

    digits.push_back(mod);
  }
  std::reverse(digits.begin(), digits.end());
  return digits;
}

ll solve(string n) {
  ll mod = 10;
  ll cnt = 0;

  return cnt;
}

int main() {
  fastio();
  IN_OUT();

  string n;
  cin >> n;

  cout << solve(n);

  return 0;
}
