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

bool can(int n, pair<ll, ll> a, pair<ll, ll> b, ll x, const vector<ll> &px, const vector<ll> &py) {
    pair<ll, ll> d;
    ll cnt = x / n, rem = x % n;
    d.first = a.first + px[n] * 1ll * cnt + px[rem];
    d.second = a.second + py[n] * 1ll * cnt + py[rem];
    return abs(d.first - b.first) + abs(d.second - b.second) <= x;
}

ll solve(int n, const string &s, pair<ll, ll> a, pair<ll, ll> b) {
    vector<ll> px(n + 1, 0);
    vector<ll> py(n + 1, 0);

    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};
    auto dirs = "UDLR";
    for (int i = 0; i < n; i++) {
        int idx = -1;
        for (int j = 0; j < 4; j++)
            if (dirs[j] == s[i])
                idx = j;

        px[i + 1] = px[i] + dx[idx];
        py[i + 1] = py[i] + dy[idx];
    }

    ll l = -1, r = INF;
    while (r - l > 1) {
        ll x = midpoint(l, r);
        if (!can(n, a, b, x, px, py))
            l = x;
        else
            r = x;
    }

    if (r == INF)
        return -1;

    return r;
}

int main() {
    fastio();
    IN_OUT();

    pair<ll, ll> a;
    pair<ll, ll> b;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;

    int n;
    cin >> n;

    string s;
    cin >> s;

    cout << solve(n, s, a, b);

    return 0;
}
