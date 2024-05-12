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

vector<ll> solve(int n, vector<ll> x) {
    vector<ll> a(n, 0);
    a[0] = 507;

    for (int i = 1; i < n; i++)
        a[i] = x[i - 1] + a[i - 1];

    return a;
}

int main() {
    fastio();
    IN_OUT();

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<ll> x(n, 0);
        for (int j = 0; j < n - 1; j++)
            cin >> x[j];

        auto a = solve(n, x);
        for (int j = 0; j < n; j++)
            cout << a[j] << ' ';
        cout << endl;
    }

    return 0;
}