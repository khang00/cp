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

ll solve(int n, vector<ll> s) {
    vector<ll> dp(n + 1, 1);

    ll all_max = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + i; j <= n; j += i) {
            if (s[j - 1] > s[i - 1]) {
                dp[j] = max(dp[j], dp[i] + 1);
                all_max = max(all_max, dp[j]);
            }
        }
    }

    return all_max;
}

int main() {
    fastio();
    IN_OUT();

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<ll> s(n, 0);
        for (int j = 0; j < n; j++)
            cin >> s[j];

        cout << solve(n, s) << '\n';
    }

    return 0;
}