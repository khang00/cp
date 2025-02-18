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

ll solve(int n, int m, vector<Edge> &edges) {
    if (n == 1)
        return 0;

    if (m == 0)
        return -1;

    DSU dsu;
    for (int i = 1; i <= n; i++)
        dsu.make_set(i);

    ll cost = 0;
    vector<bool> isSubordinate(n + 1);

    std::sort(edges.begin(), edges.end());
//    for (auto edge: edges) {
//        cout << edge.u << " " << edge.v << " " << edge.weight << "\n";
//    }
    for (const auto &edge: edges) {
        if (dsu.find_set(edge.u) != dsu.find_set(edge.v) && !isSubordinate[edge.v]) {
            // cout << edge.u << " " << edge.v << " " << edge.weight << "\n";
            isSubordinate[edge.v] = true;
            cost += edge.weight;
            dsu.merge_set(edge.u, edge.v);
        }
    }

    auto cnt = 0;
    for (int i = 1; i <= n; i++)
        if (!isSubordinate[i]) {
            cnt += 1;
            if (cnt > 1)
                return -1;
        }

    return cost;
}

int main() {
    fastio();
    IN_OUT();

    int n;
    cin >> n;

    int tmp;
    for (auto i = 0; i < n; i++)
        cin >> tmp;

    int m;
    cin >> m;

    vector<Edge> edges;
    for (auto i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;

        edges.push_back({u, v, w});
    }

    cout << solve(n, m, edges) << "\n";

    return 0;
}