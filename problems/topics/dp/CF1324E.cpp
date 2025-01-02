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

int in( ll x, int l, int r) {
    return l <= x && x <= r;
}

ll solve(int n, int h, int l, int r, vector<ll> &a) {
    ll sum = 0;
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -1e9));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        for (int j = 0; j <= n; ++j) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + in((sum - j) % h, l, r));

            if (j < n)
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + in((sum - j - 1) % h, l, r));
        }
    }

#ifndef ONLINE_JUDGE
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
#endif

    return *max_element(dp[n].begin(), dp[n].end());
}

int main() {
    fastio();
    IN_OUT();

    int n, h, l, r;
    cin >> n >> h >> l >> r;

    vector<ll> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << solve(n, h, l, r, a);
    return 0;
}