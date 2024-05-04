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

vector<long long> pow_bin_arr(long long exp) {
    vector<long long> pows(exp + 1, 1);
    pows[0] = 1;

    for (int i = 1; i <= exp; i++) {
        pows[i] = pows[i - 1] * 2;
    }

    return pows;
}

ll solve(ll n, vector<ll> a) {
    sort(a.begin(), a.end());

    ll cost = 0;
    ll median = a[midpoint(0ll, n)];
    for (ll i = 0; i < n; i++) {
        cost += abs(median - a[i]);
    }

    return cost;
}

int main() {
    fastio();
    IN_OUT();

    ll n;
    cin >> n;

    vector<ll> a(n, 0);
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    cout << solve(n, a);

    return 0;
}