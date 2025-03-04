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

vector<ll> solve(ll n) {
    vector<ll> a(n * n, 0);
    for (int i = 0; i < (n * n); i++) {
        auto val = (1 + 2 * i) % (n * n);
        if (n * n % 2 == 0)
            val = (1 + 2 * i) % (n * n + 1);

        if (val == 0)
            val = n * n;

        a[i] = val;
    }

    return a;
}

int main() {
    fastio();
    IN_OUT();

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        ll n;
        cin >> n;

        if (n == 2) {
            cout << -1 << "\n";
            continue;
        }

        auto ans = solve(n);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++)
                cout << ans[j * n + k] << " ";
            cout << "\n";
        }
    }

    return 0;
}