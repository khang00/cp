#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
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

int solve(int n, int q, vector<int> t) {
    unordered_map<int, int> map;
    for (int i = 0; i < q; i++)
        map[t[i]] += 1;

    int cnt = 0;
    for (auto it: map)
        if (it.second % 2 == 1)
            cnt++;

    return n - cnt;
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> t(q, 0);
    for (int i = 0; i < q; i++)
        cin >> t[i];

    cout << solve(n, q, t);

    return 0;
}