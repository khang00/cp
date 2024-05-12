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

ll solve(int n, int m, string a, string b) {
    int max_ = 0;

    int ai = 0;
    for (int i = 0; i < m; i++) {
        if (b[i] == a[ai]) {
            max_ = max(max_, ai + 1);
            ai += 1;
        }
    }

    return max_;
}

int main() {
    fastio();
    IN_OUT();

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;

        string a, b;
        cin >> a >> b;

        cout << solve(n, m, a, b) << endl;
    }

    return 0;
}