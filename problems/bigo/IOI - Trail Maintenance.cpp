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

struct Edge {
    ll w = INF, u = -1, v = -1;
};

pair<ll, ll> dfs(vector<vector<ll>> &adj, ll node, ll end) {
    int n = adj.size();

    ll max_w = -1;
    pair<ll, ll> max_pair = {-1, -1};

    vector<bool> vis(n, false);
    vis[node] = true;

    unordered_map<ll, ll> parent;
    stack<ll> stack;
    stack.push(node);
    while (!stack.empty()) {
        auto curr = stack.top();
        stack.pop();
        //cout << "pop: " << curr << "\n";
        if (curr == end) {
            while (parent.find(curr) != parent.end()) {
                auto anc = parent[curr];
                if (max_w < adj[anc][curr]) {
                    max_w = adj[anc][curr];
                    max_pair = {anc, curr};
                }
                curr = anc;
            }
            //cout << "bbbbb: " << max_pair.first << " " << max_pair.second << "\n";
            return max_pair;
        }

        for (int i = 0; i < n; i++) {
            if (adj[curr][i] == INF || vis[i])
                continue;

            parent[i] = curr;
            vis[i] = true;
            stack.push(i);
        }
    }

    return max_pair;
}

void solve(int n, int m, vector<Edge> &edges) {
    for (int i = 0; i < n; i++)
        make_set(i);

    vector<vector<ll>> adj(n, vector<ll>(n, INF));
    ll components = n;
    ll currWeight = 0;
    for (const auto &edge: edges) {
        auto u = edge.u;
        auto v = edge.v;
        auto w = edge.w;
        //cout << u << " " << v << "\n";
        if (find_set(u) != find_set(v)) {
            components -= 1;
            currWeight += w;
            adj[u][v] = w;
            adj[v][u] = w;
            merge_set(u, v);
        } else {
            auto [i, j] = dfs(adj, u, v);
            if (i == -1 && j == -1) {
//                for (int i = 0; i < n; i++) {
//                    for (int j = 0; j < n; j++) {
//                        cout << adj[i][j] << " ";
//                    }
//                    cout << "\n";
//                }
//                cout << "aaaa: " << i << " " << j << " " << u << " " << v;
                return;
            }
            if (adj[i][j] > w) {
                currWeight -= abs(adj[i][j] - w);

                adj[i][j] = INF;
                adj[j][i] = INF;
                adj[u][v] = w;
                adj[v][u] = w;
            }
        }

        if (components > 1)
            cout << "-1\n";
        else
            cout << currWeight << "\n";
    }
}

int main() {
    fastio();
    IN_OUT();


    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;

        edges[i] = {w, u - 1, v - 1};
    }

    solve(n, m, edges);
    return 0;
}