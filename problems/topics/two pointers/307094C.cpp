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

ll solve(ll n, ll d, vector<ll> a) {
    ll cnt = 0;
    int l = 0, r = 1;
    while (n > r) {
        while (a[r] - a[l] > d)
            l += 1;

        if (r != l)
            cnt += r - l;
        r += 1;
    }

    return (n * (n - 1) / 2) - cnt;
}

int main() {
    fastio();
    IN_OUT();

    int n;
    ll r;
    cin >> n >> r;

    vector<ll> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << solve(n, r, a);

    return 0;
}