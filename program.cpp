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

ll solve(int n, int k, vector<ll> a) {
    ll mod = (ll) 1e9 + 7;
    vector<vector<ll>> dp(n, vector<ll>(k + 1, 0));

    for (ll j = 0; j <= a[0]; j++)
        dp[0][j] = 1;
    for (ll i = 0; i < n; i++)
        dp[i][0] = 1;

    for (int i = 1; i < n; i++) {
        for (ll j = 1; j <= a[i]; j++) {
            for (ll o = 0; o <= j; o++)
                dp[i][j] += dp[i - 1][j - o];
        }
    }

#ifndef ONLINE_JUDGE
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
#endif

    return dp[n - 1][k];
}

int main() {
    fastio();
    IN_OUT();

    int n, k;
    cin >> n >> k;

    vector<ll> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << solve(n, k, a);
    return 0;
}