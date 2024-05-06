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

ll solve(int n, vector<ll> a) {
    multiset<ll> towers;
    towers.insert(a[0]);

    for (int i = 1; i < n; i++) {
        auto it = towers.lower_bound(a[i] + 1);
        if (it != towers.end())
            towers.erase(it);

        towers.insert(a[i]);
    }

    return (ll) towers.size();
}

int main() {
    fastio();
    IN_OUT();

    int n;
    cin >> n;

    vector<ll> a(n, 0);
    for (int j = 0; j < n; j++)
        cin >> a[j];

    cout << solve(n, a);

    return 0;
}