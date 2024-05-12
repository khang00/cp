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

ll solve(int x) {
    int max_y = 0;
    int max_gcd = 0;
    for (int y = 1; y < x; y++) {
        int curr_gcd = gcd(x, y) + y;
        if (curr_gcd > max_gcd) {
            max_y = y;
            max_gcd = curr_gcd;
        }
    }

    return max_y;
}

int main() {
    fastio();
    IN_OUT();

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int x;
        cin >> x;

        cout << solve(x) << endl;
    }

    return 0;
}