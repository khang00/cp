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

int solve(int n, int k, vector<int> a) {
    int cnt = 0;
    int empty = k;
    for (int i = 0; i < n; i++) {
        if (empty < a[i]) {
            cnt += 1;
            empty = k;
        }
        empty -= a[i];
    }

    if (empty < k)
        cnt += 1;

    return cnt;
}

int main() {
    fastio();
    IN_OUT();

    int n, k;
    cin >> n >> k;

    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << solve(n, k, a);


    return 0;
}