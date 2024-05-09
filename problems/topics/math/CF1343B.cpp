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

vector<ll> solve(ll n) {
    if (n <= 3 || ((n / 2) % 2 == 1)) {
        return {};
    }

    vector<ll> odd, even;
    for (int i = 1; i <= n / 2; i++) {
        if (i % 2 != 0) {
            odd.emplace_back(i);
            odd.emplace_back(n - (i - 1) + 1);
        } else {
            even.emplace_back(i);
            even.emplace_back(n - (i - 1) + 1);
        }
    }
    even.insert(even.end(), odd.begin(), odd.end());
    return even;
}

int main() {
    fastio();
    IN_OUT();

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        ll n;
        cin >> n;

        auto ans = solve(n);
        if (ans.empty())
            cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            for (auto it: ans)
                cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}