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

ll solve(int n, int m, int a, int b) {
    if (n > m) {
        return min(min(a * n, b * (int) floor(n / m) + (n % m) * a), b * (int) ceil((float) n / (float) m));
    } else {
        return min(b, a * n);
    }
}

int main() {
    fastio();
    IN_OUT();

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    cout << solve(n, m, a, b);

    return 0;
}