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

ll solve(int n) {
    auto arr = pow_bin_arr(n);
    ll big = arr[n], small = 0;
    for (int i = 0; i < (n - 1) / 2; i++)
        big += arr[i + 1];

    for (int i = (n - 1) / 2; i < n - 1; i++)
        small += arr[i + 1];

    return abs(big - small);
}

int main() {
    fastio();
    IN_OUT();
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        cout << solve(n) << endl;
    }

    return 0;
}