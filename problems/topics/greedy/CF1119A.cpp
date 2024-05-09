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
    ll left_dis = 0;
    for (int i = n - 1; i > 0; i--) {
        if (a[i] != a[0]) {
            left_dis = i;
            break;
        }
    }

    ll right_dis = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] != a[n - 1]) {
            right_dis = n - 1 - i;
            break;
        }
    }

    return max(left_dis, right_dis);
}

int main() {
    fastio();
    IN_OUT();

    int n;
    cin >> n;

    vector<ll> a(n, 0);
    for (int j = 0; j < n; j++)
        cin >> a[j];

    cout << solve(n, a);

    return 0;
}