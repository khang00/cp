#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define INF (ll) 1e18
#define MAX (int) 1e6
#define ll long long
#define ul unsigned long
#define ld long double
#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);                                                              \
  cout << fixed << std::setprecision(10)

void IN_OUT() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

int grayCode(int n) {
    return n ^ (n >> 1);
}

void solve(int N) {
    int n = pow(2, N);

    for (int i = 0; i < n; i++) {
        auto a = grayCode(i);
        for (int j = 0; j < N; j++)
            cout << ((a >> j) & 1);

        cout << "\n";
    }
}

int main() {
    fastio();
    IN_OUT();

    int n;
    cin >> n;

    solve(n);

    return 0;
}