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

ll solve(int n, vector<ll> a) {
    ll m = 1e8;
    vector<ll> p(n, a[0]);
    for (int i = 1; i < n; i++)
        p[i] = ((p[i - 1] % m) + (a[i] % m)) % m;

    ll sum = 0;
    for (int i = 0; i < n - 1; i++) {
        ll sum_j = p[n - 1] - p[i];
        ll curr_term = (a[i] * (n - i - 1)) % m + sum_j;
        sum += curr_term;
    }

    return sum + m;
}

int main() {
    fastio();
    IN_OUT();

    int n;
    cin >> n;

    vector<ll> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << solve(n, a);


    return 0;
}