#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define INF 1e18
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

ll solve(ll n, ll t, vector<ll> a) {
    vector<ll> p(n, a[0]);
    for (int i = 0; i < n; i++)
        p[i] = p[i - 1] + a[i];

    ll max_len = 0;
    ll l = 0, r = 0;
    while (n > r) {
        while (p[r] - p[l] + a[l] > t)
            l += 1;

        max_len = max(max_len, r - l + 1);
        r += 1;
    }

    return max_len;
}

int main() {
    fastio();
    IN_OUT();

    int n;
    ll t;
    cin >> n >> t;

    vector<ll> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << solve(n, t, a);

    return 0;
}