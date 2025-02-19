#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define INF (ll) 1e18
#define MAX (int) 1e5 + 1
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

vector<pair<ll, ll>> findBridgesTarjan(ll n, vector<vector<ll>> &adj) {
    vector<pair<ll, ll>> bridges;

    vector<ll> level(n);
    vector<ll> low(n);
    function<void(ll, ll)> dfs = [&](ll u, ll p) {
        if (p == -1)
            level[u] = low[u] = 1;

        for (auto nxt: adj[u]) {
            if (level[nxt] == 0) {
                level[nxt] = low[nxt] = level[u] + 1;
                dfs(nxt, u);

                low[u] = min(low[u], low[nxt]);
                if (low[nxt] > level[u])
                    bridges.emplace_back(u, nxt);
            } else if (nxt != p)
                low[u] = min(low[u], level[nxt]);
        }
    };

    for (int i = 0; i < n; i++)
        if (level[i] == 0)
            dfs(i, -1);

    return bridges;
}

vector<pair<ll, ll>> findBridges(ll n, vector<vector<ll>> &adj) {
    // number of edges pass through u and its parent p
    vector<ll> dp(n);
    vector<ll> level(n);
    vector<pair<ll, ll>> bridges;

    function<void(ll, ll)> dfs = [&](ll u, ll p) {
        if (p == -1)
            level[u] = 1;

        dp[u] = 0;
        for (auto v: adj[u]) {
            if (level[v] == 0) { // edge to direct child
                level[v] = level[u] + 1;
                dfs(v, u);
                dp[u] += dp[v];
            } else if (level[v] < level[u]) { // edge upwards
                dp[u]++;
            } else { // edge downwards
                dp[u]--;
            }
        }

        dp[u]--; // minus edge connect to parent of u
        if (level[u] >= 1 && dp[u] == 0)
            bridges.emplace_back(p, u);
    };

    for (int i = 0; i < n; i++)
        if (level[i] == 0)
            dfs(i, -1);

    return bridges;
}

ll solve(ll n, ll m, vector<vector<ll>> &adj) {
    DSU dsu;
    vector<pair<ll, ll>> comp;
    for (int i = 0; i < n; i++)
        if (dsu.find_set(i) == i)
            comp.emplace_back(setSize[i], i);

    if (comp.size() >= 3)
        return 0;

    vector<bool> vis(n);
    vector<ll> sub(n);
    function<void(ll)> dfs = [&](ll v) {
        vis[v] = true;
        sub[v] = 1;
        for (auto u: adj[v]) {
            if (vis[u])
                continue;

            dfs(u);
            sub[v] += sub[u];
        }
    };
    dfs(0);

    auto bridges = findBridges(n, adj);
//    for (auto [u, v]: bridges)
//        cout << u << " " << v << "\n";
    if (comp.size() == 2)
        return comp[0].first * comp[1].first * (m - bridges.size());

    ll sum = 0;
    for (auto pair: bridges)
        sum += sub[pair.second] * (n - sub[pair.second]) - 1;

    ll nonExistEdges = n * (n - 1) / 2 - m;
    return (m - bridges.size()) * nonExistEdges + sum;
}

int main() {
    fastio();
    IN_OUT();

    ll n, m;
    cin >> n >> m;

    DSU dsu;
    for (int i = 0; i < n; i++)
        dsu.make_set(i);

    vector<vector<ll>> adj(n);
    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        --u;
        --v;

        dsu.merge_set(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << solve(n, m, adj);
    return 0;
}