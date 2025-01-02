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

ll solve(int n, int k, const vector<ll> &a, vector<vector<ll>> &cache) {
    ll mod = (ll) 1e9 + 7;
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (ll j = 1; j <= a[i - 1]; j++) {
            for (ll o = 0; o <= a[i - 1]; o++)
                if (j - o >= 0)
                    dp[i][j] += dp[i - 1][j - o] % mod;
        }
    }

    return dp[n][k] % mod;
}

ll solve(int n, int k, const vector<ll> &a) {
    ll mod = (ll) 1e9 + 7;
    ll sum_ = 0;
    for (int i = 0; i < n; i++)
        sum_ += a[i];

    if (k > sum_)
        return 0;

    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        vector<ll> pre_sum(k + 2, 0);
        pre_sum[0] = dp[i][0];
        for (int j = 0; j <= k; j++)
            pre_sum[j + 1] = pre_sum[j] + dp[i][j];


        for (ll j = 0; j <= k; j++)
            dp[i + 1][j] = (pre_sum[j + 1] - pre_sum[j - min(j, a[i])]) % mod;
    }

#ifndef ONLINE_JUDGE
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
#endif

    return dp[n][k] % mod;
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