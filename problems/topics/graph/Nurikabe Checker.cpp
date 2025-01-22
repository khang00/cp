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

string solve(vector<vector<ll>> graph, int n, int m) {
    vector<pair<int, int>> directions{
            {0,  1},
            {0,  -1},
            {1,  0},
            {-1, 0},
    };

    vector<vector<pair<int, int>>> sides = {
            {
                    {-1, -1},
                    {0,  -1},
                    {-1, 0},
            },
            {
                    {1,  1},
                    {0,  1},
                    {1,  0},
            },
            {
                    {-1, 1},
                    {-1, 0},
                    {0,  1},
            },
            {
                    {1,  -1},
                    {0,  -1},
                    {1,  0},
            }
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // cout << " a: " << i << " " << j << " " << convertToNode(i, j, m);
            make_set(convertToNode(i, j, m));
        }
        //cout << "\n";
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            auto currNode = convertToNode(i, j, m);
            for (auto [dx, dy]: directions) {
                auto x = i + dx;
                auto y = j + dy;
                if (!(0 <= x && x < n && 0 <= y && y < m))
                    continue;

                if ((graph[i][j] == graph[x][y] && graph[i][j] == -1) ||
                    (graph[i][j] >= 0 && graph[x][y] >= 0))
                    merge_set(currNode, convertToNode(x, y, m));
            }
        }
    }

    ll blackSet = -1;
    vector<ll> numCheck(MAX, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            auto currSet = find_set(convertToNode(i, j, m));
            if (graph[i][j] == 0 && numCheck[currSet] == -1)
                numCheck[currSet] = 0;

            if (graph[i][j] > 0) {
                if (numCheck[currSet] == -1)
                    numCheck[currSet] = 0;
                numCheck[currSet] += 1;
            }

            if (graph[i][j] > 0 && set_size[currSet] != graph[i][j])
                return "Incorrect";

            if (graph[i][j] == -1 && blackSet != -1 && blackSet != currSet)
                return "Incorrect";

            if (graph[i][j] == -1) {
                blackSet = currSet;

                for (const auto &side: sides) {
                    auto allBlack = true;
                    for (const auto [dx, dy]: side) {
                        auto x = i + dx;
                        auto y = j + dy;
                        if (!(0 <= x && x < n && 0 <= y && y < m)) {
                            allBlack = false;
                            break;
                        }

                        allBlack &= (graph[x][y] == graph[i][j]);
                    }

                    if (allBlack)
                        return "Incorrect";
                }
            }
        }
    }

    for (auto val: numCheck) {
        if (val == -1)
            continue;

        if (val != 1)
            return "Incorrect";
    }

    return "Correct";
}

int main() {
    fastio();
    IN_OUT();

    int t;
    cin >> t;

    for (int q = 0; q < t; q++) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<vector<ll>> graph(n, vector<ll>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char cell;
                cin >> cell;

                if (cell == '#')
                    graph[i][j] = -1;
            }
        }

        for (int i = 0; i < k; i++) {
            ll r, c, v;
            cin >> r >> c >> v;

            graph[r - 1][c - 1] = v;
        }

        cout << "Puzzle #" << q + 1 << ": " << solve(graph, n, m) << "\n";
    }
    return 0;
}