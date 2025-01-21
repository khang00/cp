#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define INF (ll) 1e18
#define ll long long
#define ul unsigned long
#define ld long double
#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);                                                              \
  cout << fixed << std::setprecision(10)

void IN_OUT() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

ll solve(ll n, ll a, ll b, string s) {
    if (b > 0)
        return a * n + b * n;

    ll segments[2];
    segments[0] = 0;
    segments[1] = 0;

    auto pre = s[0];
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != pre) {
            segments[pre - '0']++;
        }

        pre = s[i];
    }
    segments[pre - '0']++;

    return a * n + b * (min(segments[0], segments[1]) + 1);
}

int main() {
    fastio();
    IN_OUT();

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        ll n, a, b;
        cin >> n >> a >> b;

        string s;
        cin >> s;

        cout << solve(n, a, b, s) << "\n";
    }

    return 0;
}