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

ll solve(int n, int k, vector<pair<ll, ll>> a) {
    sort(a.begin(), a.end());

    ll cnt = 0;
    multiset<ll> b;
    for (int i = 0; i < k; i++)
        b.insert(0);

    for (int i = 0; i < n; i++) {
        auto it = b.upper_bound(a[i].second);
        if (it == b.begin())
            continue;

        b.erase(--it);
        b.insert(a[i].first);
        cnt += 1;
    }

    return cnt;
}

int main() {
    fastio();
    IN_OUT();

    int n, k;
    cin >> n >> k;

    vector<pair<ll, ll>> a(n, {0, 0});
    for (int i = 0; i < n; i++)
        cin >> a[i].second >> a[i].first;

    cout << solve(n, k, a);

    return 0;
}