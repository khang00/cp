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

long long bin_pow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

struct Edge {
    ll w = INF, to = -1;
};

vector<ll> solve(int n, ll r, vector<pair<ll, ll>> coordinates) {
    for (int i = 0; i < n; i++)
        make_set(i);

    ll r_sqr = bin_pow(r, 2);
    vector<vector<ll>> adj(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll w = bin_pow(coordinates[i].first - coordinates[j].first, 2) +
                   bin_pow(coordinates[i].second - coordinates[j].second, 2);

            // cout << coordinates[i].first << " " << coordinates[i].second << " " << w << " " << r_sqr << "\n";
            adj[i][j] = w;
            adj[j][i] = w;
        }
    }

    ll states = 1;
    ld totalCostRails = 0;
    ld totalCostRoads = 0;

    vector<bool> selected(n, false);
    vector<Edge> min_e(n);
    min_e[0].w = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w))
                v = j;
        }

        selected[v] = true;
        if (min_e[v].w > r_sqr) {
            states += 1;
            totalCostRails += sqrt(min_e[v].w);
        } else {
            totalCostRoads += sqrt(min_e[v].w);
        }

        for (int to = 0; to < n; ++to) {
            if (adj[v][to] < min_e[to].w)
                min_e[to] = {adj[v][to], v};
        }
    }

    return {states, (ll) round(totalCostRoads), (ll) round(totalCostRails)};
//    std::sort(edges.begin(), edges.end());
//    for (const auto &edge: edges) {
//        if (edgeCounts == n - 1)
//            break;
//
//        auto w = get<0>(edge);
//        auto u = get<1>(edge);
//        auto v = get<2>(edge);
//
//        if (find_set(u) != find_set(v)) {
//            if (w > r_sqr) {
//                states += 1;
//                totalCostRails += sqrt(w);
//            } else {
//                totalCostRoads += sqrt(w);
//            }
//            edgeCounts += 1;
//            merge_set(u, v);
//        }
//    }
}

int main() {
    fastio();
    IN_OUT();

    int t;
    cin >> t;

    for (int q = 0; q < t; q++) {
        int n, r;
        cin >> n >> r;

        vector<pair<ll, ll>> coordinates(n);
        for (int i = 0; i < n; i++) {
            ll x, y;
            cin >> x >> y;

            coordinates[i] = {x, y};
        }

        auto ans = solve(n, r, coordinates);
        cout << "Case #" << q + 1 << ": " << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
    }

    return 0;
}