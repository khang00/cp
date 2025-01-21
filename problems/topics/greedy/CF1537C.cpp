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

vector<ll> solve(int n, vector<ll> &h) {
    sort(h.begin(), h.end());
    if (n <= 2)
        return h;

    auto min_diff_index = 0;
    auto min_diff = INF;
    for (auto i = 1; i < n; i++) {
        if (h[i] - h[i - 1] < min_diff) {
            min_diff = h[i] - h[i - 1];
            min_diff_index = i;
        }
    }

    vector<ll> b(h.begin() + min_diff_index, h.end());
    b.insert(b.end(), h.begin(), h.begin() + min_diff_index);
    return b;
}

int main() {
    fastio();
    IN_OUT();

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<ll> h(n, 0);
        for (int j = 0; j < n; j++) {
            cin >> h[j];
        }

        for (auto it: solve(n, h))
            cout << it << " ";
        cout << "\n";
    }

    return 0;
}