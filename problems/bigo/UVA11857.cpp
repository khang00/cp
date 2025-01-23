#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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

ll parent[MAX];
ll set_size[MAX];

void make_set(ll a) {
    parent[a] = a;
    set_size[a] = 1;
}

ll find_set(ll a) {
    if (parent[a] == a)
        return a;

    parent[a] = find_set(parent[a]);
    return parent[a];
}

void merge_set(ll a, ll b) {
    auto lt = find_set(a);
    auto gt = find_set(b);
    if (lt == gt)
        return;

    if (set_size[lt] > set_size[gt])
        swap(lt, gt);

    parent[lt] = gt;
    set_size[gt] += set_size[lt];
}

ll solve(int n, int m, vector<tuple<ll, ll, ll>> edges) {
    for (int i = 0; i < n; i++)
        make_set(i);

    ll maxCost = 0;
    ll treeEdges = 0;

    std::sort(edges.begin(), edges.end());
    for (const auto &edge: edges) {
        auto w = get<0>(edge);
        auto u = get<1>(edge);
        auto v = get<2>(edge);

        if (find_set(u) != find_set(v)) {
            treeEdges += 1;
            maxCost = max(maxCost, w);
            merge_set(u, v);
        }
    }

    if (treeEdges < n - 1)
        return -1;

    return maxCost;
}

int main() {
    fastio();
    IN_OUT();

    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0)
            return 0;

        vector<tuple<ll, ll, ll>> edges(m);

        for (int i = 0; i < m; i++) {
            ll u, v, w;
            cin >> u >> v >> w;

            edges[i] = {w, u, v};
        }

        ll ans = solve(n, m, edges);
        if (ans == -1)
            cout << "IMPOSSIBLE";
        else
            cout << ans << "\n";
    }

    return 0;
}