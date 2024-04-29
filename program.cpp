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

bool check(int n, int k, const vector<ll> &a, const vector<ll> &p, ll x) {
    ll min_ = a[0] - x;
    ll d = x;
    for (int i = n - 1; i >= 0; i--) {
        d += a[i] - min_;
        ll sum_ = p[n - 1] - d;
        if (sum_ <= k)
            return true;
    }

    return false;
}

ll solve(int n, ll k, vector<ll> a) {
    sort(a.begin(), a.end());

    vector<ll> p(n, 0);
    p[0] = a[0];
    for (int i = 1; i < n; i++)
        p[i] = p[i - 1] + a[i];

    ll min_step = 1e12;
    for (int y = n; y > 0; y--) {
        ll l = -1, r = 1e12;
        while (r - l > 1) {
            ll x = midpoint(l, r);
            ll sum_ = (p[y - 1] - p[0] + a[0]) + (a[0] - x) * (n - y) - x;
            if (sum_ > k)
                l = x;
            else
                r = x;
        }

        min_step = min(min_step, r + (n - y));
    }

    return min_step;
}

int main() {
    fastio();
    IN_OUT();

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        ll k;
        cin >> n >> k;

        vector<ll> a(n, 0);
        for (int j = 0; j < n; j++)
            cin >> a[j];

        cout << solve(n, k, a) << endl;
    }

    return 0;
}
