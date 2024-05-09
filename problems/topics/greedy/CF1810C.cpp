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

ll solve(int n, ll c, ll d, vector<ll> a) {
    sort(a.begin(), a.end());

    set<ll> set;
    ll cost = 0;
    for (int i = 0; i < n; i++) {
        if (set.contains(a[i]))
            cost += c;
        else
            set.insert(a[i]);
    }

    vector<ll> b(set.size() + 1, 0);
    int m = 0;
    for (auto it: set)
        b[++m] = it;

    ll min_cost = INF;
    for (int i = 1; i <= m; i++) {
        ll curr_cost = (m - i) * c + (b[i] - i) * d;
        min_cost = min(min_cost, curr_cost);
    }
    min_cost = min(min_cost, m * c + d);

    return cost + min_cost;
}

int main() {
    fastio();
    IN_OUT();

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        ll c, d;
        cin >> n >> c >> d;

        vector<ll> a(n, 0);
        for (int j = 0; j < n; j++)
            cin >> a[j];

        cout << solve(n, c, d, a) << endl;
    }

    return 0;
}