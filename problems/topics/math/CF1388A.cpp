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

vector<ll> solve(int n) {
    set<ll> b = {36, 40, 44};

    if (n <= 30) {
        cout << "NO";
        return {};
    } else if (b.contains(n)) {
        cout << "YES" << endl;
        return {6, 10, 15, n - 31};
    } else if (n >= 31) {
        cout << "YES" << endl;
        return {6, 10, 14, n - 30};
    }
}

int main() {
    fastio();
    IN_OUT();

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        auto ans = solve(n);
        for (auto it: ans)
            cout << it << ' ';
        cout << endl;
    }


    return 0;
}