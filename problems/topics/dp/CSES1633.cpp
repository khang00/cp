#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define INF 1e18
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

ll solve(ll n) {
    ll mod = 1e9 + 7;

    vector<ll> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (1 <= i && i <= 6)
            dp[i] = 1;

        for (int j = 1; j <= 6; j++) {
            if (i - j > 0)
                dp[i] += (dp[i - j] % mod);
        }
    }

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