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

pair<ll, vector<ll>> solve(int n, vector<ll> a) {
    sort(a.begin(), a.end());

    vector<ll> b(n, a[n - 1]);
    int bi = 1;
    int r = n - 2, l = n / 2 - 1;
    while (l >= 0) {
        if (a[l] == a[r]) {
            b[bi] = a[l];
            bi += 1;
        } else {
            b[bi] = a[l];
            b[bi + 1] = a[r];
            bi += 2;
        }

        r -= 1;
        l -= 1;
    }

    if (bi < n) {
        b[bi] = a[r];
    }

    ll cnt = 0;
    for (int i = 0; i < n - 2; i++) {
        if (b[i] > b[i + 1] && b[i + 1] < b[i + 2])
            cnt += 1;
    }

    return pair(cnt, b);
}

int main() {
    fastio();
    IN_OUT();

    int n;
    cin >> n;

    vector<ll> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    auto [c, b] = solve(n, a);
    cout << c << endl;
    for (auto it: b)
        cout << it << ' ';

    return 0;
}