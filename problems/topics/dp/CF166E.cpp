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

ll solve(int n) {
    ll mod = 1e9 + 7;

    vector<ll> curr(4, 0);
    vector<ll> pre(4, 0);
    for (int j = 0; j < 4; j++)
        pre[j] = 1;
    pre[3] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            curr[j] = 0;
            for (int o = 0; o < 4; o++) {
                if (o != j)
                    curr[j] += pre[o] % mod;
            }
        }
        pre = curr;
    }

    return curr[3] % mod;
}

int main() {
    fastio();
    IN_OUT();

    int n;
    cin >> n;

    cout << solve(n) << '\n';
    return 0;
}