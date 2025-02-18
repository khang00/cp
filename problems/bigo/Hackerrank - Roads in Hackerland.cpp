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
        return weight < other.weight;
    }
};

ll maxPow = 0;
ll nodeCount[MAX];
ll ans[MAX];

void dfs(int n, vector<vector<pair<ll, ll>>> &graph, ll u, ll p, ll c) {
    nodeCount[u] = 1;
    for (auto const &v: graph[u]) {
        if (v.second == p)
            continue;
        dfs(n, graph, v.second, u, v.first);
        nodeCount[u] += nodeCount[v.second];
    }

    ans[c] += 1LL * nodeCount[u] * (n - nodeCount[u]);
    maxPow = max(maxPow, c);
}

void solve(int n, int m, vector<Edge> edges) {
    DSU dsu;
    for (int i = 0; i <= n; i++)
        dsu.make_set(i);

    vector<vector<pair<ll, ll>>> graph(n + 1);
    std::sort(edges.begin(), edges.end());
    for (const auto &edge: edges) {
        if (dsu.find_set(edge.u) != dsu.find_set(edge.v)) {
            graph[edge.u].emplace_back(edge.weight, edge.v);
            graph[edge.v].emplace_back(edge.weight, edge.u);
            dsu.merge_set(edge.u, edge.v);
        }
    }

    dfs(n, graph, 1, 0, 0);
    for (int i = 0; i <= maxPow; i++) {
        ans[i + 1] += ans[i] / 2;
        ans[i] = ans[i] % 2;
        if (ans[i + 1] > 0 && i == maxPow)
            maxPow += 1;
    }

    for (int i = maxPow; i >= 0; i--) {
        if (ans[i] == 0)
            cout << "0";
        else
            cout << "1";
    }
}

int main() {
    fastio();
    IN_OUT();

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (auto i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;

        edges[i] = {u, v, w};
    }
    solve(n, m, edges);

    return 0;
}