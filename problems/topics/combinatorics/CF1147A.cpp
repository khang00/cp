#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define INF 1e18
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

ll solve(int n, int k, vector<ll> a) {
    unordered_map<ll, pair<int, int>> map;
    for (int i = 0; i < k; i++)
        map[a[i]] = pair(-1, i);

    for (int i = k - 1; i >= 0; i--)
        map[a[i]].first = i;

    ll p = 0;
    for (int i = 2; i <= n; i++) {
        if (map.contains(i) && map.contains(i - 1)) {
            if (map[i].first <= map[i - 1].second)
                p += 1;

            if (map[i - 1].first <= map[i].second)
                p += 1;
        }
    }

    return n + 2 * (n - 1) - map.size() - p;
}

int main() {
    fastio();
    IN_OUT();

    int n, k;
    cin >> n >> k;

    vector<ll> a(k);
    for (int i = 0; i < k; i++)
        cin >> a[i];

    cout << solve(n, k, a);

    return 0;
}