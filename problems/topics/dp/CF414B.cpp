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

ll solve(int n, int k) {
    unordered_map<int, vector<int>> map;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i)
            map[j].push_back(i);

    int mod = 1e9 + 7;
    vector<vector<ll>> dp(k + 1, vector<ll>(n + 1, 0));
    for (int i = 1; i <= n; i++)
        dp[1][i] = 1;

    for (int i = 2; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            for (auto o: map[j])
                dp[i][j] += dp[i - 1][o] % mod;
        }
    }

#ifndef ONLINE_JUDGE
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
#endif

    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += dp[k][i] % mod;
    }

    return cnt % mod;
}

int main() {
    fastio();
    IN_OUT();

    int n, k;
    cin >> n >> k;

    cout << solve(n, k);

    return 0;
}