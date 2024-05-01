#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define INF 1e18
#define ll long long
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

ll solve(int n, int m, vector<ll> a, vector<ll> b) {
    unordered_map<ll, ll> map;
    for (int i = 0; i < m; i++)
        map[b[i]] += 1;

    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        if (map.contains(a[i])) {
            cnt += map[a[i]];
        }
    }

    return cnt;
}

int main() {
    fastio();
    IN_OUT();

    int n, m;
    cin >> n >> m;

    vector<ll> a(n, 0), b(m, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
        cin >> b[i];

    cout << solve(n, m, a, b);

    return 0;
}