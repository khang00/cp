#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define INF (ll) 1e18
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

struct HASH {
    size_t operator()(const pair<int, int> &x) const {
        return hash<long long>()(((long long) x.first) ^ (((long long) x.second) << 32));
    }
};

ll solve(int n, vector<int> a) {
    unordered_map<pair<ll, ll>, ll, HASH> table;

    for (auto i = 0; i < n; i++) {
        auto min_ = min(a[i], i);
        table[pair(a[i] - min_, i - min_)]++;
    }

    ll cnt = 0;
    for (auto it : table) {
        cnt += (it.second * (it.second - 1)) / 2;
    }

    return cnt;
}

int main() {
    fastio();
    IN_OUT();

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> a(n, 0);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }

        cout << solve(n, a) << "\n";
    }

    return 0;
}