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

string solve(string &a) {
    ll n = a.size();
    int o = n, e = n;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0)
            e = min(e, i);
        else
            o = min(o, i);
    }

    string b = string(n, '-');
    for (int i = 0; i < n; i++) {
        int O = a[o] - '0';
        int E = a[e] - '0';
        if ((O <= E && o < n) || e >= n) {
            b[i] = a[o];

            o++;
            while (o < n && (a[o] - '0') % 2 != 1)
                o++;
        } else {
            b[i] = a[e];

            e++;
            while (e < n && (a[e] - '0') % 2 == 1)
                e++;
        }
    }

    return b;
}

int main() {
    fastio();
    IN_OUT();
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string a;
        cin >> a;

        cout << solve(a) << endl;
    }

    return 0;
}