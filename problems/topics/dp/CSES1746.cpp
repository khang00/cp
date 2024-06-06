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
  cout.tie(NULL)

void IN_OUT() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

ll count(int i, int m, const vector<ll> &a) {
    if (i == 0)
        return m;

    return 3;
}

ll solve(int n, int m, vector<int> a) {
    ll mod = 1e9 + 7;

    vector<vector<ll>> dp(n, vector<ll>(m + 1, 0));
    if (a[0] == 0)
        for (int j = 1; j <= m; j++)
            dp[0][j] = 1;
    else
        dp[0][a[0]] = 1;

    for (int i = 1; i < n; i++)
        if (a[i] != 0)
            for (int o = max(1, a[i] - 1); o <= min(a[i] + 1, m); o++)
                dp[i][a[i]] += (dp[i - 1][o] % mod);
        else
            for (int j = 1; j <= m; j++)
                for (int o = max(1, j - 1); o <= min(j + 1, m); o++)
                    dp[i][j] += (dp[i - 1][o] % mod);


#ifndef ONLINE_JUDGE
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++)
            cout << dp[i][j] << ' ';
        cout << endl;
    }
#endif
    ll cnt = 0;
    for (int i = 1; i <= m; i++)
        cnt += (dp[n - 1][i] % mod);

    return cnt % mod;
}

int main() {
    fastio();
    IN_OUT();

    int n, m;
    cin >> n >> m;

    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << solve(n, m, a);
    return 0;
}