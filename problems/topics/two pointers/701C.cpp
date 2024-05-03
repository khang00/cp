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

ll solve(ll n, string s) {
    unordered_set<ll> set;
    for (int i = 0; i < n; i++)
        set.insert(s[i]);
    ll t = set.size();

    unordered_map<ll, ll> map;
    ll min_len = INF;
    ll l = 0, r = 0;
    while (n > l) {
        while (n > r && map.size() < t) {
            map[s[r]] += 1;
            r += 1;
        }

        if (map.size() == t)
            min_len = min(min_len, r - l);

        map[s[l]] -= 1;
        if (map[s[l]] == 0)
            map.erase(s[l]);

        l += 1;
    }

    return min_len;
}

int main() {
    fastio();
    IN_OUT();
    int n;
    cin >> n;

    string s;
    cin >> s;

    cout << solve(n, s);

    return 0;
}