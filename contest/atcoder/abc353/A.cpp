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

int solve(int n, vector<ll> h) {
    for (int i = 0; i < n; i++) {
        if (h[i] > h[0])
            return i + 1;
    }

    return -1;
}

int main() {
    fastio();
    IN_OUT();

    int n;
    cin >> n;

    vector<ll> h(n, 0);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    cout << solve(n, h);


    return 0;
}