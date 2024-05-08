#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define INF 1e18
#define ll long long
#define ul unsigned long
#define ld long double
#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

void IN_OUT() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

vector<int> solve(int n, int m, vector<int> a) {
    vector<int> ans(m, 0);
    unordered_map<int, int> map;
    for (int i = 0; i < m; i++) {
        map[a[i]] += 1;
        if (map.size() == n) {
            ans[i] = 1;
            for (int j = 1; j <= n; j++) {
                map[j] -= 1;
                if (map[j] == 0)
                    map.erase(j);
            }
        }
    }

    return ans;
}

int main() {
    fastio();
    IN_OUT();

    int n, m;
    cin >> n >> m;

    vector<int> a(m, 0);
    for (int j = 0; j < m; j++)
        cin >> a[j];

    auto ans = solve(n, m, a);
    for (auto c: ans)
        cout << c;

    return 0;
}