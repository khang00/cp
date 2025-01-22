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

class DSU {
public:
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
};

void solve(vector<tuple<ll, ll, ll, ll, ll>> edges, int nodeSize, int edgeSize, int q) {
    vector<ll> changedEdge;
    for (int i = 0; i < q; i++) {
        ll k, s;
        cin >> k >> s;

        k -= 1;
        for (int j = 0; j < s; j++) {
            ll t, c;
            cin >> t >> c;

            get<0>(edges[t - 1]) = c;
            changedEdge.push_back(t - 1);
        }

        tuple<ll, ll, ll, ll, ll> needEdge = edges[k];
        auto wk = get<0>(needEdge);
        auto uk = get<2>(needEdge);
        auto vk = get<3>(needEdge);

        DSU dsu;
        for (int j = 0; j < nodeSize; j++)
            dsu.make_set(j);

        for (auto &edge: edges) {
            auto u = get<2>(edge);
            auto v = get<3>(edge);
            auto w = get<0>(edge);

            if (dsu.find_set(u) != dsu.find_set(v) && w < wk)
                dsu.merge_set(u, v);
        }

        if (dsu.find_set(uk) == dsu.find_set(vk))
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";

        for (long long j: changedEdge)
            get<0>(edges[j]) = get<4>(edges[j]);
        changedEdge.clear();
    }
}

int main() {
    fastio();
    IN_OUT();

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m, q;
        cin >> n >> m >> q;

        vector<tuple<ll, ll, ll, ll, ll>> edges(m);
        for (int j = 0; j < m; j++) {
            ll u, v, w;
            cin >> u >> v >> w;

            edges[j] = make_tuple(w, j, u - 1, v - 1, w);
        }

        solve(edges, n, m, q);
    }
    return 0;
}