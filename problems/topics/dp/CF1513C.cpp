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

ll solve(string s, ll m, const vector<ll> &dp) {
    int n = s.size();
    ll mod = 1e9 + 7;
    ll sum = 0;

    for (int i = 0; i < n; i++) {
        int num = s[i] - '0';
        if (m - (10 - num) >= 0)
            sum += dp[m - (10 - num)] % mod;
        else
            sum += 1 % mod;
    }

    return sum % mod;
}

int main() {
    fastio();
    IN_OUT();

    ll mod = 1e9 + 7;
    vector<ll> dp(2 * 1e5 + 1, 0);
    dp[9] = 3;
    for (int i = 0; i <= 8; i++)
        dp[i] = 2;

    for (int i = 10; i < dp.size(); i++)
        dp[i] = (dp[i - 9] % mod + dp[i - 10] % mod) % mod;

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string s;
        ll m;
        cin >> s >> m;

        cout << solve(s, m, dp) << '\n';
    }
    return 0;
}