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

ll solve(int n, ll s, vector<ll> a) {
    vector<ll> p(n, a[0]);
    for (int i = 1; i < n; i++)
        p[i] = p[i - 1] + a[i];

    ll sum_len = 0;
    int l = 0, r = 0;
    while (n > r) {
        while (p[r] - p[l] + a[l] > s)
            l += 1;

        ll len = r - l + 1;
        if (r >= l)
            sum_len += len * (len + 1) / 2;
        r += 1;
    }

    return sum_len;
}

int main() {
    fastio();
    IN_OUT();

    int n;
    ll s;
    cin >> n >> s;

    vector<ll> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << solve(n, s, a);

    return 0;
}