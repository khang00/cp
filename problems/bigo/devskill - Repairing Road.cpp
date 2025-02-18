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

ll parent[MAX];
ll setSize[MAX];

class DSU {
public:

    void make_set(ll a) {
        parent[a] = a;
        setSize[a] = 1;
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

        if (setSize[lt] > setSize[gt])
            swap(lt, gt);

        parent[lt] = gt;
        setSize[gt] += setSize[lt];
    }
};

struct Edge {
    ll u, v;
    ll weight;

    bool operator<(Edge const &other) {
        return weight > other.weight;
    }
};

pair<ll, ll> solve(int n, int m, vector<Edge> edges) {
    DSU dsu;
    for (int i = 0; i <= n; i++)
        dsu.make_set(i);

    ll compCount = 0;
    ll maxFit = 0;
    std::sort(edges.begin(), edges.end());
    for (const auto &edge: edges) {
        if (dsu.find_set(edge.u) != dsu.find_set(edge.v)) {
            compCount += 1;
            maxFit += edge.weight;
            dsu.merge_set(edge.u, edge.v);
        }
    }

    return make_pair(compCount, maxFit);
}

int main() {
    fastio();
    IN_OUT();

    int t;
    cin >> t;

    for (int q = 0; q < t; q++) {
        int n, m;
        cin >> n >> m;

        vector<Edge> edges(m);
        for (auto i = 0; i < m; i++) {
            ll u, v, w;
            cin >> u >> v >> w;

            edges[i] = {u, v, w};
        }
        auto [comp, maxFit] = solve(n, m, edges);

        cout << "Case " << q + 1 << ": " << comp << " " << maxFit << "\n";
    }

    return 0;
}