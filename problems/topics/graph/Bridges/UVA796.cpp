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

vector<pair<ll, ll>> solve(ll n, vector<vector<ll>> &adj) {
    if (n == 0)
        return {};

    vector<ll> parents(n, -1);
    vector<vector<bool>> spanEdges(n, vector<bool>(n));
    vector<ll> dp(n, 0);
    vector<bool> vis(n);

    function<void(ll, ll)> dfs = [&](ll u, ll p) {
        parents[u] = p;

        vis[u] = true;
        for (auto v: adj[u])
            if (vis[v] && not spanEdges[u][v])
                dp[u] += 2;

        for (auto v: adj[u]) {
            if (vis[v])
                continue;

            spanEdges[u][v] = true;
            spanEdges[v][u] = true;
            dfs(v, u);
            dp[u] += dp[v];
        }

        for (auto v: adj[u])
            if (not spanEdges[u][v])
                dp[u] -= 1;
    };

    for (int i = 0; i < n; i++)
        if (not vis[i])
            dfs(i, -1);

    vector<pair<ll, ll>> bridges;
    for (ll i = 0; i < n; i++) {
        if (parents[i] != -1 && dp[i] == 0)
            bridges.emplace_back(min(i, parents[i]), max(i, parents[i]));
    }
    std::sort(bridges.begin(), bridges.end());
    return bridges;
}

int main() {
    fastio();
    IN_OUT();

    ll n;
    while (cin >> n) {
        vector<vector<ll>> adj(n);
        for (int i = 0; i < n; i++) {
            ll u;
            cin >> u;

            int m;
            char b;
            cin >> b >> m >> b;

            for (int j = 0; j < m; j++) {
                ll v;
                cin >> v;

                adj[u].push_back(v);
            }
        }

        auto ans = solve(n, adj);
        cout << ans.size() << " critical links\n";
        for (auto [x, y]: ans)
            cout << x << " - " << y << "\n";
        cout << "\n";
    }

    return 0;
}
