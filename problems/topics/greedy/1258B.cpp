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

string solve(int n, vector<ll> a) {
    ll sum = 0;
    for (auto it: a)
        sum += it;

    ll all_max = 0;
    ll curr_max = 0;
    for (int i = 0; i < n - 1; i++) {
        curr_max = max(curr_max + a[i], a[i]);
        all_max = max(all_max, curr_max);
    }

    curr_max = 0;
    for (int i = 1; i < n; i++) {
        curr_max = max(curr_max + a[i], a[i]);
        all_max = max(all_max, curr_max);
    }

    if (sum > all_max)
        return "YES";
    else
        return "NO";
}

int main() {
    fastio();
    IN_OUT();

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<ll> a(n, 0);
        for (int j = 0; j < n; j++)
            cin >> a[j];

        cout << solve(n, a) << endl;
    }

    return 0;
}