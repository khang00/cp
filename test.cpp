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

ll solve(int n, vector<ll> a, vector<ll> b) {
    ll mod = 998244353;
    int m = 3000;
    vector<vector<ll>> dp(n, vector<ll>(m + 1, 0));
    for (int i = a[0]; i <= b[0]; i++)
        dp[0][i] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = a[i]; j <= b[i]; j++) {
            for (int o = a[i - 1]; o <= j; o++)
                dp[i][j] += dp[i - 1][o] % mod;
        }
    }

    ll cnt = 0;
    for (int j = a[n - 1]; j <= b[n - 1]; j++)
        cnt += dp[n - 1][j] % mod;

    return cnt % mod;
}

int main() {
    fastio();
    IN_OUT();

    int n;
    cin >> n;

    vector<ll> a(n, 0);
    vector<ll> b(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];


    cout << solve(n, a, b) << '\n';
    return 0;
}