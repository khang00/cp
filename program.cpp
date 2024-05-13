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
    sort(a.begin(), a.end());
    ll sum_ = 0;
    for (int i = 0; i < n - 1; i++)
        sum_ += a[i];

    if (a[n - 1] > sum_)
        return a[n - 1] * 2;
    else
        return sum_ + a[n - 1];
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