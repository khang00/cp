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

vector<pair<int, int>> solve(int n) {
    vector<pair<int, int>> a;
    a.emplace_back(1, 1);
    if (n == 1)
        return a;

    a.emplace_back(2, 1);
    if (n == 2)
        return a;

    int cell_cnt = 2;
    for (int i = 0; i < n - 2; i++) {
        if (n - i * 2 < 1)
            break;

        a.emplace_back(n, n - i * 2);
        cell_cnt += 1;
    }

    if (cell_cnt < n) {
        int x = 0;
        while (cell_cnt < n) {
            a.emplace_back(5 + x, 1);
            cell_cnt += 1;
            x += 2;
        }
    }

    return a;
}

int main() {
    fastio();
    IN_OUT();

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        auto ans = solve(n);
        for (auto it: ans)
            cout << it.first << ' ' << it.second << endl;
        cout << endl;
    }

    return 0;
}