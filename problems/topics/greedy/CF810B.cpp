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

ll solve(int n, int f, vector<ll> k, vector<ll> l) {
    vector<pair<ll, int>> a(n, pair(-1, -1));
    for (int i = 0; i < n; i++) {
        a[i] = {min(l[i], k[i] * 2) - min(l[i], k[i]), i};
    }

    std::sort(a.begin(), a.end());

    ll sum_ = 0;
    for (int i = n - 1; i >= 0; i--) {
        int j = a[i].second;
        if (f > 0) {
            sum_ += min(l[j], k[j] * 2);
            f -= 1;
        } else {
            sum_ += min(l[j], k[j]);
        }
    }

    return sum_;
}

int main() {
    fastio();
    IN_OUT();

    int n, f;
    cin >> n >> f;

    vector<ll> k(n, 0);
    vector<ll> l(n, 0);
    for (int i = 0; i < n; i++)
        cin >> k[i] >> l[i];

    cout << solve(n, f, k, l);

    return 0;
}