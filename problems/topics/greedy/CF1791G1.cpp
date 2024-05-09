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

ll solve(int n, ll c, vector<ll> a) {
    for (int i = 0; i < n; i++)
        a[i] += i + 1;

    sort(a.begin(), a.end());
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        if (c - a[i] < 0)
            return cnt;

        c -= a[i];
        cnt++;
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
        ll c;
        cin >> n >> c;

        vector<ll> a(n, 0);
        for (int j = 0; j < n; j++)
            cin >> a[j];

        cout << solve(n, c, a) << endl;
    }

    return 0;
}