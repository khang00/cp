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

ll solve(int n, ll k, vector<ll> a) {
    ll cnt = 0;
    map<ll, int> map;

    int l = 0, r = 0;
    while (n > r) {
        map[a[r]] += 1;
        while (map.rbegin()->first - map.begin()->first > k) {
            map[a[l]] -= 1;
            if (map[a[l]] == 0)
                map.erase(a[l]);
            l += 1;
        }

        cnt += r - l + 1;
        r += 1;
    }

    return cnt;
}

int main() {
    fastio();
    IN_OUT();

    int n;
    ll k;
    cin >> n >> k;

    vector<ll> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << solve(n, k, a);

    return 0;
}