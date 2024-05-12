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

pair<string, string> solve(int n, vector<ll> a, vector<ll> b) {
    string c(n, '0'), d(n, '0');
    int k = n / 2;
    for (int i = 0; i < k; i++) {
        c[i] = '1';
        d[i] = '1';
    }

    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        if (a[l] < b[r]) {
            c[l] = '1';
            l += 1;
        } else {
            d[r] = '1';
            r += 1;
        }
    }

    return {c, d};
}

int main() {
    fastio();
    IN_OUT();

    int n;
    cin >> n;

    vector<ll> a(n, 0);
    vector<ll> b(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    auto ans = solve(n, a, b);
    cout << ans.first << endl << ans.second;

    return 0;
}