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

string solve(ll n, ll w, ll h) {
    ll cnt = 1;
    while (w % 2 == 0) {
        cnt *= 2;
        w /= 2;
    }

    while (h % 2 == 0) {
        cnt *= 2;
        h /= 2;
    }

    if (cnt >= n)
        return "YES";
    else
        return "NO";
}

int main() {
    fastio();
    IN_OUT();

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        ll n, w, h;
        cin >> w >> h >> n;

        cout << solve(n, w, h) << endl;
    }
    return 0;
}