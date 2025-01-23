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

ll convertToNode(ll row, ll col, int m) {
    return (m * row) + col;
}

vector<vector<ll>> solve(int n, vector<pair<ll, ll>> edges) {
    for (int i = 0; i < n; i++)
        make_set(i);

    vector<pair<ll, ll>> redundantEdges;
    for (const auto &edge: edges) {
        auto u = edge.first;
        auto v = edge.second;
        if (find_set(u) == find_set(v)) {
            redundantEdges.emplace_back(u, v);
        } else {
            merge_set(find_set(u), find_set(v));
        }
    }

    unordered_set<ll> existed;
    vector<ll> components;
    for (int i = 0; i < n; i++) {
        auto set = find_set(i);
        if (existed.find(set) == existed.end()) {
            existed.insert(set);
            components.push_back(set);
        }
    }

    vector<vector<ll>> ans;
    for (int i = 0; i < redundantEdges.size(); i++) {
        ans.push_back({redundantEdges[i].first + 1,
                       redundantEdges[i].second + 1,
                       components[i] + 1,
                       components[i + 1] + 1});
    }

    return ans;
}

int main() {
    fastio();
    IN_OUT();

    int n;
    cin >> n;

    vector<pair<ll, ll>> edges(n - 1);
    for (int i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        edges[i] = {u - 1, v - 1};
    }

    auto ans = solve(n, edges);
    cout << ans.size() << "\n";
    for (const auto &replace: ans) {
        cout << replace[0] << " " << replace[1] << " " << replace[2] << " " << replace[3] << "\n";
    }
    return 0;
}