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

string solve(int n, ll k, string s) {
    char r = 'a';
    char l = 'a';
    char max_ = 'a';
    for (int i = 0; i < n; i++) {
        if (s[i] <= max_) {
            s[i] = 'a';
            continue;
        }

        if (k > 0) {
            auto diff = s[i] - max_;
            if (diff <= k) {
                max_ = max(max_, s[i]);
                s[i] = 'a';
                k -= diff;
            } else {
                r = s[i];
                s[i] -= k;
                l = s[i];
                k = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (l <= s[i] && s[i] <= r)
            s[i] = l;
    }

    return s;
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

        string s;
        cin >> s;

        cout << solve(n, k, s) << '\n';
    }


    return 0;
}