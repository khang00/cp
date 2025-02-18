#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define INF (ll) 1e18
#define MAX (int) 1e6
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

auto solve(int n, vector<ll> a) {
    vector<bool> b(n, false);
    for (int i = 0; i < n - 1; i++) {
        auto num = abs(a[i] - a[i + 1]);
        if (num > b.size() || num <= 0)
            return "Not jolly";

        b[num] = true;
    }

    for (int i = 1; i < n; i++)
        if (!b[i])
            return "Not jolly";

    return "Jolly";
}

int main() {
    fastio();
    IN_OUT();

    int n;
    while (cin >> n) {
        vector<ll> a(n);
        for (auto i = 0; i < n; i++)
            cin >> a[i];

        cout << solve(n, a) << "\n";
    }

    return 0;
}